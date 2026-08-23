#ifndef v1751DpppsdTrace10BitData_H
#define v1751DpppsdTrace10BitData_H

#include "TObject.h"

// #define VMEV1751_TRACE_SIZE 3000 // When traces are enabled
#define VMEV1751_TRACE_SIZE 2 // When traces are disabled

class v1751DpppsdTrace10BitData : public TObject
{
    public:
        // Default Constructor
        v1751DpppsdTrace10BitData();

        v1751DpppsdTrace10BitData(
                        uint32_t num_channels_fired,
                        uint8_t board_id,
                        uint8_t channel_id,
                        uint8_t detector_id,
                        uint32_t channel_time_tag,
                        uint32_t channel_extended_time,
                        uint32_t channel_fine_time,
                        uint16_t channel_charge_short,
                        uint16_t channel_charge_long,
                        uint16_t wr_subsystem_id,
                        uint64_t wr_t
                        );

        // Destructor
        virtual ~v1751DpppsdTrace10BitData() {};

        // Getters
        inline const uint32_t Get_num_channels_fired() const { return fnum_channels_fired; }
        inline const uint8_t Get_board_id() const { return fboard_id; }
        inline const uint8_t Get_channel_id() const { return fchannel_id; }
        inline const uint8_t Get_detector_id() const { return fdetector_id; }
        inline const uint32_t Get_channel_time_tag() const { return fchannel_time_tag; }
        inline const uint32_t Get_channel_extended_time() const { return fchannel_extended_time; }
        inline const uint32_t Get_channel_fine_time() const { return fchannel_fine_time; }
        inline const uint16_t Get_channel_charge_short() const { return fchannel_charge_short; }
        inline const uint16_t Get_channel_charge_long() const { return fchannel_charge_long; }

        inline const uint16_t Get_trace(const int idx) {
            return trace[idx];
        }
        inline const uint16_t Get_trace_length() {
            return flength;
        }

        inline const uint16_t Get_wr_subsystem_id() const { return fwr_subsystem_id; }
        inline const uint64_t Get_wr_t() const { return fwr_t; }



        // Setters
        void Set_num_channels_fired(uint32_t v) { fnum_channels_fired = v; }
        void Set_board_id(uint8_t v) { fboard_id = v; }
        void Set_channel_id(uint8_t v) { fchannel_id = v; }
        void Set_detector_id(uint8_t v) { fdetector_id = v; }
        void Set_channel_time_tag(uint32_t v) { fchannel_time_tag = v; }
        void Set_channel_extended_time(uint32_t v) { fchannel_extended_time = v; }
        void Set_channel_fine_time(uint32_t v) { fchannel_fine_time = v; }
        void Set_channel_charge_short(uint16_t v) { fchannel_charge_short = v; }
        void Set_channel_charge_long(uint16_t v) { fchannel_charge_long = v; }

        void Set_trace_val(uint16_t vtrace, int idx) {
                trace[idx] = vtrace;
        }
        void Set_length(int length){flength = length;}

        void Set_wr_subsystem_id(uint32_t v) { fwr_subsystem_id = v; }
        void Set_wr_t(uint64_t v) { fwr_t = v; }

    protected:
        // Data items
        uint32_t fnum_channels_fired;
        uint8_t fboard_id;
        uint8_t fchannel_id;
        uint8_t fdetector_id;
        uint32_t fchannel_time_tag;
        uint32_t fchannel_extended_time;
        uint32_t fchannel_fine_time;
        uint16_t fchannel_charge_short;
        uint16_t fchannel_charge_long;
        uint16_t trace[VMEV1751_TRACE_SIZE];
        uint16_t flength;

        //whiterabbit
        uint32_t fwr_subsystem_id;
        uint64_t fwr_t;
    

    public:
        ClassDef(v1751DpppsdTrace10BitData, 1);
};

#endif
