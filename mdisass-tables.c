#include "mdisass.h"
#include "insn/mdisass-insn.h"

disass_insn one_byte_insn[] =
{
    { add_Eb_Gb },      // 0x00
    { add_Ev_Gv },      // 0x01
    { add_Gb_Eb },      // 0x02
    { add_Gv_Ev },      // 0x03
    { add_AL_Ib },      // 0x04
    { add_eAX_Iv },     // 0x05
    { push_ES },        // 0x06
    { pop_ES },         // 0x07
};

