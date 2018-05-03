#include "../mdisass.h"

list_head * imul_Gv_Ev_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s ", "imul");

    fetch_data(data, sizeof(int8_t)); // we go to the modrm byte

    add_entry_str(list_insn, "%s,", (!has_opsize_pfx(list_pfx)) ? names_r32[data->code->reg] : names_r16[data->code->reg]);

    if (data->code->mod != 3) {
        if (!has_addrsize_pfx(list_pfx)) {
            if (!modrm[MODRM_32b][data->code->mod](data, list_insn, list_pfx)) return NULL;
        }

        else {
            if (!modrm[MODRM_16b][data->code->mod](data, list_insn, list_pfx)) return NULL;
        }
    }

    else {
        add_entry_str(list_insn, "%s", (!has_opsize_pfx(list_pfx)) ? names_mod_11[MOD_11_32b][data->code->rm] : names_mod_11[MOD_11_16b][data->code->rm]);

        fetch_data(data, sizeof(int8_t)); // we leave the modrm byte
    }

    if (has_opsize_pfx(list_pfx)) {
        if (!add_entry_addr16(data, list_insn, ",word 0x%hx", &data->code->val16)) return NULL;
        fetch_data(data, sizeof(int16_t)); // we leave the addr16
    }

    else {
        if (!add_entry_addr32(data, list_insn, ",dword 0x%x", &data->code->val32)) return NULL;
        fetch_data(data, sizeof(int32_t)); // we leave the addr32
    }

    return list_insn;
}

