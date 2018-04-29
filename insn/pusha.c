#include "../mdisass.h"

list_head * pusha(disass_data *data, list_head *list_insn, list_head *list_pfx)
{
    add_entry_str(list_insn, "%s", has_opsize_pfx(list_pfx) ? "pushaw" : "pusha");

    fetch_data(data, sizeof(int8_t)); // we leave

    return list_insn;
}

