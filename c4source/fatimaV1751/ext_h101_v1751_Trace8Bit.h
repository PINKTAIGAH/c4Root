/********************************************************
 *
 * Structure for ext_data_fetch_event() filling.
 *
 * Do not edit - automatically generated.
 */

#ifndef __GUARD_H101_V1751_Trace8Bit_EXT_H101_V1751_H__
#define __GUARD_H101_V1751_Trace8Bit_EXT_H101_V1751_H__

#ifndef __CINT__
# include <stdint.h>
#else
/* For CINT (old version trouble with stdint.h): */
# ifndef uint32_t
typedef unsigned int uint32_t;
typedef          int  int32_t;
# endif
#endif
#ifndef EXT_STRUCT_CTRL
# define EXT_STRUCT_CTRL(x)
#endif

/********************************************************
 *
 * Plain structure (layout as ntuple/root file):
 */

typedef struct EXT_STR_h101_v1751_Trace8Bit_t
{
  /* UNPACK */
  // uint32_t vme_qdc_n /* [0,32] */;
  // uint32_t vme_qdc_nI[32 EXT_STRUCT_CTRL(vme_qdc_n)] /* [1,32] */;
  // uint32_t vme_qdc_data[32 EXT_STRUCT_CTRL(vme_qdc_n)] /* [0,16777215] */;
  uint32_t vme_v1751_board_id /* [0,255] */;
  uint32_t vme_v1751_channels1 /* [0,255] */;
  uint32_t vme_v1751_channels2 /* [0,255] */;
  uint32_t vme_v1751_channels3 /* [0,255] */;
  uint32_t vme_v1751_channels4 /* [0,255] */;
  uint32_t vme_v1751_channels5 /* [0,255] */;
  uint32_t vme_v1751_channels6 /* [0,255] */;
  uint32_t vme_v1751_channels7 /* [0,255] */;
  uint32_t vme_v1751_channels8 /* [0,255] */;
  uint32_t vme_v1751_board_time /* [-1,-1] */;
  uint32_t vme_v1751_event_size /* [-1,-1] */;
  uint32_t vme_v1751_nsamples_trace1 /* [0,65535] */;
  uint32_t vme_v1751_nsamples_trace2 /* [0,65535] */;
  uint32_t vme_v1751_nsamples_trace3 /* [0,65535] */;
  uint32_t vme_v1751_nsamples_trace4 /* [0,65535] */;
  uint32_t vme_v1751_nsamples_trace5 /* [0,65535] */;
  uint32_t vme_v1751_nsamples_trace6 /* [0,65535] */;
  uint32_t vme_v1751_nsamples_trace7 /* [0,65535] */;
  uint32_t vme_v1751_nsamples_trace8 /* [0,65535] */;
  uint32_t vme_v1751_trigger_time1 /* [-1,-1] */;
  uint32_t vme_v1751_trigger_time2 /* [-1,-1] */;
  uint32_t vme_v1751_trigger_time3 /* [-1,-1] */;
  uint32_t vme_v1751_trigger_time4 /* [-1,-1] */;
  uint32_t vme_v1751_trigger_time5 /* [-1,-1] */;
  uint32_t vme_v1751_trigger_time6 /* [-1,-1] */;
  uint32_t vme_v1751_trigger_time7 /* [-1,-1] */;
  uint32_t vme_v1751_trigger_time8 /* [-1,-1] */;
  uint32_t vme_v1751_extended_time1 /* [-1,-1] */;
  uint32_t vme_v1751_extended_time2 /* [-1,-1] */;
  uint32_t vme_v1751_extended_time3 /* [-1,-1] */;
  uint32_t vme_v1751_extended_time4 /* [-1,-1] */;
  uint32_t vme_v1751_extended_time5 /* [-1,-1] */;
  uint32_t vme_v1751_extended_time6 /* [-1,-1] */;
  uint32_t vme_v1751_extended_time7 /* [-1,-1] */;
  uint32_t vme_v1751_extended_time8 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time1 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time2 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time3 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time4 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time5 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time6 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time7 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time8 /* [-1,-1] */;
  uint32_t vme_v1751_q_short1 /* [-1,-1] */;
  uint32_t vme_v1751_q_short2 /* [-1,-1] */;
  uint32_t vme_v1751_q_short3 /* [-1,-1] */;
  uint32_t vme_v1751_q_short4 /* [-1,-1] */;
  uint32_t vme_v1751_q_short5 /* [-1,-1] */;
  uint32_t vme_v1751_q_short6 /* [-1,-1] */;
  uint32_t vme_v1751_q_short7 /* [-1,-1] */;
  uint32_t vme_v1751_q_short8 /* [-1,-1] */;
  uint32_t vme_v1751_q_long1 /* [-1,-1] */;
  uint32_t vme_v1751_q_long2 /* [-1,-1] */;
  uint32_t vme_v1751_q_long3 /* [-1,-1] */;
  uint32_t vme_v1751_q_long4 /* [-1,-1] */;
  uint32_t vme_v1751_q_long5 /* [-1,-1] */;
  uint32_t vme_v1751_q_long6 /* [-1,-1] */;
  uint32_t vme_v1751_q_long7 /* [-1,-1] */;
  uint32_t vme_v1751_q_long8 /* [-1,-1] */;
  uint32_t vme_v1751_sample_trace1 /* [0,2000] */;
  uint32_t vme_v1751_sample_trace1I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace1)] /* [1,2000] */;
  uint32_t vme_v1751_sample_trace1v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace1)] /* [0,65535] */;
  uint32_t vme_v1751_sample_trace2 /* [0,2000] */;
  uint32_t vme_v1751_sample_trace2I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace2)] /* [1,2000] */;
  uint32_t vme_v1751_sample_trace2v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace2)] /* [0,65535] */;
  uint32_t vme_v1751_sample_trace3 /* [0,2000] */;
  uint32_t vme_v1751_sample_trace3I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace3)] /* [1,2000] */;
  uint32_t vme_v1751_sample_trace3v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace3)] /* [0,65535] */;
  uint32_t vme_v1751_sample_trace4 /* [0,2000] */;
  uint32_t vme_v1751_sample_trace4I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace4)] /* [1,2000] */;
  uint32_t vme_v1751_sample_trace4v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace4)] /* [0,65535] */;
  uint32_t vme_v1751_sample_trace5 /* [0,2000] */;
  uint32_t vme_v1751_sample_trace5I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace5)] /* [1,2000] */;
  uint32_t vme_v1751_sample_trace5v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace5)] /* [0,65535] */;
  uint32_t vme_v1751_sample_trace6 /* [0,2000] */;
  uint32_t vme_v1751_sample_trace6I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace6)] /* [1,2000] */;
  uint32_t vme_v1751_sample_trace6v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace6)] /* [0,65535] */;
  uint32_t vme_v1751_sample_trace7 /* [0,2000] */;
  uint32_t vme_v1751_sample_trace7I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace7)] /* [1,2000] */;
  uint32_t vme_v1751_sample_trace7v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace7)] /* [0,65535] */;
  uint32_t vme_v1751_sample_trace8 /* [0,2000] */;
  uint32_t vme_v1751_sample_trace8I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace8)] /* [1,2000] */;
  uint32_t vme_v1751_sample_trace8v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_trace8)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp11 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp11I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp11)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp11v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp11)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp12 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp12I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp12)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp12v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp12)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp13 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp13I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp13)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp13v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp13)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp14 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp14I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp14)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp14v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp14)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp15 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp15I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp15)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp15v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp15)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp16 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp16I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp16)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp16v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp16)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp17 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp17I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp17)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp17v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp17)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp18 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp18I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp18)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp18v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp18)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp21 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp21I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp21)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp21v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp21)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp22 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp22I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp22)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp22v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp22)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp23 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp23I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp23)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp23v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp23)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp24 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp24I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp24)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp24v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp24)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp25 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp25I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp25)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp25v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp25)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp26 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp26I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp26)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp26v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp26)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp27 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp27I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp27)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp27v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp27)] /* [0,65535] */;
  uint32_t vme_v1751_sample_dp28 /* [0,2000] */;
  uint32_t vme_v1751_sample_dp28I[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp28)] /* [1,2000] */;
  uint32_t vme_v1751_sample_dp28v[2000 EXT_STRUCT_CTRL(vme_v1751_sample_dp28)] /* [0,65535] */;

} EXT_STR_h101_v1751_Trace8Bit;

