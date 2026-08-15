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
#include "FatimaV1751Data.h"

FatimaV1751Data::FatimaV1751Data()
    : 
      fnum_channels_fired(0),
      fboard_id(0),
      fchannel_id(0),
      fchannel_time_tag(0),
      fchannel_fine_time(0),
      fchannel_time(0),
      fchannel_charge_short(0),
      fchannel_charge_long(0),
      fchannel_energy(0),
      fwr_subsystem_id(0),
      fwr_t(0)
{}

FatimaV1751Data::FatimaV1751Data(
  uint32_t num_channels_fired,
  uint8_t board_id,
  uint8_t channel_id,
  uint32_t channel_time_tag,
  uint32_t channel_fine_time,
  double channel_time,
  uint16_t channel_charge_short,
  uint16_t channel_charge_long,
  uint16_t channel_energy,
  uint16_t wr_subsystem_id,
  uint64_t wr_t)
  : 
    fnum_channels_fired(num_channels_fired),
    fboard_id(board_id),
    fchannel_id(channel_id),
    fchannel_time_tag(channel_time_tag),
    fchannel_fine_time(channel_fine_time),
    fchannel_time(channel_time),
    fchannel_charge_short(channel_charge_short),
    fchannel_charge_long(channel_charge_long),
    fchannel_energy(channel_energy),
    fwr_subsystem_id(wr_subsystem_id),
    fwr_t(wr_t)
{}

ClassImp(FatimaV1751Data)
