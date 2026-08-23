// Switch all tasks related to {subsystem type} on (1)/off (0)
#define FATIMA_TRACE10BIT_ON 0
#define FATIMA_TRACE8BIT_ON 1

#include <TROOT.h>

// Struct should containt all subsystem h101 structures
typedef struct EXT_STR_h101_t
{   
    EXT_STR_h101_unpack_t eventheaders;
    EXT_STR_h101_v1751_Trace10Bit_onion_t fatima_trace10bit;
    EXT_STR_h101_v1751_Trace8Bit_onion_t fatima_trace8bit;
} EXT_STR_h101;


int FatimaV1751MakeTrees(TString inputfile, TString outputfile)
{   
    if (FATIMA_TRACE10BIT_ON && FATIMA_TRACE8BIT_ON){
        printf("ERROR: Cannot have 10BIT Traces and 8BIT traces enabled simultaneously.");
        std::exit(1);
    }    

    if (!(FATIMA_TRACE10BIT_ON || FATIMA_TRACE8BIT_ON)){
        printf("ERROR: Must enable either 10BIT Traces or 8BIT traces.");
        std::exit(1);
    }    

    // const Int_t nev = -1; // Process all events
    const Int_t nev = 10000; // Process all events
    const Int_t fRunId = 1; 
    const Int_t fExpId = 1;

    TString ucesb_path;

    if (FATIMA_TRACE10BIT_ON){
        TString ucesb_path = "/lustre/gamma/gbrunic/FatimaTest/c4Root/unpack/exps/onlyFatimaTrace10Bit/onlyFatimaTrace10Bit --input-buffer=200Mi --allow-errors --debug";
    }

    if (FATIMA_TRACE8BIT_ON){
        TString ucesb_path = "/lustre/gamma/gbrunic/FatimaTest/c4Root/unpack/exps/onlyFatimaTrace8Bit/onlyFatimaTrace8Bit --input-buffer=200Mi --allow-errors --debug";
    }

    // Set level of debug information
    FairLogger::GetLogger()->SetLogScreenLevel("INFO");
    FairLogger::GetLogger()->SetColoredLog(true);


    // Macro timing
    TString cRunId = Form("%04d", fRunId);
    TString cExpId = Form("%03d", fExpId);
    TStopwatch timer;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    timer.Start();
    

    FairRunOnline* run = new FairRunOnline();
    EventHeader* EvtHead = new EventHeader();
    run->SetEventHeader(EvtHead);
    run->SetRunId(1);
    run->SetSink(new FairRootFileSink(outputfile));

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
    // FatimaV1751Configuration::Set_QDC_E_CalFile("/lustre/gamma/gbrunic/FatimaTest/c4Root/config/fatima_test/fatima_v1751_ecalib_single.txt");
    // FatimaV1751Configuration::Set_QDC_E_CalFile("/lustre/gamma/gbrunic/FatimaTest/c4Root/config/fatima_test/fatima_v1751_ecalib_double.txt");
    FatimaV1751Configuration::Set_QDC_E_CalFile("/lustre/gamma/gbrunic/FatimaTest/c4Root/config/fatima_test/152Eu_double_6ns_25frac_ecalib_params.txt");

    // ------------------------------------------------------------------------------------- //
    // *** Read Subsystems - comment out unwanted systems ********************************** //

    // EventHeader - should always be done
    UnpackReader* unpackheader = new UnpackReader((EXT_STR_h101_unpack*)&ucesb_struct.eventheaders, offsetof(EXT_STR_h101, eventheaders));
    source->AddReader(unpackheader);
    
    if (FATIMA_TRACE10BIT_ON){
        v1751DpppsdTrace10BitReader* unpack_v1751 = new v1751DpppsdTrace10BitReader((EXT_STR_h101_v1751_Trace10Bit_onion*)&ucesb_struct.fatima_trace10bit, offsetof(EXT_STR_h101, fatima_trace10bit));
        // unpack_v1751->SetOnline(false);
        unpack_v1751->SetOnline(true);
        unpack_v1751->SetControlOutput(true);
        unpack_v1751->SetMultiplicityOutput(1); // Change for different multiplicity counters
        source->AddReader(unpack_v1751);

        v1751DpppsdTrace10BitRaw2Cal* fatima_cal = new v1751DpppsdTrace10BitRaw2Cal();
        fatima_cal->SetOnline(false);
        run->AddTask(fatima_cal);
    } 

    if (FATIMA_TRACE8BIT_ON){
        v1751DpppsdTrace8BitReader* unpack_v1751 = new v1751DpppsdTrace8BitReader((EXT_STR_h101_v1751_Trace8Bit_onion*)&ucesb_struct.fatima_trace8bit, offsetof(EXT_STR_h101, fatima_trace8bit));
        // unpack_v1751->SetOnline(false);
        unpack_v1751->SetOnline(true);
        unpack_v1751->SetControlOutput(true);
        unpack_v1751->SetMultiplicityOutput(1); // Change for different multiplicity counters
        source->AddReader(unpack_v1751);

        v1751DpppsdTrace8BitRaw2Cal* fatima_cal = new v1751DpppsdTrace8BitRaw2Cal();
        fatima_cal->SetOnline(false);
        run->AddTask(fatima_cal);
    } 
    
    
    
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

