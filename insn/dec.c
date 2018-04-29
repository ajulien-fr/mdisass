#include "../mdisass.h"

list_head * dec_eAX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "dec ax" : "dec eax");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * dec_eCX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "dec cx" : "dec ecx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * dec_eDX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "dec dx" : "dec edx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * dec_eBX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "dec bx" : "dec ebx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * dec_eSP(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "dec sp" : "dec esp");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * dec_eBP(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "dec bp" : "dec ebp");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * dec_eSI(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "dec si" : "dec esi");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * dec_eDI(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "dec di" : "dec edi");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

