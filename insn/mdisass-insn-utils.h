#ifndef __INSN_UTILS_H__
#define __INSN_UTILS_H__

#include "../mdisass-types.h"

bool has_opsize_pfx(list_head *pfx_list);
bool has_addrsize_pfx(list_head *pfx_list);

list_head * (*modrm[2][3])(disass_data *data, list_head *insn_list, list_head *pfx_list);

#endif // __INSN_UTILS_H__

