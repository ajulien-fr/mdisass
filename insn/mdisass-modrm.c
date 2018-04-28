#include "../mdisass.h"

list_head * mod_00_32b(disass_data *data, list_head *insn_list, list_head *pfx_list);
list_head * mod_01_32b(disass_data *data, list_head *insn_list, list_head *pfx_list);
list_head * mod_10_32b(disass_data *data, list_head *insn_list, list_head *pfx_list);
list_head * mod_11_32b(disass_data *data, list_head *insn_list, list_head *pfx_list);

list_head * mod_00_16b(disass_data *data, list_head *insn_list, list_head *pfx_list);
list_head * mod_01_16b(disass_data *data, list_head *insn_list, list_head *pfx_list);
list_head * mod_10_16b(disass_data *data, list_head *insn_list, list_head *pfx_list);
list_head * mod_11_16b(disass_data *data, list_head *insn_list, list_head *pfx_list);

list_head * (*modrm[2][3])(disass_data *data, list_head *insn_list, list_head *pfx_list) =
{
    { mod_00_32b, mod_01_32b, mod_10_32b },
    { mod_00_16b, mod_01_16b, mod_10_16b },
};

list_head * mod_00_32b(disass_data *data, list_head *insn_list, list_head *pfx_list)
{
    if (data->code->rm == 4) {
        // 32-bit SIB Byte

        // we go to the SIB Byte
        if (!fetch_data(data, sizeof(int8_t))) return NULL;

        if (data->code->base == 5) {
            // disp32
            add_entry_str(insn_list, "[%s", names_index[data->code->ss][data->code->index]);

            if (data->code->index != 4) add_entry_str(insn_list, "%s", (data->code->val32 < 0) ? "-" : "+");

            // we go to the disp32
            if (!fetch_data(data, sizeof(int8_t))) return NULL;

            if (!add_entry_int32(data, insn_list, "0x%x]", &data->code->val32)) return NULL;

            if (!fetch_data(data, sizeof(int32_t))) return NULL;
        }

        else {
            add_entry_str(insn_list, "[%s", names_base[data->code->base]);
            add_entry_str(insn_list, "%s", (data->code->index != 4) ? "+" : "");
            add_entry_str(insn_list, "%s]", names_index[data->code->ss][data->code->index]);

            if (!fetch_data(data, sizeof(int8_t))) return NULL;
        }
    }

    else if (data->code->rm == 5) {
        // disp32

        // we go to the disp32
        if (!fetch_data(data, sizeof(int8_t))) return NULL;

        if (!add_entry_addr32(data, insn_list, "[dword 0x%x]", &data->code->val32)) return NULL;

        if (!fetch_data(data, sizeof(int32_t))) return NULL;
    }

    else {
        add_entry_str(insn_list, "[%s]", names_rm_32b[data->code->rm]);

        if (!fetch_data(data, sizeof(int8_t))) return NULL;
    }

    return insn_list;
}

list_head * mod_01_32b(disass_data *data, list_head *insn_list, list_head *pfx_list)
{
    if (data->code->rm == 4) {
        // 32-bit SIB Byte

        // we go to the SIB Byte
        if (!fetch_data(data, sizeof(int8_t))) return NULL;

        add_entry_str(insn_list, "[%s", names_base[data->code->base]);
        add_entry_str(insn_list, "%s", (data->code->index != 4) ? "+" : "");
        add_entry_str(insn_list, "%s", names_index[data->code->ss][data->code->index]);
        add_entry_str(insn_list, "%s", (data->code->val32 < 0) ? "-" : "+");

        // we go to the disp8
        if (!fetch_data(data, sizeof(int8_t))) return NULL;

        if (!add_entry_int8(data, insn_list, "0x%hhx]", &data->code->val8)) return NULL;
    }

    else {
        add_entry_str(insn_list, "[%s", names_rm_32b[data->code->rm]);
        add_entry_str(insn_list, "%s", (data->code->val32 < 0) ? "-" : "+");

        // we go to the disp8
        if (!fetch_data(data, sizeof(int8_t))) return NULL;

        if (!add_entry_int8(data, insn_list, "0x%hhx]", &data->code->val8)) return NULL;
    }

    if (!fetch_data(data, sizeof(int8_t))) return NULL;

    return insn_list;
}

list_head * mod_10_32b(disass_data *data, list_head *insn_list, list_head *pfx_list)
{
    if (data->code->rm == 4) {
        // 32-bit SIB Byte

        // we go to the SIB Byte
        if (!fetch_data(data, sizeof(int8_t))) return NULL;

        add_entry_str(insn_list, "[%s", names_base[data->code->base]);
        add_entry_str(insn_list, "%s", (data->code->index != 4) ? "+" : "");
        add_entry_str(insn_list, "%s", names_index[data->code->ss][data->code->index]);
        add_entry_str(insn_list, "%s", (data->code->val32 < 0) ? "-" : "+");

        // we go to the disp32
        if (!fetch_data(data, sizeof(int8_t))) return NULL;

        if (!add_entry_int32(data, insn_list, "0x%x]", &data->code->val32)) return NULL;
    }

    else {
        add_entry_str(insn_list, "[%s", names_rm_32b[data->code->rm]);
        add_entry_str(insn_list, "%s", (data->code->val32 < 0) ? "-" : "+");

        // we go to the disp8
        if (!fetch_data(data, sizeof(int8_t))) return NULL;

        if (!add_entry_int32(data, insn_list, "0x%x]", &data->code->val32)) return NULL;
    }

    if (!fetch_data(data, sizeof(int32_t))) return NULL;

    return insn_list;
}

list_head * mod_00_16b(disass_data *data, list_head *insn_list, list_head *pfx_list)
{
    if (data->code->rm == 6) {
        add_entry_str(insn_list, "%s", "[word ");

        if (!fetch_data(data, sizeof(int8_t))) return NULL;

        if (!add_entry_int16(data, insn_list, "0x%hx]", &data->code->val16)) return NULL;

        if (!fetch_data(data, sizeof(int16_t))) return NULL;
    }

    else {
        add_entry_str(insn_list, "[%s]", names_rm_16b[data->code->rm]);

        if (!fetch_data(data, sizeof(int8_t))) return NULL;
    }

    return insn_list;
}

list_head * mod_01_16b(disass_data *data, list_head *insn_list, list_head *pfx_list)
{
    add_entry_str(insn_list, "[%s", names_rm_16b[data->code->rm]);
    add_entry_str(insn_list, "%s", (data->code->val32 < 0) ? "-" : "+");

    if (!fetch_data(data, sizeof(int8_t))) return NULL;

    if (!add_entry_int8(data, insn_list, "0x%hhx]", &data->code->val8)) return NULL;

    if (!fetch_data(data, sizeof(int8_t))) return NULL;

    return insn_list;
}

list_head * mod_10_16b(disass_data *data, list_head *insn_list, list_head *pfx_list)
{
    add_entry_str(insn_list, "[%s", names_rm_16b[data->code->rm]);
    add_entry_str(insn_list, "%s", (data->code->val32 < 0) ? "-" : "+");

    if (!fetch_data(data, sizeof(int8_t))) return NULL;

    if (!add_entry_int16(data, insn_list, "0x%hx]", &data->code->val16)) return NULL;

    if (!fetch_data(data, sizeof(int16_t))) return NULL;

    return insn_list;
}

