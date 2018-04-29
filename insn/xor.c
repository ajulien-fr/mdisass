#include "../mdisass.h"

list_head * xor_Eb_Gb(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    int reg;

    add_entry_str(list_insn, "%s ", "xor");

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
        add_entry_str(list_insn, "%s", names_mod_11[MOD_11_8b][data->code->rm]);

        fetch_data(data, sizeof(int8_t)); // we leave the modrm byte
    }

    add_entry_str(list_insn, ",%s", names_r8[reg]);

    return list_insn;
}

list_head * xor_Ev_Gv(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    int reg;

    add_entry_str(list_insn, "%s ", "xor");

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
        add_entry_str(list_insn, "%s", (!has_opsize_pfx(list_pfx)) ? names_mod_11[MOD_11_32b][data->code->rm] : names_mod_11[MOD_11_16b][data->code->rm]);

        fetch_data(data, sizeof(int8_t)); // we leave the modrm byte
    }

    add_entry_str(list_insn, ",%s", (!has_opsize_pfx(list_pfx)) ? names_r32[reg] : names_r16[reg]);

    return list_insn;
}

list_head * xor_Gb_Eb(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s ", "xor");

    fetch_data(data, sizeof(int8_t)); // we go to the modrm byte

    add_entry_str(list_insn, "%s,", names_r8[data->code->reg]);

    if (data->code->mod != 3) {
        if (!has_addrsize_pfx(list_pfx)) {
            if (!modrm[MODRM_32b][data->code->mod](data, list_insn, list_pfx)) return NULL;
        }

        else {
            if (!modrm[MODRM_16b][data->code->mod](data, list_insn, list_pfx)) return NULL;
        }
    }

    else {
        add_entry_str(list_insn, "%s", names_mod_11[MOD_11_8b][data->code->rm]);

        fetch_data(data, sizeof(int8_t)); // we leave the modrm byte
    }

    return list_insn;
}

list_head * xor_Gv_Ev(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s ", "xor");

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

    return list_insn;
}

list_head * xor_AL_Ib(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", "xor al,");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we go to the addr8

    if (!add_entry_addr8(data, list_insn, "0x%hhx", &data->code->val8)) return NULL;

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we leave the addr8

    return list_insn;
}

list_head * xor_eAX_Iv(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s ", "xor");

    if (has_opsize_pfx(list_pfx)) {
        add_entry_str(list_insn, "%s", "ax,");
        if (!fetch_data(data, sizeof(int8_t))) return NULL; // we go to the addr16
        if (!add_entry_addr16(data, list_insn, "0x%hx", &data->code->val16)) return NULL;
        fetch_data(data, sizeof(int16_t)); // we leave the addr16
    }

    else {
        add_entry_str(list_insn, "%s", "eax,");
        if (!fetch_data(data, sizeof(int8_t))) return NULL; // we go to the addr32
        if (!add_entry_addr32(data, list_insn, "0x%x", &data->code->val32)) return NULL;
        fetch_data(data, sizeof(int32_t)); // we leave the addr32
    }

    return list_insn;
}

