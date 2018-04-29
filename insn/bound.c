#include "../mdisass.h"

list_head * bound(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s ", "bound");

    fetch_data(data, sizeof(int8_t)); // we go to the modrm byte

    if (data->code->mod != 3) {
        add_entry_str(list_insn, "%s,", (!has_opsize_pfx(list_pfx)) ? names_r32[data->code->reg] : names_r16[data->code->reg]); 

        if (!has_addrsize_pfx(list_pfx)) {
            if (!modrm[MODRM_32b][data->code->mod](data, list_insn, list_pfx)) return NULL;
        }

        else {
            if (!modrm[MODRM_16b][data->code->mod](data, list_insn, list_pfx)) return NULL;
        }
    }

    else return NULL;

    return list_insn;
}

