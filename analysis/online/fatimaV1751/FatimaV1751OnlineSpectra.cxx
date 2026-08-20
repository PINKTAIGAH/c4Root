/******************************************************************************
 *   Copyright (C) 2024 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2024 Members of HISPEC/DESPEC Collaboration                *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************
 *                          G. Bruni-Campanella                               *
 *                                20.08.26                                    *
 ******************************************************************************/

// FairRoot
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRunOnline.h"
#include "FairRuntimeDb.h"

// c4
#include "FatimaV1751OnlineSpectra.h"
#include "EventHeader.h"
#include "FatimaV1751Configuration.h"

#include "AnalysisTools.h"
#include "c4Logger.h"

#include "TCanvas.h"
#include "TClonesArray.h"
#include "THttpServer.h"
#include "TMath.h"
#include "TRandom.h"

FatimaV1751OnlineSpectra::FatimaV1751OnlineSpectra() 
    : FatimaV1751OnlineSpectra("FatimaV1751OnlineSpectra")
    {
        fatima_vme_config = FatimaV1751Configuration::GetInstance();
    }

FatimaV1751OnlineSpectra::FatimaV1751OnlineSpectra(const TString& name, Int_t verbose)
    :   FairTask(name, verbose)
    ,   fNEvents(0)
    ,   header(nullptr)
    ,   fatimaV1751Array(nullptr)
{
    fatima_vme_config = FatimaV1751Configuration::GetInstance();
}

FatimaV1751OnlineSpectra::~FatimaV1751OnlineSpectra()
{
    c4LOG(info, "Deleting data class arrays");
    delete fatimaV1751Array;
}

