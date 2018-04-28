#include "../mdisass.h"

bool has_opsize_pfx(list_head *pfx_list)
{
    list_head *list;

    list_for_each(list, pfx_list)
    {
        list_pfx_entry *entry = (list_pfx_entry *)list;

        if (entry->pf == 0x66)
        {
            return true;
        }
    }

    return false;
}

bool has_addrsize_pfx(list_head *pfx_list)
{
    list_head *list;

    list_for_each(list, pfx_list)
    {
        list_pfx_entry *entry = (list_pfx_entry *)list;

        if (entry->pf == 0x67)
        {
            return true;
        }
    }

    return false;
}

