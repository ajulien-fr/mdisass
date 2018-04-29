#include "../mdisass.h"

list_head * arpl(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    int reg;

    add_entry_str(list_insn, "%s ", "arpl");

    fetch_data(data, sizeof(int8_t)); // we go to the modrm byte

    reg = data->code->reg; // we save reg before fetch data in modrm[][]();

    if (data->code->mod != 3) {
        if (!has_addrsize_pfx(list_pfx)) {
            if (!modrm[MODRM_32b][data->code->mod](data, list_insn, list_pfx)) return NULL;
        }

        else {
            if (!modrm[MODRM_16b][data->code->mod](data, list_insn, list_pfx)) return NULL;
        }
    }

    else {
        add_entry_str(list_insn, "%s", names_mod_11[MOD_11_16b][data->code->rm]);

        fetch_data(data, sizeof(int8_t)); // we leave the modrm byte
    }

    add_entry_str(list_insn, ",%s", names_r16[reg]);

    return list_insn;
}
