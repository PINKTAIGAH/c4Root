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
 *                                11.08.26                                    *
 ******************************************************************************/

// FairRoot
#include "FairLogger.h"
#include "FairRootManager.h"

// c4
#include "v1751DpppsdReader.h"
#include "v1751DpppsdData.h"
#include "FatimaV1751Configuration.h"
// #include "QDCData.h"
#include "c4Logger.h"

#include "TClonesArray.h"
#include "ext_data_struct_info.hh"

extern "C"
{
    #include "ext_data_client.h"
    #include "ext_h101_v1751.h"
}

v1751DpppsdReader::v1751DpppsdReader(EXT_STR_h101_v1751_onion* data, size_t offset)
    : c4Reader("v1751DpppsdReader")
    , fNEvent(0)
    , fData(data)
    , fOffset(offset)
    , fOnline(kFALSE)
    , fArray(new TClonesArray("v1751DpppsdData"))
    // , fArrayqdc(new TClonesArray("QDCData"))
{
}

v1751DpppsdReader::~v1751DpppsdReader() { 
    delete fArray;
    // delete fArrayqdc;

}

Bool_t v1751DpppsdReader::Init(ext_data_struct_info* a_struct_info)
{
    Int_t ok;

    EXT_STR_h101_v1751_ITEMS_INFO(ok, *a_struct_info, fOffset, EXT_STR_h101_v1751, 0);

    if (!ok)
    {
        c4LOG(error, "Failed to set up structure information");
        return kFALSE;
    }

    // Register output array in a tree
    FairRootManager::Instance()->Register("v1751DpppsdData", "FATIMA v1751 Data", fArray, !fOnline);
    fArray->Clear();


    // Get configuration singleton`
    FatimaV1751Configuration const* fatima_conf = FatimaV1751Configuration::GetInstance();
    NBoards = fatima_conf->NQDCBoards();
    dets_qdc = fatima_conf->QDCMapping();

    // // Register output array in a tree
    // FairRootManager::Instance()->Register("QDCData", "QDC V792 Data", fArrayqdc, !fOnline);
    // fArrayqdc->Clear();

    run = FairRunOnline::Instance();


    memset(fData, 0, sizeof *fData);

    return kTRUE;
}


