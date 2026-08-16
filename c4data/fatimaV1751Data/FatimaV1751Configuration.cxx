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
 *                                16.08.26                                    *
 ******************************************************************************/

#include "FatimaV1751Configuration.h"

#include "c4Logger.h"

#include <iostream>
#include <sstream>
#include <string>
#include <set>

FatimaV1751Configuration* FatimaV1751Configuration::instance = nullptr;
std::string FatimaV1751Configuration::mapfilepath = "Fatima_channel_allocation.txt";
std::string FatimaV1751Configuration::qdc_e_calfilepath = "";
// std::string FatimaV1751Configuration::qdc_t_calfilepath = "";

FatimaV1751Configuration::FatimaV1751Configuration()
    :   num_detectors(0)
    ,   num_qdc_boards(0)
{
    ReadConfiguration();
    Read_QDC_E_Calibration();
    // Read_QDC_T_Calibration();
}

void FatimaV1751Configuration::ReadConfiguration()
{
    std::ifstream detector_map_file(mapfilepath);
    std::string line;
    std::set<int> detector_ids;
    std::set<int> qdc_boards;

    if (detector_map_file.fail()) c4LOG(warn, "Could not open Fatima V1751 configuration map");

    while (std::getline(detector_map_file, line))
    {
        if (line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        std::string signal;

        int det, qdc_board, qdc_chan;

        iss >> signal;

        if (isdigit(signal[0])) // detector
        {
            det = std::stoi(signal);
            
            iss >> qdc_board >> qdc_chan;

            if (det > -1) detector_ids.insert(det);
            
        }

        if (qdc_board > -1) qdc_boards.insert(qdc_board);

        dets_qdc[std::make_pair(qdc_board, qdc_chan)] = det;

    }

    DetectorMap_loaded = 1;
    num_detectors = detector_ids.size();
    num_qdc_boards = qdc_boards.size();
    detector_map_file.close();
    return;
}

void FatimaV1751Configuration::Read_QDC_E_Calibration()
{
    // Note this is only compatible with 100 detectors at a time!!!
    std::ifstream calfile(qdc_e_calfilepath);
    std::string line;

    const char* format = "%d %lf %lf %lf %lf";
    calib_coeffs_QDC_E = new double*[100];
    for (int i = 0; i < 100; i++) calib_coeffs_QDC_E[i] = new double[4];
    original_calib_coeffs_QDC_E = new double*[100];
    for (int i = 0; i < 100; i++) original_calib_coeffs_QDC_E[i] = new double[4];

    if (calfile.fail()) c4LOG(warn, "Could not open Fatima VME QDC E calibration file.");

    double tmp_coeffs[4] = {0, 0, 0, 0};
    int det_id = 0;

    while (calfile.good())
    {
        std::getline(calfile, line, '\n');
        if (line[0] == '#' || line.empty()) continue;

        sscanf(line.c_str(), format, &det_id, &tmp_coeffs[0], &tmp_coeffs[1], &tmp_coeffs[2], &tmp_coeffs[3]);
        
        for (int i = 0; i < 4; i++)
        {
            calib_coeffs_QDC_E[det_id][i] = tmp_coeffs[i];
            original_calib_coeffs_QDC_E[det_id][i] = tmp_coeffs[i];
        }
        ECalibFile_loaded = true;
    }
}

// void FatimaV1751Configuration::Read_QDC_T_Calibration()
// {
//     const char* format = "%d %lf";
//     calib_coeffs_QDC_T = new double[100];

//     std::ifstream calfile(qdc_t_calfilepath);
//     std::string line;

//     if (calfile.fail()) c4LOG(warn, "Could not find Fatima VME QDC T Calibration file");
    
//     double tmp_coeffs;
//     int det_id = 0;

//     while (calfile.good())
//     {
//         std::getline(calfile, line, '\n');
//         if (line[0] == '#' || line.empty()) continue;
        
//         sscanf(line.c_str(), format, &det_id, &tmp_coeffs);

//         calib_coeffs_QDC_T[det_id] = tmp_coeffs;
//     }
// }


