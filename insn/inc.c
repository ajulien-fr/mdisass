#include "../mdisass.h"

list_head * inc_eAX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "inc ax" : "inc eax");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * inc_eCX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "inc cx" : "inc ecx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * inc_eDX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "inc dx" : "inc edx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * inc_eBX(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "inc bx" : "inc ebx");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * inc_eSP(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "inc sp" : "inc esp");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * inc_eBP(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "inc bp" : "inc ebp");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * inc_eSI(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "inc si" : "inc esi");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

list_head * inc_eDI(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "inc di" : "inc edi");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

