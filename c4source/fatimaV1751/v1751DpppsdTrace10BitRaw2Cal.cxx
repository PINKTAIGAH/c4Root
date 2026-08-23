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
 *                                23.08.26                                    *
 ******************************************************************************/

// FairRoot
#include "FairTask.h"
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRunOnline.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"

#include "c4Logger.h"

// c4
#include "FatimaV1751Configuration.h"

#include "v1751DpppsdTrace10BitData.h"
#include "FatimaV1751Trace10BitData.h"

#include "TClonesArray.h"
#include "TMath.h"
#include "v1751DpppsdTrace10BitRaw2Cal.h"

/*
Empty constructor for FairRoot.
*/
v1751DpppsdTrace10BitRaw2Cal::v1751DpppsdTrace10BitRaw2Cal()
  : FairTask(), 
  fNEvents(0),
  header(nullptr),
  fOnline(kFALSE),
  funcal_data(new TClonesArray("v1751DpppsdTrace10BitData")),
  fcal_data(new TClonesArray("FatimaV1751Trace10BitData"))
  {
      fatima_vme_config = FatimaV1751Configuration::GetInstance();
  }

/*
Named constructor with verbosity level.
*/
v1751DpppsdTrace10BitRaw2Cal::v1751DpppsdTrace10BitRaw2Cal(const TString& name, Int_t verbose) 
  : FairTask(name, verbose),
  fNEvents(0),
  header(nullptr),
  fOnline(kFALSE),
  funcal_data(new TClonesArray("v1751DpppsdTrace10BitData")),
  fcal_data(new TClonesArray("FatimaV1751Trace10BitData"))
  {
      fatima_vme_config = FatimaV1751Configuration::GetInstance();
  }

v1751DpppsdTrace10BitRaw2Cal::~v1751DpppsdTrace10BitRaw2Cal(){
    c4LOG(info, "Deleting v1751DpppsdTrace10BitRaw2Cal task");
    if (funcal_data) delete funcal_data;
    if (fcal_data) delete fcal_data;
}



void v1751DpppsdTrace10BitRaw2Cal::SetParContainers()
{
    FairRuntimeDb *rtdb = FairRuntimeDb::instance();
    c4LOG_IF(fatal, NULL == rtdb, "FairRuntimeDb not found.");
}

/*
Init - register data to output tree and gets input data.
*/
InitStatus v1751DpppsdTrace10BitRaw2Cal::Init()
{
    FairRootManager* mgr = FairRootManager::Instance();
    c4LOG_IF(fatal, NULL == mgr, "FairRootManager not found");

    header = (EventHeader*)mgr->GetObject("EventHeader.");
    c4LOG_IF(error, !header, "Branch EventHeader. not found");

    funcal_data = (TClonesArray*)mgr->GetObject("v1751DpppsdTrace10BitData");
    c4LOG_IF(fatal, !funcal_data, "Fatima branch of v1751DpppsdTrace10BitData not found.");
 
    // needs to have the name of the detector subsystem here:
    FairRootManager::Instance()->Register("FatimaV1751Trace10BitData", "Fatima Cal Data", fcal_data, !fOnline);

    calib_coeffs_QDC_E = fatima_vme_config->QDC_E_Calib();
    
    fcal_data->Clear();

    return kSUCCESS;
}

// double AgataTraceRaw2Cal::LinearInterp(double frac, double val1, double val2){
//     // linear polynomial between (0, val1) and (1,val2) -> y = val2/val1 * x 
//     // returns the value at x = frac
//     return (val2-val1)*frac;
// }
// double AgataTraceRaw2Cal::GetFrac(double val1, double val2, double threshold){
//     // linear polynomial between (0, val1) and (1,val2) -> y = val2/val1 * x 
//     // returns the value x when y(x) = threshold
//     return threshold/(val2-val1);
// }

double v1751DpppsdTrace10BitRaw2Cal::Calibrate_QDC_E(double E, int det_id)
{
    double Energy_c = calib_coeffs_QDC_E[det_id][0];
    for (int i = 1; i < 4; i++) Energy_c = Energy_c * E + calib_coeffs_QDC_E[det_id][i];
    Energy_c += (static_cast<double>(rand()) / static_cast<double>(RAND_MAX + 0.5));
    return Energy_c;
}

