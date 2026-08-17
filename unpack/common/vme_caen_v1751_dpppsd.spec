// channel mask is provided
// one option is simply to encode this mask value
// analyse it for fired channels later? 
// not sure its possible in ucesb .spec

#define TRACE_LENGTH 2000 // is maximum or something



VME_CAEN_V1751_DPPPSD(geom)
{
    MEMBER(DATA8 board_id);
    MEMBER(DATA8 channels[8]);
    MEMBER(DATA32 board_time);
    MEMBER(DATA32 event_size);

    MEMBER(DATA16 nsamples_trace[8]);
    MEMBER(DATA32 trigger_time[8]);
    MEMBER(DATA16 sample_trace[8][TRACE_LENGTH] ZERO_SUPPRESS);

    // Fine time (from EXTRAS word, bits 0-9), and short/long gate charges
    // (from the charge word, bits 0-14 and 16-31 respectively).
    // Layout depends on the board's EXTRAS format setting; this matches
    // Extras Format 2 (fine timestamp only), as used in the Go4 unpacker.
    MEMBER(DATA16 extended_time[8]);
    MEMBER(DATA16 fine_time[8]);
    MEMBER(DATA16 q_short[8]);
    MEMBER(DATA16 q_long[8]);

    UINT32 board_header NOENCODE
    {
        0_27: event_size;
        28_31: id = MATCH(0xa);

        ENCODE(event_size, (value = event_size));
        
    };

    UINT32 board_details NOENCODE
    {
        0: channels_0; // channel_mask
        1: channels_1; // channel_mask
        2: channels_2; // channel_mask
        3: channels_3; // channel_mask
        4: channels_4; // channel_mask
        5: channels_5; // channel_mask
        6: channels_6; // channel_mask
        7: channels_7; // channel_mask
        8_23: pattern;
        24_25: empty;
        26: board_fail;
        27_31: id = MATCH(geom); // "geo"
        ENCODE(channels[0], (value = channels_0));
        ENCODE(channels[1], (value = channels_1));
        ENCODE(channels[2], (value = channels_2));
        ENCODE(channels[3], (value = channels_3));
        ENCODE(channels[4], (value = channels_4));
        ENCODE(channels[5], (value = channels_5));
        ENCODE(channels[6], (value = channels_6));
        ENCODE(channels[7], (value = channels_7));
        ENCODE(board_id, (value = id));
    };

    UINT32 board_counter NOENCODE
    {
        0_22: counter;
        23_31: empty;
    };

    UINT32 board_timetag NOENCODE
    {
        0_31: time_tag;
        ENCODE(board_time, (value = time_tag));
    };

    // --- end of first four words, always present --- //
    if (board_header.event_size > 4){
    if (board_details.channels_0)
    {
        UINT32 channel_size NOENCODE
        {
            0_21: channel_agg_size;
            28_31: format = MATCH(0x4);
        };

        UINT32 num_samples NOENCODE
        {
            0_15: num_samples;
            16_31: garbage;
            ENCODE(nsamples_trace[0], (value=num_samples));
        };
        
        UINT32 format NOENCODE
        {
            0_31: dontneed;
        };
        UINT32 trigger_tag_agg NOENCODE
        {
            0_31: triggertime;
            ENCODE(trigger_time[0], (value=triggertime));
        };

        list (0 <= index < num_samples.num_samples*4)
        {
            UINT32 trace_value NOENCODE
            {
                0_9: sample_one;
                10_19: sample_two;
                20_29: sample_three;
                30_31: nwords;

                ENCODE(sample_trace[0][index*3], (value=sample_one));
                ENCODE(sample_trace[0][index*3+1], (value=sample_two));
                ENCODE(sample_trace[0][index*3+2], (value=sample_three));
            };
        }
        
        UINT32 extras NOENCODE
        {
            0_9: fine_time;
            10_15: extra_flags; // Flags in EXTRAS Format 2 (0b010)
            16_31: extended_time;

            ENCODE(fine_time[0], (value=fine_time));
            ENCODE(extended_time[0], (value=extended_time));
        };
        UINT32 charge NOENCODE
        {
            0_14: charge_short;
            15: pileup_flag;
            16_31: charge_long;

            ENCODE(q_short[0], (value=charge_short));
            ENCODE(q_long[0], (value=charge_long));
        };
    };
    if (board_details.channels_1)
    {
        UINT32 channel_size NOENCODE
        {
            0_21: channel_agg_size;
            28_31: format = MATCH(0x4);
        };

        UINT32 num_samples NOENCODE
        {
            0_15: num_samples;
            16_31: garbage;
            ENCODE(nsamples_trace[1], (value=num_samples));
        };
        
        UINT32 format NOENCODE
        {
            0_31: dontneed;
        };
        UINT32 trigger_tag_agg NOENCODE
        {
            0_31: triggertime;
            ENCODE(trigger_time[1], (value=triggertime));
        };

        list (0 <= index < num_samples.num_samples*4)
        {
            UINT32 trace_value NOENCODE
            {
                0_9: sample_one;
                10_19: sample_two;
                20_29: sample_three;
                30_31: nwords;

                ENCODE(sample_trace[1][index*3], (value=sample_one));
                ENCODE(sample_trace[1][index*3+1], (value=sample_two));
                ENCODE(sample_trace[1][index*3+2], (value=sample_three));
            };
        }
        
        UINT32 extras NOENCODE
        {
            0_9: fine_time;
            10_15: extra_flags; // Flags in EXTRAS Format 2 (0b010)
            16_31: extended_time;

            ENCODE(fine_time[1], (value=fine_time));
            ENCODE(extended_time[1], (value=extended_time));
        };
        UINT32 charge NOENCODE
        {
            0_14: charge_short;
            15: pileup_flag;
            16_31: charge_long;

            ENCODE(q_short[1], (value=charge_short));
            ENCODE(q_long[1], (value=charge_long));
        };
    };
    if (board_details.channels_2)
    {
        UINT32 channel_size NOENCODE
        {
            0_21: channel_agg_size;
            28_31: format = MATCH(0x4);
        };

        UINT32 num_samples NOENCODE
        {
            0_15: num_samples;
            16_31: garbage;
            ENCODE(nsamples_trace[2], (value=num_samples));
        };
        
        UINT32 format NOENCODE
        {
            0_31: dontneed;
        };
        UINT32 trigger_tag_agg NOENCODE
        {
            0_31: triggertime;
            ENCODE(trigger_time[2], (value=triggertime));
        };

        list (0 <= index < num_samples.num_samples*4)
        {
            UINT32 trace_value NOENCODE
            {
                0_9: sample_one;
                10_19: sample_two;
                20_29: sample_three;
                30_31: nwords;

                ENCODE(sample_trace[2][index*3], (value=sample_one));
                ENCODE(sample_trace[2][index*3+1], (value=sample_two));
                ENCODE(sample_trace[2][index*3+2], (value=sample_three));
            };
        }
        
        UINT32 extras NOENCODE
        {
            0_9: fine_time;
            10_15: extra_flags; // Flags in EXTRAS Format 2 (0b010)
            16_31: extended_time;

            ENCODE(fine_time[2], (value=fine_time));
            ENCODE(extended_time[2], (value=extended_time));
        };
        UINT32 charge NOENCODE
        {
            0_14: charge_short;
            15: pileup_flag;
            16_31: charge_long;

            ENCODE(q_short[2], (value=charge_short));
            ENCODE(q_long[2], (value=charge_long));
        };
    };
    if (board_details.channels_3)
    {
        UINT32 channel_size NOENCODE
        {
            0_21: channel_agg_size;
            28_31: format = MATCH(0x4);
        };

        UINT32 num_samples NOENCODE
        {
            0_15: num_samples;
            16_31: garbage;
            ENCODE(nsamples_trace[3], (value=num_samples));
        };
        
        UINT32 format NOENCODE
        {
            0_31: dontneed;
        };
        UINT32 trigger_tag_agg NOENCODE
        {
            0_31: triggertime;
            ENCODE(trigger_time[3], (value=triggertime));
        };

        list (0 <= index < num_samples.num_samples*4)
        {
            UINT32 trace_value NOENCODE
            {
                0_9: sample_one;
                10_19: sample_two;
                20_29: sample_three;
                30_31: nwords;

                ENCODE(sample_trace[3][index*3], (value=sample_one));
                ENCODE(sample_trace[3][index*3+1], (value=sample_two));
                ENCODE(sample_trace[3][index*3+2], (value=sample_three));
            };
        }
        
        UINT32 extras NOENCODE
        {
            0_9: fine_time;
            10_15: extra_flags; // Flags in EXTRAS Format 2 (0b010)
            16_31: extended_time;

            ENCODE(fine_time[3], (value=fine_time));
            ENCODE(extended_time[3], (value=extended_time));
        };
        UINT32 charge NOENCODE
        {
            0_14: charge_short;
            15: pileup_flag;
            16_31: charge_long;

            ENCODE(q_short[3], (value=charge_short));
            ENCODE(q_long[3], (value=charge_long));
        };
    };
    if (board_details.channels_4)
    {
        UINT32 channel_size NOENCODE
        {
            0_21: channel_agg_size;
            28_31: format = MATCH(0x4);
        };

        UINT32 num_samples NOENCODE
        {
            0_15: num_samples;
            16_31: garbage;
            ENCODE(nsamples_trace[4], (value=num_samples));
        };
        
        UINT32 format NOENCODE
        {
            0_31: dontneed;
        };
        UINT32 trigger_tag_agg NOENCODE
        {
            0_31: triggertime;
            ENCODE(trigger_time[4], (value=triggertime));
        };

        list (0 <= index < num_samples.num_samples*4)
        {
            UINT32 trace_value NOENCODE
            {
                0_9: sample_one;
                10_19: sample_two;
                20_29: sample_three;
                30_31: nwords;

                ENCODE(sample_trace[4][index*3], (value=sample_one));
                ENCODE(sample_trace[4][index*3+1], (value=sample_two));
                ENCODE(sample_trace[4][index*3+2], (value=sample_three));
            };
        }
        
        UINT32 extras NOENCODE
        {
            0_9: fine_time;
            10_15: extra_flags; // Flags in EXTRAS Format 2 (0b010)
            16_31: extended_time;

            ENCODE(fine_time[4], (value=fine_time));
            ENCODE(extended_time[4], (value=extended_time));
        };
        UINT32 charge NOENCODE
        {
            0_14: charge_short;
            15: pileup_flag;
            16_31: charge_long;

            ENCODE(q_short[4], (value=charge_short));
            ENCODE(q_long[4], (value=charge_long));
        };
    };
    if (board_details.channels_5)
    {
        UINT32 channel_size NOENCODE
        {
            0_21: channel_agg_size;
            28_31: format = MATCH(0x4);
        };

        UINT32 num_samples NOENCODE
        {
            0_15: num_samples;
            16_31: garbage;
            ENCODE(nsamples_trace[5], (value=num_samples));
        };
        
        UINT32 format NOENCODE
        {
            0_31: dontneed;
        };
        UINT32 trigger_tag_agg NOENCODE
        {
            0_31: triggertime;
            ENCODE(trigger_time[5], (value=triggertime));
        };

        list (0 <= index < num_samples.num_samples*4)
        {
            UINT32 trace_value NOENCODE
            {
                0_9: sample_one;
                10_19: sample_two;
                20_29: sample_three;
                30_31: nwords;

                ENCODE(sample_trace[5][index*3], (value=sample_one));
                ENCODE(sample_trace[5][index*3+1], (value=sample_two));
                ENCODE(sample_trace[5][index*3+2], (value=sample_three));
            };
        }
        
        UINT32 extras NOENCODE
        {
            0_9: fine_time;
            10_15: extra_flags; // Flags in EXTRAS Format 2 (0b010)
            16_31: extended_time;

            ENCODE(fine_time[5], (value=fine_time));
            ENCODE(extended_time[5], (value=extended_time));
        };
        UINT32 charge NOENCODE
        {
            0_14: charge_short;
            15: pileup_flag;
            16_31: charge_long;

            ENCODE(q_short[5], (value=charge_short));
            ENCODE(q_long[5], (value=charge_long));
        };
    };
    if (board_details.channels_6)
    {
        UINT32 channel_size NOENCODE
        {
            0_21: channel_agg_size;
            28_31: format = MATCH(0x4);
        };

        UINT32 num_samples NOENCODE
        {
            0_15: num_samples;
            16_31: garbage;
            ENCODE(nsamples_trace[6], (value=num_samples));
        };
        
        UINT32 format NOENCODE
        {
            0_31: dontneed;
        };
        UINT32 trigger_tag_agg NOENCODE
        {
            0_31: triggertime;
            ENCODE(trigger_time[6], (value=triggertime));
        };

        list (0 <= index < num_samples.num_samples*4)
        {
            UINT32 trace_value NOENCODE
            {
                0_9: sample_one;
                10_19: sample_two;
                20_29: sample_three;
                30_31: nwords;

                ENCODE(sample_trace[6][index*3], (value=sample_one));
                ENCODE(sample_trace[6][index*3+1], (value=sample_two));
                ENCODE(sample_trace[6][index*3+2], (value=sample_three));
            };
        }
        
        UINT32 extras NOENCODE
        {
            0_9: fine_time;
            10_15: extra_flags; // Flags in EXTRAS Format 2 (0b010)
            16_31: extended_time;

            ENCODE(fine_time[6], (value=fine_time));
            ENCODE(extended_time[6], (value=extended_time));
        };
        UINT32 charge NOENCODE
        {
            0_14: charge_short;
            15: pileup_flag;
            16_31: charge_long;

            ENCODE(q_short[6], (value=charge_short));
            ENCODE(q_long[6], (value=charge_long));
        };
    };
    if (board_details.channels_7)
    {
        UINT32 channel_size NOENCODE
        {
            0_21: channel_agg_size;
            28_31: format = MATCH(0x4);
        };

        UINT32 num_samples NOENCODE
        {
            0_15: num_samples;
            16_31: garbage;
            ENCODE(nsamples_trace[7], (value=num_samples));
        };
        
        UINT32 format NOENCODE
        {
            0_31: dontneed;
        };
        UINT32 trigger_tag_agg NOENCODE
        {
            0_31: triggertime;
            ENCODE(trigger_time[7], (value=triggertime));
        };

        list (0 <= index < num_samples.num_samples*4)
        {
            UINT32 trace_value NOENCODE
            {
                0_9: sample_one;
                10_19: sample_two;
                20_29: sample_three;
                30_31: nwords;

                ENCODE(sample_trace[7][index*3], (value=sample_one));
                ENCODE(sample_trace[7][index*3+1], (value=sample_two));
                ENCODE(sample_trace[7][index*3+2], (value=sample_three));
            };
        }
        
        UINT32 extras NOENCODE
        {
            0_9: fine_time;
            10_15: extra_flags; // Flags in EXTRAS Format 2 (0b010)
            16_31: extended_time;

            ENCODE(fine_time[7], (value=fine_time));
            ENCODE(extended_time[7], (value=extended_time));
        };
        UINT32 charge NOENCODE
        {
            0_14: charge_short;
            15: pileup_flag;
            16_31: charge_long;

            ENCODE(q_short[7], (value=charge_short));
            ENCODE(q_long[7], (value=charge_long));
        };
    };

    /*

    UINT32 trail1 NOENCODE
    {
        0_31: nope;
    };
    
    UINT32 trail2 NOENCODE
    {
        0_31: nope;
    };
    */
    };
}