Bool_t v1751DpppsdReader::Read()
{
    c4LOG(debug1, "Event Data");

    if(!fData) return kTRUE;

    // uint32_t num_channels_fired = fData->vme_qdc_n;
    // for (int ihit = 0; ihit < num_channels_fired; ihit++){
    //     int channel = (int)fData->vme_qdc_nI[ihit];
    //     int16_t charge = (int16_t)fData->vme_qdc_data[ihit];

        // new ((*fArrayqdc)[fArrayqdc->GetEntriesFast()]) QDCData(
        // 0,
        // channel,
        // charge,
        // 0, //wr here if added in the future
        // 0
        // );
    // }

    uint32_t board_id = fData->vme_v1751_board_id;
    
    uint32_t* vme_v1751_channels[] = {
        &fData->vme_v1751_channels1, &fData->vme_v1751_channels2, &fData->vme_v1751_channels3, &fData->vme_v1751_channels4,
        &fData->vme_v1751_channels5, &fData->vme_v1751_channels6, &fData->vme_v1751_channels7, &fData->vme_v1751_channels8
    };

    uint32_t* vme_v1751_nsamples[] = {
        &fData->vme_v1751_nsamples_trace1, &fData->vme_v1751_nsamples_trace2, &fData->vme_v1751_nsamples_trace3, &fData->vme_v1751_nsamples_trace4,
        &fData->vme_v1751_nsamples_trace5, &fData->vme_v1751_nsamples_trace6, &fData->vme_v1751_nsamples_trace7, &fData->vme_v1751_nsamples_trace8
    };

    uint32_t* vme_v1751_trigger_time[] = {
        &fData->vme_v1751_trigger_time1, &fData->vme_v1751_trigger_time2, &fData->vme_v1751_trigger_time3, &fData->vme_v1751_trigger_time4,
        &fData->vme_v1751_trigger_time5, &fData->vme_v1751_trigger_time6, &fData->vme_v1751_trigger_time7, &fData->vme_v1751_trigger_time8
    };

    uint32_t* vme_v1751_fine_time[] = {
        &fData->vme_v1751_fine_time1, &fData->vme_v1751_fine_time2, &fData->vme_v1751_fine_time3, &fData->vme_v1751_fine_time4,
        &fData->vme_v1751_fine_time5, &fData->vme_v1751_fine_time6, &fData->vme_v1751_fine_time7, &fData->vme_v1751_fine_time8
    };

    uint32_t* vme_v1751_charge_short[] = {
        &fData->vme_v1751_q_short1, &fData->vme_v1751_q_short2, &fData->vme_v1751_q_short3, &fData->vme_v1751_q_short4,
        &fData->vme_v1751_q_short5, &fData->vme_v1751_q_short6, &fData->vme_v1751_q_short7, &fData->vme_v1751_q_short8
    };

    uint32_t* vme_v1751_charge_long[] = {
        &fData->vme_v1751_q_long1, &fData->vme_v1751_q_long2, &fData->vme_v1751_q_long3, &fData->vme_v1751_q_long4,
        &fData->vme_v1751_q_long5, &fData->vme_v1751_q_long6, &fData->vme_v1751_q_long7, &fData->vme_v1751_q_long8
    };

    uint32_t* vme_v1751_sample_trace[] = {
        &fData->vme_v1751_sample_trace1, &fData->vme_v1751_sample_trace2, &fData->vme_v1751_sample_trace3, &fData->vme_v1751_sample_trace4,
        &fData->vme_v1751_sample_trace5, &fData->vme_v1751_sample_trace6, &fData->vme_v1751_sample_trace7, &fData->vme_v1751_sample_trace8
    };

    uint32_t (*vme_v1751_sample_traceI[8])[2000] = {
        &fData->vme_v1751_sample_trace1I, &fData->vme_v1751_sample_trace2I, &fData->vme_v1751_sample_trace3I, &fData->vme_v1751_sample_trace4I,
        &fData->vme_v1751_sample_trace5I, &fData->vme_v1751_sample_trace6I, &fData->vme_v1751_sample_trace7I, &fData->vme_v1751_sample_trace8I
    };

    uint32_t (*vme_v1751_sample_traceV[8])[2000] = {
        &fData->vme_v1751_sample_trace1v, &fData->vme_v1751_sample_trace2v, &fData->vme_v1751_sample_trace3v, &fData->vme_v1751_sample_trace4v,
        &fData->vme_v1751_sample_trace5v, &fData->vme_v1751_sample_trace6v, &fData->vme_v1751_sample_trace7v, &fData->vme_v1751_sample_trace8v
    };

    int nfired_ch = 0;
    for (int ich = 0; ich < 8; ich++) {
        if (*vme_v1751_channels[ich] != 0) nfired_ch++; 
    }

    for (int ich = 0; ich<8; ich++){
        if (*vme_v1751_channels[ich] == 0) continue; // not fired, skip.
        
        uint8_t current_detector_id = dets_qdc[std::make_pair(board_id, ich)]; // get detector id
        v1751DpppsdData * event = new v1751DpppsdData(
          nfired_ch,board_id,ich,current_detector_id,*vme_v1751_trigger_time[ich],*vme_v1751_fine_time[ich],*vme_v1751_charge_short[ich],*vme_v1751_charge_long[ich],
          0,0 // last two are WR, change if want to add it in
        );
        event->Set_length(*vme_v1751_sample_trace[ich]);
        for (int it = 0; it<*vme_v1751_sample_trace[ich];it++){
            event->Set_trace_val((uint16_t)((*vme_v1751_sample_traceV[ich])[it]), it);
        }
        new ((*fArray)[fArray->GetEntriesFast()]) v1751DpppsdData(*event);
    }

    if (!fOnline && ControlOutput){
        if (nfired_ch >= multiplicity_filter){
            run->MarkFill(true);
        }else{
            run->MarkFill(false);
        }
    }


    fNEvent += 1;
    return kTRUE;
}



void v1751DpppsdReader::Reset()
{
    // reset output array
    fArray->Clear();
    // fArrayqdc->Clear();
}



ClassImp(v1751DpppsdReader)
