#include <TROOT.h>

// Struct should containt all subsystem h101 structures
typedef struct EXT_STR_h101_t
{   
    EXT_STR_h101_unpack_t eventheaders;
    EXT_STR_h101_v1751_onion_t fatima;
} EXT_STR_h101;


int FatimaV1751MakeTrees(TString inputfile, TString outputfile)
{   
    const Int_t nev = 1000000; const Int_t fRunId = 1; const Int_t fExpId = 1;

    TString ucesb_path = "/lustre/gamma/gbrunic/FatimaTest/c4Root/unpack/exps/onlyFatimaVme/onlyFatimaVme  --input-buffer=200Mi --event-sizes --allow-errors --data";

    // Set level of debug information
    FairLogger::GetLogger()->SetLogScreenLevel("INFO");
    FairLogger::GetLogger()->SetColoredLog(true);

    // Define where to read data from. Online = stream/trans server, Nearline = .lmd file.
    
    //TString filename = "/data.local1/lustre/despec/Scanner2024/lyso_0026_0001.lmd"; // timesorter.
    //TString filename = "/data.local1/lustre/despec/ScannerSummer/QDCPedestalCalibration/lyso_qdc_cal_0002_0001.lmd"; // timesorter.
    //TString filename = "/data.local1/lustre/despec/ScannerSummer/QDCPedestalCalibration/lyso_standalone_trigger_0001_000*.lmd";
    //TString filename = "/data.local1/lustre/despec/ScannerSummer/TraceScan2/scan_front_0006_0688.lmd";
    // TString filename = "stream://r4l-62";

    // Macro timing
    TString cRunId = Form("%04d", fRunId);
    TString cExpId = Form("%03d", fExpId);
    TStopwatch timer;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    timer.Start();
    
    // // Create Online run
    // Int_t refresh = 1; // Refresh rate for online histograms
    // Int_t port = 5010; // 

    FairRunOnline* run = new FairRunOnline();
    EventHeader* EvtHead = new EventHeader();
    run->SetEventHeader(EvtHead);
    run->SetRunId(1);
    run->SetSink(new FairRootFileSink(outputfile));
    // run->ActivateHttpServer(refresh, port);

    // TFolder* histograms = new TFolder("Histograms", "Histograms");
    // FairRootManager::Instance()->Register("Histograms", "Histogram Folder", histograms, false);
    // run->AddObject(histograms);


    // Create source using ucesb for input
    EXT_STR_h101 ucesb_struct;
    TString ntuple_options = "UNPACK"; // Define which level of data to unpack - we don't use "RAW" or "CAL"
    UcesbSource* source = new UcesbSource(inputfile, ntuple_options, ucesb_path, &ucesb_struct, sizeof(ucesb_struct));
    source->SetMaxEvents(nev);
    run->SetSource(source);


    FatimaV1751Configuration::SetDetectorMapFile("/lustre/gamma/gbrunic/FatimaTest/c4Root/config/fatima_test/Fatima_v1751_allocation.txt");
    FatimaV1751Configuration::Set_QDC_E_CalFile("/lustre/gamma/gbrunic/FatimaTest/c4Root/config/fatima_test/fatima_v1751_ecalib.txt");

    // ------------------------------------------------------------------------------------- //
    // *** Read Subsystems - comment out unwanted systems ********************************** //

    // EventHeader - should always be done
    UnpackReader* unpackheader = new UnpackReader((EXT_STR_h101_unpack*)&ucesb_struct.eventheaders, offsetof(EXT_STR_h101, eventheaders));
    
    source->AddReader(unpackheader);
    
    /*
    AgataTraceReader* unpack_traces = new AgataTraceReader((EXT_STR_h101_agata_onion*)&ucesb_struct.agata, offsetof(EXT_STR_h101, agata));
    unpack_traces->SetOnline(true);
    source->AddReader(unpack_traces);
    */
    
    v1751DpppsdReader* unpack_v1751 = new v1751DpppsdReader((EXT_STR_h101_v1751_onion*)&ucesb_struct.fatima, offsetof(EXT_STR_h101, fatima));
    unpack_v1751->SetOnline(false);
    unpack_v1751->SetControlOutput(true);
    unpack_v1751->SetMultiplicityOutput(1); // Change for different multiplicity counters
    source->AddReader(unpack_v1751);

    v1751DpppsdRaw2Cal* fatima_cal = new v1751DpppsdRaw2Cal();
    fatima_cal->SetOnline(false);
    run->AddTask(fatima_cal);

    /*
    LYSORaw2Cal* lyso_cal = new LYSORaw2Cal();
    lyso_cal->SetOnline(true);
    run->AddTask(lyso_cal);
    */
    
    
    /*
    TraceVisualizer* onlinege = new TraceVisualizer();
    onlinege->SetTraceLength(200);
    onlinege->SetPlotFrequency(200);
    run->AddTask(onlinege);
    */
    
    //LYSOOnline* lonline = new LYSOOnline();
    //run->AddTask(lonline);
    // TraceVisualizerv1751 * onlinev1751 = new TraceVisualizerv1751();
    // onlinev1751->SetPlotFrequency(50);
    // run->AddTask(onlinev1751);
    
    
    
    // Initialise
    run->Init();
    
    FairLogger::GetLogger()->SetLogScreenLevel("info");

    // Information about portnumber and main data stream
    // cout << "\n\n" << endl;
    // cout << "Data stream is: " << filename << endl;
    // cout << "Online port server: " << port << endl;
    // cout << "\n\n" << endl;

    // create sink object before run starts    
    FairSink* sf = FairRunOnline::Instance()->GetSink();

    // Run
    run->Run((nev < 0) ? nev : 0, (nev < 0) ? 0 : nev); 

    return 0;
}

