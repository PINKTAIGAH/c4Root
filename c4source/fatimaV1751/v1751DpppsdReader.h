#ifndef v1751DpppsdReader_H
#define v1751DpppsdReader_H

#include "c4Reader.h"
#include "FairRunOnline.h"

#include <Rtypes.h>
#include <unordered_map>
#include <map>
#include <set>

extern "C"
{
    #include "ext_h101_v1751.h"
}

class TClonesArray;

struct EXT_STR_h101_v1751_t;
typedef struct EXT_STR_h101_v1751_t EXT_STR_h101_v1751;
typedef struct EXT_STR_h101_v1751_onion_t EXT_STR_h101_v1751_onion;
class ext_data_struct_info;

class v1751DpppsdReader : public c4Reader
{
    public:
        v1751DpppsdReader(EXT_STR_h101_v1751_onion*, size_t);

        virtual ~v1751DpppsdReader();


        virtual Bool_t Init(ext_data_struct_info*) override;

        virtual Bool_t Read() override;

        virtual void Reset() override;

        void SetOnline(Bool_t option) { fOnline = option; }


        void SetVetoPileupStatus(bool v){VetoPileup = v;}
        void SetVetoOverflowStatus(bool v){VetoOverflow = v;}
        void SetWriteZeroMultEvents(bool v){WriteZeroMultEvents = v;}

        void SetControlOutput(bool v){ControlOutput = v;}
        void SetMultiplicityOutput(int v){multiplicity_filter = v;}
    
    private:
        unsigned int fNEvent;

        FairRunOnline* run;

        EXT_STR_h101_v1751_onion* fData;

        size_t fOffset;

        Bool_t fOnline;
        int multiplicity_filter = 1; // change for online 

        TClonesArray* fArray;
        // TClonesArray* fArrayqdc;

        bool ControlOutput = false;


        int NBoards = 1; //change

        std::map<std::pair<int, int>, int> dets_qdc;

        uint64_t event_trigger_time_long;
        uint64_t channel_trigger_time_long;
        uint64_t channel_fine_time_long;

        int32_t channel_charge_long;
        int32_t channel_charge_short;

        bool VetoPileup = 1; //should I veto on Pileup flag?
        bool VetoOverflow = 1; //should I veto on overflow flag?
        bool WriteZeroMultEvents = 0; // Write triggered DAQ events with no channels fired?


    public:
        ClassDefOverride(v1751DpppsdReader, 0);
};

#endif