/********************************************************
 *
 * Structure with multiple levels of arrays (partially)
 * recovered (recommended):
 */

typedef struct EXT_STR_h101_v1751_Trace8Bit_onion_t
{
  /* UNPACK */
  // uint32_t vme_qdc_n;
  // uint32_t vme_qdc_nI[32 /* vme_qdc_n */];
  // uint32_t vme_qdc_data[32 /* vme_qdc_n */];
  uint32_t vme_v1751_board_id;
  uint32_t vme_v1751_channels1;
  uint32_t vme_v1751_channels2;
  uint32_t vme_v1751_channels3;
  uint32_t vme_v1751_channels4;
  uint32_t vme_v1751_channels5;
  uint32_t vme_v1751_channels6;
  uint32_t vme_v1751_channels7;
  uint32_t vme_v1751_channels8;
  uint32_t vme_v1751_board_time;
  uint32_t vme_v1751_event_size;
  uint32_t vme_v1751_nsamples_trace1;
  uint32_t vme_v1751_nsamples_trace2;
  uint32_t vme_v1751_nsamples_trace3;
  uint32_t vme_v1751_nsamples_trace4;
  uint32_t vme_v1751_nsamples_trace5;
  uint32_t vme_v1751_nsamples_trace6;
  uint32_t vme_v1751_nsamples_trace7;
  uint32_t vme_v1751_nsamples_trace8;
  uint32_t vme_v1751_trigger_time1;
  uint32_t vme_v1751_trigger_time2;
  uint32_t vme_v1751_trigger_time3;
  uint32_t vme_v1751_trigger_time4;
  uint32_t vme_v1751_trigger_time5;
  uint32_t vme_v1751_trigger_time6;
  uint32_t vme_v1751_trigger_time7;
  uint32_t vme_v1751_trigger_time8;
  uint32_t vme_v1751_extended_time1;
  uint32_t vme_v1751_extended_time2;
  uint32_t vme_v1751_extended_time3;
  uint32_t vme_v1751_extended_time4;
  uint32_t vme_v1751_extended_time5;
  uint32_t vme_v1751_extended_time6;
  uint32_t vme_v1751_extended_time7;
  uint32_t vme_v1751_extended_time8;
  uint32_t vme_v1751_fine_time1 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time2 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time3 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time4 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time5 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time6 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time7 /* [-1,-1] */;
  uint32_t vme_v1751_fine_time8 /* [-1,-1] */;
  uint32_t vme_v1751_q_short1 /* [-1,-1] */;
  uint32_t vme_v1751_q_short2 /* [-1,-1] */;
  uint32_t vme_v1751_q_short3 /* [-1,-1] */;
  uint32_t vme_v1751_q_short4 /* [-1,-1] */;
  uint32_t vme_v1751_q_short5 /* [-1,-1] */;
  uint32_t vme_v1751_q_short6 /* [-1,-1] */;
  uint32_t vme_v1751_q_short7 /* [-1,-1] */;
  uint32_t vme_v1751_q_short8 /* [-1,-1] */;
  uint32_t vme_v1751_q_long1 /* [-1,-1] */;
  uint32_t vme_v1751_q_long2 /* [-1,-1] */;
  uint32_t vme_v1751_q_long3 /* [-1,-1] */;
  uint32_t vme_v1751_q_long4 /* [-1,-1] */;
  uint32_t vme_v1751_q_long5 /* [-1,-1] */;
  uint32_t vme_v1751_q_long6 /* [-1,-1] */;
  uint32_t vme_v1751_q_long7 /* [-1,-1] */;
  uint32_t vme_v1751_q_long8 /* [-1,-1] */;
  uint32_t vme_v1751_sample_trace1;
  uint32_t vme_v1751_sample_trace1I[2000 /* vme_v1751_sample_trace1 */];
  uint32_t vme_v1751_sample_trace1v[2000 /* vme_v1751_sample_trace1 */];
  uint32_t vme_v1751_sample_trace2;
  uint32_t vme_v1751_sample_trace2I[2000 /* vme_v1751_sample_trace2 */];
  uint32_t vme_v1751_sample_trace2v[2000 /* vme_v1751_sample_trace2 */];
  uint32_t vme_v1751_sample_trace3;
  uint32_t vme_v1751_sample_trace3I[2000 /* vme_v1751_sample_trace3 */];
  uint32_t vme_v1751_sample_trace3v[2000 /* vme_v1751_sample_trace3 */];
  uint32_t vme_v1751_sample_trace4;
  uint32_t vme_v1751_sample_trace4I[2000 /* vme_v1751_sample_trace4 */];
  uint32_t vme_v1751_sample_trace4v[2000 /* vme_v1751_sample_trace4 */];
  uint32_t vme_v1751_sample_trace5;
  uint32_t vme_v1751_sample_trace5I[2000 /* vme_v1751_sample_trace5 */];
  uint32_t vme_v1751_sample_trace5v[2000 /* vme_v1751_sample_trace5 */];
  uint32_t vme_v1751_sample_trace6;
  uint32_t vme_v1751_sample_trace6I[2000 /* vme_v1751_sample_trace6 */];
  uint32_t vme_v1751_sample_trace6v[2000 /* vme_v1751_sample_trace6 */];
  uint32_t vme_v1751_sample_trace7;
  uint32_t vme_v1751_sample_trace7I[2000 /* vme_v1751_sample_trace7 */];
  uint32_t vme_v1751_sample_trace7v[2000 /* vme_v1751_sample_trace7 */];
  uint32_t vme_v1751_sample_trace8;
  uint32_t vme_v1751_sample_trace8I[2000 /* vme_v1751_sample_trace8 */];
  uint32_t vme_v1751_sample_trace8v[2000 /* vme_v1751_sample_trace8 */];
  uint32_t vme_v1751_sample_dp11;
  uint32_t vme_v1751_sample_dp11I[2000 /* vme_v1751_sample_dp11 */];
  uint32_t vme_v1751_sample_dp11v[2000 /* vme_v1751_sample_dp11 */];
  uint32_t vme_v1751_sample_dp12;
  uint32_t vme_v1751_sample_dp12I[2000 /* vme_v1751_sample_dp12 */];
  uint32_t vme_v1751_sample_dp12v[2000 /* vme_v1751_sample_dp12 */];
  uint32_t vme_v1751_sample_dp13;
  uint32_t vme_v1751_sample_dp13I[2000 /* vme_v1751_sample_dp13 */];
  uint32_t vme_v1751_sample_dp13v[2000 /* vme_v1751_sample_dp13 */];
  uint32_t vme_v1751_sample_dp14;
  uint32_t vme_v1751_sample_dp14I[2000 /* vme_v1751_sample_dp14 */];
  uint32_t vme_v1751_sample_dp14v[2000 /* vme_v1751_sample_dp14 */];
  uint32_t vme_v1751_sample_dp15;
  uint32_t vme_v1751_sample_dp15I[2000 /* vme_v1751_sample_dp15 */];
  uint32_t vme_v1751_sample_dp15v[2000 /* vme_v1751_sample_dp15 */];
  uint32_t vme_v1751_sample_dp16;
  uint32_t vme_v1751_sample_dp16I[2000 /* vme_v1751_sample_dp16 */];
  uint32_t vme_v1751_sample_dp16v[2000 /* vme_v1751_sample_dp16 */];
  uint32_t vme_v1751_sample_dp17;
  uint32_t vme_v1751_sample_dp17I[2000 /* vme_v1751_sample_dp17 */];
  uint32_t vme_v1751_sample_dp17v[2000 /* vme_v1751_sample_dp17 */];
  uint32_t vme_v1751_sample_dp18;
  uint32_t vme_v1751_sample_dp18I[2000 /* vme_v1751_sample_dp18 */];
  uint32_t vme_v1751_sample_dp18v[2000 /* vme_v1751_sample_dp18 */];
  uint32_t vme_v1751_sample_dp21;
  uint32_t vme_v1751_sample_dp21I[2000 /* vme_v1751_sample_dp21 */];
  uint32_t vme_v1751_sample_dp21v[2000 /* vme_v1751_sample_dp21 */];
  uint32_t vme_v1751_sample_dp22;
  uint32_t vme_v1751_sample_dp22I[2000 /* vme_v1751_sample_dp22 */];
  uint32_t vme_v1751_sample_dp22v[2000 /* vme_v1751_sample_dp22 */];
  uint32_t vme_v1751_sample_dp23;
  uint32_t vme_v1751_sample_dp23I[2000 /* vme_v1751_sample_dp23 */];
  uint32_t vme_v1751_sample_dp23v[2000 /* vme_v1751_sample_dp23 */];
  uint32_t vme_v1751_sample_dp24;
  uint32_t vme_v1751_sample_dp24I[2000 /* vme_v1751_sample_dp24 */];
  uint32_t vme_v1751_sample_dp24v[2000 /* vme_v1751_sample_dp24 */];
  uint32_t vme_v1751_sample_dp25;
  uint32_t vme_v1751_sample_dp25I[2000 /* vme_v1751_sample_dp25 */];
  uint32_t vme_v1751_sample_dp25v[2000 /* vme_v1751_sample_dp25 */];
  uint32_t vme_v1751_sample_dp26;
  uint32_t vme_v1751_sample_dp26I[2000 /* vme_v1751_sample_dp26 */];
  uint32_t vme_v1751_sample_dp26v[2000 /* vme_v1751_sample_dp26 */];
  uint32_t vme_v1751_sample_dp27;
  uint32_t vme_v1751_sample_dp27I[2000 /* vme_v1751_sample_dp27 */];
  uint32_t vme_v1751_sample_dp27v[2000 /* vme_v1751_sample_dp27 */];
  uint32_t vme_v1751_sample_dp28;
  uint32_t vme_v1751_sample_dp28I[2000 /* vme_v1751_sample_dp28 */];
  uint32_t vme_v1751_sample_dp28v[2000 /* vme_v1751_sample_dp28 */];

} EXT_STR_h101_v1751_Trace8Bit_onion;

