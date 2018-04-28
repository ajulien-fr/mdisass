#ifndef __MDISASS_INSN_H__
#define __MDISASS_INSN_H__

#include "../mdisass-types.h"

list_head * add_Eb_Gb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * add_Ev_Gv(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * add_Gb_Eb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * add_Gv_Ev(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * add_AL_Ib(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * add_eAX_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * push_ES(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_ES(disass_data *data, list_head *list_insn, list_head *list_pfx);

#endif // __MDISASS_INSN_H__

