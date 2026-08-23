#ifndef FatimaV1751Configuration_H
#define FatimaV1751Configuration_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

// structs

class FatimaV1751Configuration
{
    public:
        static FatimaV1751Configuration const* GetInstance();
        static void Create();
        static void SetDetectorMapFile(std::string fp) { mapfilepath = fp; }
        static void Set_QDC_E_CalFile(std::string fp) { qdc_e_calfilepath = fp; }
        // static void Set_QDC_T_CalFile(std::string fp) { qdc_t_calfilepath = fp; }

        std::map<std::pair<int, int>, int> QDCMapping() const;
        int NQDCBoards() const;
        int NDetectors() const;
        bool MappingLoaded() const;
        bool ECalibLoaded() const;
        double** QDC_E_Calib() const;
        // double* QDC_T_Calib() const;

    private:
        static std::string mapfilepath;
        static std::string qdc_e_calfilepath;
        // static std::string qdc_t_calfilepath;
        FatimaV1751Configuration();
        void ReadConfiguration();
        void Read_QDC_E_Calibration();
        // void Read_QDC_T_Calibration();

        static FatimaV1751Configuration* instance;

        std::map<std::pair<int, int>, int> dets_qdc;
        // std::map<std::pair<int, int>, int> dets_tdc;

        double** calib_coeffs_QDC_E;
        double** original_calib_coeffs_QDC_E;
        // double* calib_coeffs_QDC_T;

        int num_detectors;
        int num_qdc_boards;
        // int num_tdc_boards;

        bool DetectorMap_loaded = 0;
        bool ECalibFile_loaded = 0;

};

inline FatimaV1751Configuration const* FatimaV1751Configuration::GetInstance()
{
    if (!instance)
    {
        FatimaV1751Configuration::Create();
    }
    return instance;
}

inline void FatimaV1751Configuration::Create()
{
    delete instance;
    instance = new FatimaV1751Configuration();
}

inline std::map<std::pair<int, int>, int> FatimaV1751Configuration::QDCMapping() const
{
    return dets_qdc;
}

inline int FatimaV1751Configuration::NQDCBoards() const
{
    return num_qdc_boards;
}

// inline std::map<std::pair<int, int>, int> FatimaV1751Configuration::TDCMapping() const
// {
//     return dets_tdc;
// }


inline int FatimaV1751Configuration::NDetectors() const
{
    return num_detectors;
}

inline bool FatimaV1751Configuration::MappingLoaded() const
{
    return DetectorMap_loaded;
}

inline bool FatimaV1751Configuration::ECalibLoaded() const
{
    return ECalibFile_loaded;
}


inline double** FatimaV1751Configuration::QDC_E_Calib() const
{
    return calib_coeffs_QDC_E;
}

// inline double* FatimaV1751Configuration::QDC_T_Calib() const
// {
//     return calib_coeffs_QDC_T;
// }


#endif