/*******************************************************/

#define EXT_STR_h101_v1751_Trace8Bit_ITEMS_INFO(ok,si,offset,struct_t,printerr) do { \
  ok = 1; \
  /* UNPACK */ \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_board_id,              UINT32,\
                    "vme_v1751_board_id",255,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_channels1,             UINT32,\
                    "vme_v1751_channels1",255,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_channels2,             UINT32,\
                    "vme_v1751_channels2",255,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_channels3,             UINT32,\
                    "vme_v1751_channels3",255,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_channels4,             UINT32,\
                    "vme_v1751_channels4",255,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_channels5,             UINT32,\
                    "vme_v1751_channels5",255,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_channels6,             UINT32,\
                    "vme_v1751_channels6",255,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_channels7,             UINT32,\
                    "vme_v1751_channels7",255,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_channels8,             UINT32,\
                    "vme_v1751_channels8",255,0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_board_time,            UINT32,\
                    "vme_v1751_board_time",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_event_size,            UINT32,\
                    "vme_v1751_event_size",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_nsamples_trace1,       UINT32,\
                    "vme_v1751_nsamples_trace1",65535,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_nsamples_trace2,       UINT32,\
                    "vme_v1751_nsamples_trace2",65535,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_nsamples_trace3,       UINT32,\
                    "vme_v1751_nsamples_trace3",65535,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_nsamples_trace4,       UINT32,\
                    "vme_v1751_nsamples_trace4",65535,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_nsamples_trace5,       UINT32,\
                    "vme_v1751_nsamples_trace5",65535,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_nsamples_trace6,       UINT32,\
                    "vme_v1751_nsamples_trace6",65535,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_nsamples_trace7,       UINT32,\
                    "vme_v1751_nsamples_trace7",65535,0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_nsamples_trace8,       UINT32,\
                    "vme_v1751_nsamples_trace8",65535,0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_trigger_time1,         UINT32,\
                    "vme_v1751_trigger_time1",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_trigger_time2,         UINT32,\
                    "vme_v1751_trigger_time2",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_trigger_time3,         UINT32,\
                    "vme_v1751_trigger_time3",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_trigger_time4,         UINT32,\
                    "vme_v1751_trigger_time4",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_trigger_time5,         UINT32,\
                    "vme_v1751_trigger_time5",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_trigger_time6,         UINT32,\
                    "vme_v1751_trigger_time6",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_trigger_time7,         UINT32,\
                    "vme_v1751_trigger_time7",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_trigger_time8,         UINT32,\
                    "vme_v1751_trigger_time8",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_extended_time1,         UINT32,\
                    "vme_v1751_extended_time1",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_extended_time2,         UINT32,\
                    "vme_v1751_extended_time2",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_extended_time3,         UINT32,\
                    "vme_v1751_extended_time3",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_extended_time4,         UINT32,\
                    "vme_v1751_extended_time4",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_extended_time5,         UINT32,\
                    "vme_v1751_extended_time5",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_extended_time6,         UINT32,\
                    "vme_v1751_extended_time6",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_extended_time7,         UINT32,\
                    "vme_v1751_extended_time7",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_extended_time8,         UINT32,\
                    "vme_v1751_extended_time8",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_fine_time1,         UINT32,\
                    "vme_v1751_fine_time1",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_fine_time2,         UINT32,\
                    "vme_v1751_fine_time2",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_fine_time3,         UINT32,\
                    "vme_v1751_fine_time3",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_fine_time4,         UINT32,\
                    "vme_v1751_fine_time4",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_fine_time5,         UINT32,\
                    "vme_v1751_fine_time5",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_fine_time6,         UINT32,\
                    "vme_v1751_fine_time6",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_fine_time7,         UINT32,\
                    "vme_v1751_fine_time7",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_fine_time8,         UINT32,\
                    "vme_v1751_fine_time8",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_short1,         UINT32,\
                    "vme_v1751_q_short1",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_short2,         UINT32,\
                    "vme_v1751_q_short2",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_short3,         UINT32,\
                    "vme_v1751_q_short3",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_short4,         UINT32,\
                    "vme_v1751_q_short4",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_short5,         UINT32,\
                    "vme_v1751_q_short5",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_short6,         UINT32,\
                    "vme_v1751_q_short6",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_short7,         UINT32,\
                    "vme_v1751_q_short7",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_short8,         UINT32,\
                    "vme_v1751_q_short8",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_long1,         UINT32,\
                    "vme_v1751_q_long1",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_long2,         UINT32,\
                    "vme_v1751_q_long2",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_long3,         UINT32,\
                    "vme_v1751_q_long3",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_long4,         UINT32,\
                    "vme_v1751_q_long4",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_long5,         UINT32,\
                    "vme_v1751_q_long5",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_long6,         UINT32,\
                    "vme_v1751_q_long6",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_long7,         UINT32,\
                    "vme_v1751_q_long7",0/*flags*/); \
  EXT_STR_ITEM_INFO2    (ok,si,offset,struct_t,printerr,\
                     vme_v1751_q_long8,         UINT32,\
                    "vme_v1751_q_long8",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace1,         UINT32,\
                    "vme_v1751_sample_trace1",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace1I,        UINT32,\
                    "vme_v1751_sample_trace1I",        "vme_v1751_sample_trace1",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace1v,        UINT32,\
                    "vme_v1751_sample_trace1v",        "vme_v1751_sample_trace1",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace2,         UINT32,\
                    "vme_v1751_sample_trace2",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace2I,        UINT32,\
                    "vme_v1751_sample_trace2I",        "vme_v1751_sample_trace2",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace2v,        UINT32,\
                    "vme_v1751_sample_trace2v",        "vme_v1751_sample_trace2",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace3,         UINT32,\
                    "vme_v1751_sample_trace3",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace3I,        UINT32,\
                    "vme_v1751_sample_trace3I",        "vme_v1751_sample_trace3",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace3v,        UINT32,\
                    "vme_v1751_sample_trace3v",        "vme_v1751_sample_trace3",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace4,         UINT32,\
                    "vme_v1751_sample_trace4",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace4I,        UINT32,\
                    "vme_v1751_sample_trace4I",        "vme_v1751_sample_trace4",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace4v,        UINT32,\
                    "vme_v1751_sample_trace4v",        "vme_v1751_sample_trace4",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace5,         UINT32,\
                    "vme_v1751_sample_trace5",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace5I,        UINT32,\
                    "vme_v1751_sample_trace5I",        "vme_v1751_sample_trace5",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace5v,        UINT32,\
                    "vme_v1751_sample_trace5v",        "vme_v1751_sample_trace5",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace6,         UINT32,\
                    "vme_v1751_sample_trace6",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace6I,        UINT32,\
                    "vme_v1751_sample_trace6I",        "vme_v1751_sample_trace6",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace6v,        UINT32,\
                    "vme_v1751_sample_trace6v",        "vme_v1751_sample_trace6",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace7,         UINT32,\
                    "vme_v1751_sample_trace7",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace7I,        UINT32,\
                    "vme_v1751_sample_trace7I",        "vme_v1751_sample_trace7",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace7v,        UINT32,\
                    "vme_v1751_sample_trace7v",        "vme_v1751_sample_trace7",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace8,         UINT32,\
                    "vme_v1751_sample_trace8",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace8I,        UINT32,\
                    "vme_v1751_sample_trace8I",        "vme_v1751_sample_trace8",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_trace8v,        UINT32,\
                    "vme_v1751_sample_trace8v",        "vme_v1751_sample_trace8",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp11,         UINT32,\
                    "vme_v1751_sample_dp11",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp11I,        UINT32,\
                    "vme_v1751_sample_dp11I",        "vme_v1751_sample_dp11",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp11v,        UINT32,\
                    "vme_v1751_sample_dp11v",        "vme_v1751_sample_dp11",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp12,         UINT32,\
                    "vme_v1751_sample_dp12",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp12I,        UINT32,\
                    "vme_v1751_sample_dp12I",        "vme_v1751_sample_dp12",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp12v,        UINT32,\
                    "vme_v1751_sample_dp12v",        "vme_v1751_sample_dp12",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp13,         UINT32,\
                    "vme_v1751_sample_dp13",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp13I,        UINT32,\
                    "vme_v1751_sample_dp13I",        "vme_v1751_sample_dp13",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp13v,        UINT32,\
                    "vme_v1751_sample_dp13v",        "vme_v1751_sample_dp13",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp14,         UINT32,\
                    "vme_v1751_sample_dp14",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp14I,        UINT32,\
                    "vme_v1751_sample_dp14I",        "vme_v1751_sample_dp14",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp14v,        UINT32,\
                    "vme_v1751_sample_dp14v",        "vme_v1751_sample_dp14",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp15,         UINT32,\
                    "vme_v1751_sample_dp15",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp15I,        UINT32,\
                    "vme_v1751_sample_dp15I",        "vme_v1751_sample_dp15",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp15v,        UINT32,\
                    "vme_v1751_sample_dp15v",        "vme_v1751_sample_dp15",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp16,         UINT32,\
                    "vme_v1751_sample_dp16",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp16I,        UINT32,\
                    "vme_v1751_sample_dp16I",        "vme_v1751_sample_dp16",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp16v,        UINT32,\
                    "vme_v1751_sample_dp16v",        "vme_v1751_sample_dp16",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp17,         UINT32,\
                    "vme_v1751_sample_dp17",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp17I,        UINT32,\
                    "vme_v1751_sample_dp17I",        "vme_v1751_sample_dp17",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp17v,        UINT32,\
                    "vme_v1751_sample_dp17v",        "vme_v1751_sample_dp17",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp18,         UINT32,\
                    "vme_v1751_sample_dp18",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp18I,        UINT32,\
                    "vme_v1751_sample_dp18I",        "vme_v1751_sample_dp18",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp18v,        UINT32,\
                    "vme_v1751_sample_dp18v",        "vme_v1751_sample_dp18",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp21,         UINT32,\
                    "vme_v1751_sample_dp21",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp21I,        UINT32,\
                    "vme_v1751_sample_dp21I",        "vme_v1751_sample_dp21",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp21v,        UINT32,\
                    "vme_v1751_sample_dp21v",        "vme_v1751_sample_dp21",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp22,         UINT32,\
                    "vme_v1751_sample_dp22",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp22I,        UINT32,\
                    "vme_v1751_sample_dp22I",        "vme_v1751_sample_dp22",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp22v,        UINT32,\
                    "vme_v1751_sample_dp22v",        "vme_v1751_sample_dp22",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp23,         UINT32,\
                    "vme_v1751_sample_dp23",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp23I,        UINT32,\
                    "vme_v1751_sample_dp23I",        "vme_v1751_sample_dp23",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp23v,        UINT32,\
                    "vme_v1751_sample_dp23v",        "vme_v1751_sample_dp23",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp24,         UINT32,\
                    "vme_v1751_sample_dp24",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp24I,        UINT32,\
                    "vme_v1751_sample_dp24I",        "vme_v1751_sample_dp24",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp24v,        UINT32,\
                    "vme_v1751_sample_dp24v",        "vme_v1751_sample_dp24",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp25,         UINT32,\
                    "vme_v1751_sample_dp25",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp25I,        UINT32,\
                    "vme_v1751_sample_dp25I",        "vme_v1751_sample_dp25",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp25v,        UINT32,\
                    "vme_v1751_sample_dp25v",        "vme_v1751_sample_dp25",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp26,         UINT32,\
                    "vme_v1751_sample_dp26",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp26I,        UINT32,\
                    "vme_v1751_sample_dp26I",        "vme_v1751_sample_dp26",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp26v,        UINT32,\
                    "vme_v1751_sample_dp26v",        "vme_v1751_sample_dp26",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp27,         UINT32,\
                    "vme_v1751_sample_dp27",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp27I,        UINT32,\
                    "vme_v1751_sample_dp27I",        "vme_v1751_sample_dp27",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp27v,        UINT32,\
                    "vme_v1751_sample_dp27v",        "vme_v1751_sample_dp27",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp28,         UINT32,\
                    "vme_v1751_sample_dp28",2000,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp28I,        UINT32,\
                    "vme_v1751_sample_dp28I",        "vme_v1751_sample_dp28",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     vme_v1751_sample_dp28v,        UINT32,\
                    "vme_v1751_sample_dp28v",        "vme_v1751_sample_dp28",0/*flags*/); \
  \
} while (0);

#endif/*__GUARD_H101_VME_EXT_H101_VME_H__*/

/*******************************************************/

  // EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,
  //                    vme_qdc_n,                       UINT32,
  //                   "vme_qdc_n",32,0/*flags*/); 
  // EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,
  //                    vme_qdc_nI,                      UINT32,
  //                   "vme_qdc_nI",                      "vme_qdc_n",0/*flags*/); 
  // EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,
  //                    vme_qdc_data,                    UINT32,
  //                   "vme_qdc_data",                    "vme_qdc_n",0/*flags*/); 
