#ifndef FatimaV1751Trace10BitOnlineSpectra_H
#define FatimaV1751Trace10BitOnlineSpectra_H

#include "FairTask.h"
#include "TCanvas.h"
#include <vector>
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TFolder.h"
#include "TDirectory.h"
#include "TH1F.h"
#include "TH2F.h"
#include "FatimaV1751Configuration.h"
#include "FatimaV1751Trace10BitData.h"

class EventHeader;
class TFolder;
class TDirectory;
class TFile;
class TH1I;
class TH1D;
class TH2D;

class FatimaV1751Trace10BitOnlineSpectra : public FairTask
{
    public:
        FatimaV1751Trace10BitOnlineSpectra();
        FatimaV1751Trace10BitOnlineSpectra(const TString& name, Int_t verbose = 1);

        virtual ~FatimaV1751Trace10BitOnlineSpectra();

        virtual InitStatus Init();

        virtual void Exec(Option_t* option);

        virtual void FinishEvent();

        virtual void FinishTask();

        virtual void Reset_Histo();

    private:
        FatimaV1751Configuration const* fatima_vme_config;

        TClonesArray* fHitFatimaV1751;

        // std::vector<v1751DpppsdData> const* v1751DpppsdArray;
        // std::vector<FatimaV1751Data> const* fatimaV1751Array;

        EventHeader* header;
        Int_t fNEvents;

        int nDetectors;

        // Folders
        TFolder* histograms;
        TDirectory* dir_fatima_vme;
        TDirectory* dir_stats_vme;
        TDirectory* dir_energies;
        TDirectory* dir_times;
        TDirectory* dir_dt;

    // dir_stats_vme = dir_fatima_vme->mkdir("Stats");
    // dir_energries = dir_fatima_vme->mkdir("Energy");
    // dir_times = dir_fatima_vme->mkdir("Time");
    // dir_dt = dir_fatima_vme->mkdir("Time Difference");

    //     TDirectory* dir_stats_vme;
    //     TDirectory* dir_cal_energy;
    //     TDirectory* dir_charge_short;
    //     TDirectory* dir_charge_long;
    //     TDirectory* dir_fine_time;
    //     TDirectory* dir_time_tag;
    //     TDirectory* dir_time;
    //     // TDirectory* dir_raw_traces;
    //     TDirectory* dir_dt;
    //     TDirectory* dir_dt_ch0;
    //     TDirectory* dir_dt_ch1;
    //     TDirectory* dir_dt_ch2;
    //     TDirectory* dir_dt_ch3;
    //     TDirectory* dir_dt_ch4;
    //     TDirectory* dir_dt_ch5;
    //     TDirectory* dir_dt_ch6;
    //     TDirectory* dir_dt_ch7;

        // Canvases
        TCanvas* c_Fat_CalE;
        TCanvas* c_Fat_RawE_short;
        TCanvas* c_Fat_RawE_long;
        TCanvas* c_Fat_TFine;
        TCanvas* c_Fat_TTrigger;
        TCanvas* c_Fat_Time;
        TCanvas* c_Fat_dTrefCh0;
        TCanvas* c_Fat_dTrefCh1;
        TCanvas* c_Fat_dTrefCh2;
        TCanvas* c_Fat_dTrefCh3;
        TCanvas* c_Fat_dTrefCh4;
        TCanvas* c_Fat_dTrefCh5;
        TCanvas* c_Fat_dTrefCh6;
        TCanvas* c_Fat_dTrefCh7;

        // Histograms

        TH1* h1_Fat_CalE_Sum;
        TH1* h1_Fat_RawELong_Sum;
        TH1* h1_Fat_RawEShort_Sum;
        TH1* h1_Fat_HitPattern;
        TH1* h1_Fat_Multi;
        TH2* h2_Fat_CalE_GammaGamma_Sum;
        TH2* h2_Fat_RawELong_GammaGamma_Sum;
        std::vector<TH1*> h1_Fat_CalE;
        std::vector<TH1*> h1_Fat_RawE_short;
        std::vector<TH1*> h1_Fat_RawE_long;
        std::vector<TH1*> h1_Fat_fine_time;
        std::vector<TH1*> h1_Fat_trigger_time;
        std::vector<TH1*> h1_Fat_time;
        // std::vector<TH1*> h1_raw_traces;
        std::vector<TH1D*> h1_Fat_dt_refCh0;
        std::vector<TH1D*> h1_Fat_dt_refCh1;
        std::vector<TH1D*> h1_Fat_dt_refCh2;
        std::vector<TH1D*> h1_Fat_dt_refCh3;
        std::vector<TH1D*> h1_Fat_dt_refCh4;
        std::vector<TH1D*> h1_Fat_dt_refCh5;
        std::vector<TH1D*> h1_Fat_dt_refCh6;
        std::vector<TH1D*> h1_Fat_dt_refCh7;

    public:
        ClassDef(FatimaV1751Trace10BitOnlineSpectra, 1);
};



#endif