InitStatus FatimaV1751OnlineSpectra::Init()
{
    FairRootManager* mgr = FairRootManager::Instance();
    c4LOG_IF(fatal, NULL == mgr, "FairRootManager not found");

    FairRunOnline* run = FairRunOnline::Instance();
    run->GetHttpServer()->Register("", this);

    header = (EventHeader*)mgr->GetObject("EventHeader.");
    c4LOG_IF(error, !header, "Branch EventHeader. not found");

    fatimaV1751Array = mgr->InitObjectAs<decltype(fatimaV1751Array)>("FatimaV1751Data");
    c4LOG_IF(error, !header, "Branch FatimaV1751Data not found");

    histograms = (TFolder*)mgr->GetObject("Histograms");
    
    // Configuration
    nDetectors = fatima_vme_config->NDetectors();

    TDirectory::TContext ctx(nullptr);

    dir_fatima_vme = new TDirectory("Fatima V1751", "Fatima V1751", "", 0);
    //mgr->Register("Fatima VME", "Fatima VME Directory", dir_fatima_vme, false); // allows other tasks to access directory.
    histograms->Add(dir_fatima_vme);

    dir_stats_vme = dir_fatima_vme->mkdir("Stats");
    dir_energies = dir_fatima_vme->mkdir("Energy");
    dir_times = dir_fatima_vme->mkdir("Time");
    dir_dt = dir_fatima_vme->mkdir("Time Difference");

    // Setting histogram sizes
    h1_Fat_CalE.resize(nDetectors);
    h1_Fat_RawE_short.resize(nDetectors);
    h1_Fat_RawE_long.resize(nDetectors);
    h1_Fat_fine_time.resize(nDetectors);
    h1_Fat_trigger_time.resize(nDetectors);
    h1_Fat_time.resize(nDetectors);
    h1_Fat_dt_refCh0.resize(nDetectors);
    h1_Fat_dt_refCh1.resize(nDetectors);
    h1_Fat_dt_refCh2.resize(nDetectors);
    h1_Fat_dt_refCh3.resize(nDetectors);
    h1_Fat_dt_refCh4.resize(nDetectors);
    h1_Fat_dt_refCh5.resize(nDetectors);
    h1_Fat_dt_refCh6.resize(nDetectors);
    h1_Fat_dt_refCh7.resize(nDetectors);

    h1_Fat_Multi = MakeTH1(dir_stats_vme, "I", "h1_FatMult", "Fatima Multiplicity", nDetectors, 0, nDetectors, "Multiplicity", kRed-3, kBlack);
    h1_Fat_HitPattern = MakeTH1(dir_stats_vme, "I", "h1_Fat_HitPattern", "Fatima Hit Pattern", nDetectors, 0, nDetectors, "Detector", kRed-3, kBlack);
    h1_Fat_RawEShort_Sum = MakeTH1(dir_energies, "I", "h1_Fat_RawEShort_Sum", "Fatima Short Charge Sum", 6000, 0, 60000, "Short Charge", kRed-3, kBlack);
    h1_Fat_RawELong_Sum = MakeTH1(dir_energies, "I", "h1_Fat_RawELong_Sum", "Fatima Long Charge Sum", 6000, 0, 60000, "Long Charge", kRed-3, kBlack);
    h1_Fat_CalE_Sum = MakeTH1(dir_energies, "D", "h1_Fat_CalE_Sum", "Fatima Calibrated Energy Sum", 2000, 0, 2000, "Energy", kRed-3, kBlack);
    h2_Fat_CalE_GammaGamma_Sum = MakeTH2(dir_energies, "D", "h2_Fat_CalE_GammaGamma_Sum", "Fatima Energy Gamma Gamma Sum", 2000, 0, 2000, 2000, 0, 2000, "Energy 1", "Energy 2");
    h2_Fat_RawELong_GammaGamma_Sum = MakeTH2(dir_energies, "I", "h2_Fat_RawELong_GammaGamma_Sum", "Fatima Charge Long Gamma Gamma Sum", 6000, 0, 60000, 6000, 0, 60000, "Charge Long 1", "Charge Long 2");

    // dir_raw_energy = dir_raw_vme->mkdir("Raw Energy");
    // dir_raw_energy_short = dir_raw_vme->mkdir("Raw Energy Short");
    // dir_cal_energy = dir_cal_vme->mkdir("Calibrated Energy");
    // dir_raw_time = dir_raw_vme->mkdir("Raw Time");
    // dir_v1751_fine_time = dir_raw_vme->mkdir("Raw V1751 Fine Time");
    // dir_v1751_coarse_time = dir_raw_vme->mkdir("Raw V1751 Coarse Time");
    // dir_v1751_fine_bin = dir_raw_vme->mkdir("Raw V1751 Fine Bin");
    // dir_raw_traces = dir_raw_vme->mkdir("Traces");

    // for (int i = 0; i < nDetectors; i++)
    // {
    //     h1_v1751_fine_time[i] = MakeTH1(dir_v1751_fine_time, "D", Form("h1_v1751_fine_time_%i", i), Form("'Fine' Time (+Coarse Time): %i", i), 1000, 0, 1e8);
    //     h1_v1751_coarse_time[i] = MakeTH1(dir_v1751_coarse_time, "D", Form("h1_v1751_coarse_time_%i", i), Form("Coarse Time: %i", i), 1000, 0, 1e8);
    //     h1_v1751_fine_bin[i] = MakeTH1(dir_v1751_fine_bin, "I", Form("h1_v1751_fine_bin_%i", i), Form("Fine Bin: %i", i), 1024, 0, 1024);
    // }

    // for (int i = 0; i < nDetectors; i++)
    // {
    //     h1_raw_traces[i] = MakeTH1(dir_raw_traces, "I", Form("h1_raw_traces_%i", i), Form("Trace: %i", i), 1000, 0, 1000);
    // }

    // dir_raw_energy->cd();
    // c_FatVME_RawE = new TCanvas("c_FatVME_RawE","Fatima VME Raw Energies", 650, 350);
    // c_FatVME_RawE->Divide(4, nDetectors / 4);
    // for (int i = 0; i < nDetectors; i++)
    // {
    //     c_FatVME_RawE->cd(i+1);
    //     h1_FatVME_RawE[i] = MakeTH1(dir_raw_energy, "F", Form("h1_FatVme_RawE%i", i), Form("Fatima VME Raw Energy - Detector %i", i), 3000, 0, 10e3, "Energy [a.u.]", kSpring, kBlue+2);
    //     h1_FatVME_RawE[i]->Draw();
    // }
    // c_FatVME_RawE->cd(0);
    // dir_raw_energy->Append(c_FatVME_RawE);

    // dir_raw_energy_short->cd();
    // c_FatVME_RawE_short = new TCanvas("c_FatVME_RawE_short","Fatima VME Raw Energies Short", 650, 350);
    // c_FatVME_RawE_short->Divide(4, nDetectors / 4);
    // for (int i = 0; i < nDetectors; i++)
    // {
    //     c_FatVME_RawE_short->cd(i+1);
    //     h1_FatVME_RawE_short[i] = MakeTH1(dir_raw_energy_short, "F", Form("h1_FatVme_RawE_short%i", i), Form("Fatima VME Raw Energy Short - Detector %i", i), 3000, 0, 10e3, "Energy Short [a.u.]", kSpring, kBlue+2);
    //     h1_FatVME_RawE_short[i]->Draw();
    // }
    // c_FatVME_RawE_short->cd(0);
    // dir_raw_energy_short->Append(c_FatVME_RawE_short);

    // // dir_cal_energy->cd();
    // c_FatVME_E = new TCanvas("c_FatVME_E", "Fatima VME Calibrated Energies", 650, 350);
    // c_FatVME_E->Divide(4, nDetectors / 4);
    // for (int i = 0; i < nDetectors; i++)
    // {
    //     c_FatVME_E->cd(i+1);
    //     h1_FatVME_E[i] = MakeTH1(dir_cal_energy, "F", Form("h1_FatVME_E%i", i), Form("Fatima VME Energy - Detector %i", i), 4000, 0, 4000, "Energy [keV]", kViolet+1, kBlue+2);
    //     h1_FatVME_E[i]->Draw();
    // }
    // c_FatVME_E->cd(0);
    // dir_cal_energy->Append(c_FatVME_E);

    // h1_FatVME_E_Sum = new TH1D("h1_FatVME_E_Sum", "Fatima VME Energy - All Detectors summed", 4000, 0, 4000);
    
    // dir_raw_time->cd();
    // c_FatVME_RawT = new TCanvas("c_FatVME_RawT", "Fatima VME Raw Time", 650, 350);
    // c_FatVME_RawT->Divide(4, nDetectors / 4);
    // for (int i = 0; i < nDetectors; i++)
    // {
    //     c_FatVME_RawT->cd(i+1);
    //     h1_FatVME_RawT[i] = new TH1D(Form("h1_FatVme_RawT%i", i), Form("Fatima VME Raw Time - Detector %i", i), 5000, -1e6, 7e7);
    //     h1_FatVME_RawT[i]->Draw();
    // }
    // c_FatVME_RawT->cd(0);
    // dir_raw_time->Append(c_FatVME_RawT);

    // dir_tdc_dt = dir_fatima_vme->mkdir("Time Differences");
    // dir_dt_sc41 = dir_tdc_dt->mkdir("SC41L dT");
    // dir_dt_ch1 = dir_tdc_dt->mkdir("Ch1 dT");

    // dir_dt_sc41->cd();
    // c_FatVME_dTrefSC41 = new TCanvas("c_FatVME_dTrefSC41", "Fatima VME T - SC41L dT", 650, 350);
    // c_FatVME_dTrefSC41->Divide(4, nDetectors / 4);
    // for (int i = 0; i < nDetectors; i++)
    // {
    //     c_FatVME_dTrefSC41->cd(i+1);
    //     h1_FatVME_TDC_dT_refSC41L[i] = new TH1D(Form("h1_FatVME_TDC%i_dT_refSC41L", i), Form("Detector %i TDC dT ref. SC41L", i), 250, -2e4, 2e4);
    //     h1_FatVME_TDC_dT_refSC41L[i]->Draw();
    // }
    // c_FatVME_dTrefSC41->cd(0);
    // dir_dt_sc41->Append(c_FatVME_dTrefSC41);

    // c_FatVME_EvsdTsc41 = new TCanvas("c_FatVME_EvsdTsc41", "E vs dT (det - sc41)", 650, 350);
    // c_FatVME_EvsdTsc41->Divide(4, nDetectors / 4);
    // for (int i = 0; i < nDetectors; i++)
    // {
    //     c_FatVME_EvsdTsc41->cd(i+1);
    //     h2_FatVME_EvsdTsc41[i] = new TH2D(Form("h2_FatVME_EvsdTsc41_%i", i), Form("E vs dT (det - sc41) Det %i", i), 250, -5e3, 2e4, 2000, 0, 4e4);
    //     h2_FatVME_EvsdTsc41[i]->Draw("COLZ");
    // }
    // c_FatVME_EvsdTsc41->cd(0);
    // dir_dt_sc41->Append(c_FatVME_EvsdTsc41);
    // h2_FatVME_EvsdTsc41_summed = new TH2D("h2_FatVME_EvsdTsc41_summed", "E vs dT (det - sc41) Summed", 250,-5e3, 2e4, 2000, 0, 4e4);

    // dir_dt_ch1->cd();
    // c_FatVME_dTrefCh1 = new TCanvas("c_FatVME_dTrefCh1", "Fatima VME T - Ch1 T dT", 650, 350);
    // c_FatVME_dTrefCh1->Divide(4, nDetectors / 4);
    // for (int i = 0; i < nDetectors; i++)
    // {
    //     c_FatVME_dTrefCh1->cd(i+1);
    //     h1_FatVME_TDC_dt_refCh1[i] = new TH1D(Form("h1_FatVME_TDC%i_dt_refCh1", i), Form("Detector %i TDC dT ref. Detector 1", i), 4e4, -2e4, 2e4);
    //     h1_FatVME_TDC_dt_refCh1[i]->Draw();
    // }
    // c_FatVME_dTrefCh1->cd(0);
    // dir_dt_ch1->Append(c_FatVME_dTrefCh1);
    
    // dir_residuals->cd();
    // h1_FatVME_time_machine_undelayed = new TH1D("h1_FatVME_time_machine_undelayed", "Time Machine Undelayed - FATIMA VME", 2000, 0, 40000);
    // h1_FatVME_time_machine_delayed = new TH1D("h1_FatVME_time_machine_delayed", "Time Machine Delayed - FATIMA VME", 2000, 0, 40000);
    // h1_FatVME_sc41l_time = new TH1D("h1_FatVME_sc41l_time", "SC41L T - FATIMA VME", 5000, -1e6, 2e6);
    // h1_FatVME_sc41r_time = new TH1D("h1_FatVME_sc41r_time", "SC41R T - FATIMA VME", 5000, -1e6, 236);

    // dir_fatima_vme->cd();

    // h2_E1E2 = MakeTH2(dir_raw_energy, "F", "h2_E1E2", "Gamma Gamma I guess", 1e3, 0, 15e3, 1e3, 0, 15e3);

    run->GetHttpServer()->RegisterCommand("Reset_FATIMA_Histo", Form("/Objects/%s/->Reset_Histo()", GetName()));
    
    return kSUCCESS;

}