/*
Analysis event loop. 
Fatal error if detector map is not set. If calibration coeffs are not written, simply the uncalibrated energies are written.

Picks out the TimeMachine.
*/
void v1751DpppsdTrace10BitRaw2Cal::Exec(Option_t* option)
{
    if (funcal_data && funcal_data->GetEntriesFast() > 0)
    {
        FatimaV1751Trace10BitData event;
        
        // Initialiser for cal specific prarams
        double channel_energy = 0;
        double channel_time = 0.;
        uint64_t channel_ts = 0.;
        
        // int nfired_segments = 0;
        // int64_t fevent_trigger_time = 0;
        // int64_t fhit_pattern = 0;
        // double seg_energies[36];
        // double seg_times[36];
        // int segid = -1;

        // double supertrace[supertrace_length];
        // double supertrace_shifted[supertrace_length];

        // int normsamples = 80;
        // double normalization[36];


        // for (int i=0; i<36; i++) seg_energies[i] = 0;
        // for (int i=0; i<36; i++) seg_times[i] = 0;
        // for (int i=0; i<supertrace_length; i++) supertrace[i] = 0;
        // for (int i=0; i<supertrace_length; i++) supertrace_shifted[i] = 0;


        Int_t event_multiplicity = funcal_data->GetEntriesFast();

        for (Int_t ihit = 0; ihit < event_multiplicity; ihit++)
        {
            funcal_hit = (v1751DpppsdTrace10BitData*)funcal_data->At(ihit);

            uint8_t board_id = funcal_hit->Get_board_id();
            uint8_t channel_id = funcal_hit->Get_channel_id();
            uint8_t detector_id = funcal_hit->Get_detector_id();
            // int64_t event_trigger_time = funcal_hit->Get_channel_trigger_time();
            uint32_t channel_time_tag = funcal_hit->Get_channel_time_tag();
            uint32_t channel_extended_time = funcal_hit->Get_channel_extended_time(); // in ticks 
            uint32_t channel_fine_time = funcal_hit->Get_channel_fine_time(); // in ticks 
            uint64_t channel_coarse_time = ((uint64_t)channel_extended_time << 32) | (uint64_t)channel_time_tag;

            channel_ts = channel_coarse_time;
            channel_time = (double)channel_coarse_time * 1.0 + (double)channel_fine_time / 1024.0;;

            // channel_time = (double)channel_time_tag + ((double)(channel_fine_time & 0x3FFu) / 1024.); // in ns
            uint16_t channel_charge_short = funcal_hit->Get_channel_charge_short(); 
            uint16_t channel_charge_long = funcal_hit->Get_channel_charge_long();
            // int32_t uncal_energy = funcal_hit->Get_channel_energy();
            channel_energy = (fatima_vme_config->ECalibLoaded()) ? Calibrate_QDC_E((double)channel_charge_long, (int) detector_id) : 0.;

            uint16_t trace_length = funcal_hit->Get_trace_length();
            uint16_t trace[VMEV1751_TRACE_SIZE] = {0};
            for (int idx = 0; idx < trace_length; idx++){
                trace[idx] = funcal_hit->Get_trace(idx);
            }

            // c4LOG(info, Form("RAW2CAL :: bid = %i, chid = %i, detid = %i, calib?= %i, e = %f",board_id,channel_id,detector_id,fatima_vme_config->ECalibLoaded(),channel_energy));

            event.Set_num_channels_fired(event_multiplicity);
            event.Set_board_id(board_id);
            event.Set_channel_id(channel_id);
            event.Set_detector_id(detector_id);
            event.Set_channel_time_tag(channel_time_tag);
            event.Set_channel_ts(channel_ts);
            event.Set_channel_fine_time(channel_fine_time);
            event.Set_channel_time(channel_time);
            event.Set_channel_charge_short(channel_charge_short);
            event.Set_channel_charge_long(channel_charge_long);
            event.Set_channel_energy(channel_energy);

            event.Set_length(trace_length);
            for (int idx = 0; idx < trace_length; idx++){
                event.Set_trace_val((uint16_t)trace[idx], idx);
            }

            event.Set_wr_subsystem_id(0);
            event.Set_wr_t(0);

            // c4LOG(info, Form("bid = %i, chid = %i, time_tag = %i, time = %i, ql = %i, qs = %i",board_id,channel_id,channel_time_tag,channel_time,channel_charge_long,channel_charge_short));

            bool set_write = (channel_charge_long>0) ? true : false;
        
            if (set_write) new ((*fcal_data)[fcal_data->GetEntriesFast()]) FatimaV1751Trace10BitData(event);  
        
        }

    }
}


/*
Very important function - all TClonesArray must be cleared after each event.
*/
void v1751DpppsdTrace10BitRaw2Cal::FinishEvent(){
    funcal_data->Clear();
    fcal_data->Clear();
};



ClassImp(v1751DpppsdTrace10BitRaw2Cal)
