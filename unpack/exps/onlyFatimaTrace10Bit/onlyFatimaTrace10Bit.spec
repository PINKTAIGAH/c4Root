// -*- C++ -*-
#include "../../common/vme_caen_v1751_dpppsd_trace10bit.spec"


SUBEVENT(vme_subev_qdc){
    v1751 = VME_CAEN_V1751_DPPPSD(geom=6);
}

EVENT
{
  vme = vme_subev_qdc(procid=70);
  //ignore_unknown_subevent;
}
