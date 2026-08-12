#ifndef V1751DpppsddRaw2Cal_H
#define V1751DpppsddRaw2Cal_H

#include "FairTask.h"
// #include "TAgataConfiguration.h"
#include "FatimaV1751Data.h"

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

        // Helper functions for future raw2cal analysis
        
        // double LinearInterp(double,double,double);
        // double GetFrac(double,double,double);

        // void SetEnergyGate(double energy, double tol){energy_gate = energy; energy_gate_width = tol;}

    private:
        Bool_t fOnline;

        TClonesArray* fcal_data;
        TClonesArray* funcal_data;
        
        // Add later for configuration
        // const TAgataConfiguration *  agata_configuration;

        v1751DpppsdData* funcal_hit;
        FatimaV1751Data* fcal_hit;

        // int trace_length = TRACE_LENGTH;
        // int supertrace_length = trace_length*37;

        // double energy_gate = 0;
        // double energy_gate_width = 0;



        EventHeader * header;
        Int_t fNEvents = 0;


    public:
        ClassDef(v1751DpppsdRaw2Cal, 1);
};

#endif
