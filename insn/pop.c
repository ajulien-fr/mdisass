#include "../mdisass.h"

list_head * pop_ES(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", "pop es");

    if (!fetch_data(data, sizeof(int8_t))) return NULL; // we leave

    return list_insn;
}