void FatimaV1751OnlineSpectra::Reset_Histo() {
    c4LOG(info, "Resetting FATIMA histograms.");

    // Assuming dir is a TDirectory pointer containing histograms
    if (dir_fatima_vme) {
        AnalysisTools_H::ResetHistogramsInDirectory(dir_fatima_vme);
        c4LOG(info, "FATIMA histograms reset.");
    } else {
        c4LOG(error, "Failed to get list of histograms from directory.");
    }
}


void FatimaV1751OnlineSpectra::Exec(Option_t* option)
{
    int mult = 0;
    int e_raw_coinc[nDetectors];
    int e_calib_coinc[nDetectors];
    double t_raw_coinc[nDetectors];
    for (auto const & fatimaV1751Item : *fatimaV1751Array)
    {   

        uint8_t channel_id = fatimaV1751Item.Get_channel_id();
        uint32_t channel_time_tag =  fatimaV1751Item.Get_channel_time_tag();
        uint64_t channel_ts = fatimaV1751Item.Get_channel_ts();
        uint32_t channel_fine_time = fatimaV1751Item.Get_channel_fine_time();
        double channel_time = fatimaV1751Item.Get_channel_time();
        uint16_t channel_charge_short = fatimaV1751Item.Get_channel_charge_short();
        uint16_t channel_charge_long = fatimaV1751Item.Get_channel_charge_long();
        double channel_energy = fatimaV1751Item.Get_channel_energy();


        h1_Fat_HitPattern->Fill(channel_id);
        h1_Fat_RawEShort_Sum->Fill(channel_charge_short);
        h1_Fat_RawELong_Sum->Fill(channel_charge_long);
        h1_Fat_CalE_Sum->Fill(channel_energy);
        // h2_Fat_CalE_GammaGamma_Sum->Fill();
        // h2_Fat_RawELong_GammaGamma_Sum->Fill();

        mult++;

    }

    h1_Fat_Multi->Fill(mult);

    // // fill qdc_mult
    // h1_FatVME_QDCMult->Fill(qdc_mult);
    // if (qdc_mult == 2) h2_E1E2->Fill(e_raw_coinc[0], e_raw_coinc[1]);
    // // plot time dt

    // int tdc_mult = 0;
    // for (auto const & tdcItem : *tdcCalArray)
    // {   
    //     int det = tdcItem.Get_detector();
    //     double timestamp = tdcItem.Get_timestamp();
        
    //     h1_FatVME_RawT[det]->Fill(timestamp * 25); // time in [ps]
    //     h1_FatVME_TDC_HitPattern->Fill(det);

    //     tdc_mult++;
    // }
    // // fill tdc_mult
    // h1_FatVME_TDCMult->Fill(tdc_mult);


    // if (qdcArray)
    // {
    //     for (auto const & qdcItem : *qdcArray)
    //     {   
    //         int det = qdcItem.Get_detector();
    //         std::vector<UInt_t> waveform_one = qdcItem.Get_waveform_one();
    //         for (int i = 0; i < 120 * 3; i++) h1_raw_traces[det]->SetBinContent(i, waveform_one[i]);
    //     }
    // }

    
    // for (auto const & residualItem : *residualArray)
    // {
    //     double ts_sc41l = residualItem.Get_SC41L();
    //     double ts_sc41r = residualItem.Get_SC41R();
    //     double ts_tmu = residualItem.Get_TM_Undelayed();
    //     double ts_tmd = residualItem.Get_TM_Delayed();

    //     if (ts_tmu > 0) h1_FatVME_time_machine_undelayed->Fill(ts_tmu);
    //     if (ts_tmd > 0) h1_FatVME_time_machine_delayed->Fill(ts_tmd);
    //     if (ts_sc41l > 0) h1_FatVME_sc41l_time->Fill(ts_sc41l);
    //     if (ts_sc41r > 0) h1_FatVME_sc41l_time->Fill(ts_sc41r);

    // } 

    // // CEJ: Maybe this is something I forgot .. 
    // /*for (int j = 0; j < SC41L_Hits.size(); j++)
    //             {
    //                 double dt = SC41L_Hits[j] - TDC_timestamp[i];
    //                 if (dt != 0) h1_FatVME_TDC_dT_refSC41L[TDC_IDs[i]]->Fill(dt);
    //             }

    //             if (TDC_IDs[i] == 1 && TDC_timestamp[i] != 0)
    //             {
    //                 double t1 = TDC_timestamp[i];
    //                 for (int j = 0; j < TDC_IDs.size(); j++)
    //                 {
    //                     if (i != j)
    //                     {
    //                         double t2 = TDC_timestamp[j];
    //                         double dt = t2 - t1;
    //                         if (dt != 0) h1_FatVME_TDC_dt_refCh1[TDC_IDs[j]]->Fill(dt);
    //                     }
    //                 }
    //             }*/
    
}

void FatimaV1751OnlineSpectra::FinishEvent()
{

}

void FatimaV1751OnlineSpectra::FinishTask()
{
    
}
