#ifndef V1751DpppsddRaw2Cal_H
#define V1751DpppsddRaw2Cal_H

#include "FairTask.h"
#include "FatimaV1751Configuration.h"
#include "FatimaV1751Data.h"

#include <vector>
#include <set>
#include <map>

class TClonesArray;
class EventHeader;
class FatimaV1751Data;
class v1751DpppsdData;
// class AgataSuperTraceData;

class v1751DpppsdRaw2Cal : public FairTask
{
    public:
        v1751DpppsdRaw2Cal();

        v1751DpppsdRaw2Cal(const TString& name, Int_t verbose);

        virtual ~v1751DpppsdRaw2Cal();
        
        void SetOnline(Bool_t set_online){fOnline = set_online;}

        virtual void Exec(Option_t* option);

        virtual void FinishEvent();

        virtual void SetParContainers();

        virtual InitStatus Init();

        double Calibrate_QDC_E(double E, int det_id);

    private:
        Bool_t fOnline;

        TClonesArray* fcal_data;
        TClonesArray* funcal_data;
        
        FatimaV1751Configuration const* fatima_vme_config;

        v1751DpppsdData* funcal_hit;
        FatimaV1751Data* fcal_hit;

        // int trace_length = TRACE_LENGTH;
        // int supertrace_length = trace_length*37;

        // double energy_gate = 0;
        // double energy_gate_width = 0;
        
        // Calib params
        double** calib_coeffs_QDC_E;



        EventHeader * header;
        Int_t fNEvents = 0;


    public:
        ClassDef(v1751DpppsdRaw2Cal, 1);
};

#endif
