#include "../mdisass.h"

list_head * pop_ES(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", "pop es");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we leave

    return list_insn;
}

list_head * pop_SS(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", "pop ss");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we leave

    return list_insn;
}

list_head * pop_DS(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", "pop ds");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we leave

    return list_insn;
}

list_head * pop_eAX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "pop ax" : "pop eax");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * pop_eCX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "pop cx" : "pop ecx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * pop_eDX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "pop dx" : "pop edx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * pop_eBX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "pop bx" : "pop ebx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * pop_eSP(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "pop sp" : "pop esp");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * pop_eBP(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "pop bp" : "pop ebp");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * pop_eSI(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "pop si" : "pop esi");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * pop_eDI(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "pop di" : "pop edi");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

