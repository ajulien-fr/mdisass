#include "../mdisass.h"

list_head * push_ES(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", "push es");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we leave

    return list_insn;
}

list_head * push_CS(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", "push cs");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we leave

    return list_insn;
}

list_head * push_SS(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", "push ss");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we leave

    return list_insn;
}

list_head * push_DS(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", "push ds");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we leave

    return list_insn;
}

list_head * push_eAX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "push ax" : "push eax");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * push_eCX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "push cx" : "push ecx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * push_eDX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "push dx" : "push edx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * push_eBX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "push bx" : "push ebx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * push_eSP(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "push sp" : "push esp");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * push_eBP(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "push bp" : "push ebp");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * push_eSI(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "push si" : "push esi");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * push_eDI(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "push di" : "push edi");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * push_Ivs(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s ", "push");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we go to the addr

    if (has_opsize_pfx(list_pfx)) {
        if (!add_entry_addr16(data, list_insn, "word 0x%hx", &data->code->val16)) return NULL;
        fetch_data(data, sizeof(int16_t)); // we leave the addr16
    }

    else {
        if (!add_entry_addr32(data, list_insn, "dword 0x%x", &data->code->val32)) return NULL;
        fetch_data(data, sizeof(int32_t)); // we leave the addr32
    }

    return list_insn;
}

