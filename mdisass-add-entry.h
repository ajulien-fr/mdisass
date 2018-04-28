#ifndef __ADD_INSN_ENTRY_H__
#define __ADD_INSN_ENTRY_H__

#include "mdisass-types.h"

void add_entry_str(list_head *insn_list, const char *format, const void *value);
bool add_entry_int8(disass_data *data, list_head *insn_list, const char *format, const void *value);
bool add_entry_int16(disass_data *data, list_head *insn_list, const char *format, const void *value);
bool add_entry_int32(disass_data *data, list_head *insn_list, const char *format, const void *value);
bool add_entry_addr8(disass_data *data, list_head *insn_list, const char *format, const void *value);
bool add_entry_addr16(disass_data *data, list_head *insn_list, const char *format, const void *value);
bool add_entry_addr32(disass_data *data, list_head *insn_list, const char *format, const void *value);
bool add_entry_rel8(disass_data *data, list_head *insn_list, const char *format, const void *value);
bool add_entry_rel16(disass_data *data, list_head *insn_list, const char *format, const void *value);
bool add_entry_rel32(disass_data *data, list_head *insn_list, const char *format, const void *value);

#endif // __ADD_INSN_ENTRY_H__

