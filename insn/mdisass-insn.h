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

list_head * or_Eb_Gb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * or_Ev_Gv(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * or_Gb_Eb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * or_Gv_Ev(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * or_AL_Ib(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * or_eAX_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * push_CS(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * adc_Eb_Gb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * adc_Ev_Gv(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * adc_Gb_Eb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * adc_Gv_Ev(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * adc_AL_Ib(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * adc_eAX_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * push_SS(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_SS(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * sbb_Eb_Gb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sbb_Ev_Gv(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sbb_Gb_Eb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sbb_Gv_Ev(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sbb_AL_Ib(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sbb_eAX_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * push_DS(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_DS(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * and_Eb_Gb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * and_Ev_Gv(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * and_Gb_Eb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * and_Gv_Ev(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * and_AL_Ib(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * and_eAX_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * daa(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * sub_Eb_Gb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sub_Ev_Gv(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sub_Gb_Eb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sub_Gv_Ev(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sub_AL_Ib(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * sub_eAX_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * das(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * xor_Eb_Gb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * xor_Ev_Gv(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * xor_Gb_Eb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * xor_Gv_Ev(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * xor_AL_Ib(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * xor_eAX_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * aaa(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * cmp_Eb_Gb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * cmp_Ev_Gv(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * cmp_Gb_Eb(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * cmp_Gv_Ev(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * cmp_AL_Ib(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * cmp_eAX_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * aas(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * inc_eAX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * inc_eCX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * inc_eDX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * inc_eBX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * inc_eSP(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * inc_eBP(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * inc_eSI(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * inc_eDI(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * dec_eAX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * dec_eCX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * dec_eDX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * dec_eBX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * dec_eSP(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * dec_eBP(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * dec_eSI(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * dec_eDI(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * push_eAX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * push_eCX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * push_eDX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * push_eBX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * push_eSP(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * push_eBP(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * push_eSI(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * push_eDI(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * pop_eAX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_eCX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_eDX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_eBX(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_eSP(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_eBP(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_eSI(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * pop_eDI(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * pusha(disass_data *data, list_head *list_insn, list_head *list_pfx);
list_head * popa(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * bound(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * arpl(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * push_Ivs(disass_data *data, list_head *list_insn, list_head *list_pfx);

list_head * imul_Gv_Ev_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx);

#endif // __MDISASS_INSN_H__

