#include "mdisass.h"

void check_prefixes(disass_data *data, list_head *pfx_list);
bool is_two_byte_insn(uint8_t b);
bool is_group(uint8_t b);
bool has_secondary_opcode(uint8_t po);

list_head * get_insn(disass_data *data, list_head *insn_list)
{
    list_head pfx_list;

    INIT_LIST_HEAD(&pfx_list);

    check_prefixes(data, &pfx_list);

    if (is_two_byte_insn(data->code->b))
    {
        printf("WARNING: %.2X is a two byte insn, it's not yet implemented.\n", data->code->b);
        fetch_data(data, sizeof(uint8_t));
        return NULL;
    }

    if (is_group(data->code->b))
    {
        printf("WARNING: %.2X is group insn, it's not yet implemented.\n", data->code->b);
        fetch_data(data, sizeof(uint8_t));
        return NULL;
    }

    if (has_secondary_opcode(data->code->b))
    {
        printf("WARNING: %.2X have secondary opcode, it's not yet implemented.\n", data->code->b);
        fetch_data(data, sizeof(uint8_t));
        return NULL;
    }

    disass_insn *insn; 
    insn = &one_byte_insn[data->code->b];

    return insn->disass_fn(data, insn_list, &pfx_list);
}

void check_prefixes(disass_data *data, list_head *pfx_list)
{
    bool end = false;
    list_pfx_entry *entry;

    while (!end)
    {
        switch (data->code->b)
        {
            case 0x26:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0x2E:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0x36:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0x3E:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0x64:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0x65:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0x66:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0x67:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0x9B:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0xF0:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0xF2:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            case 0xF3:
                entry = malloc(sizeof(list_pfx_entry));
                entry->pf = data->code->b;
                entry->pos = data->read;
                list_add_tail(&entry->list, pfx_list);
                fetch_data(data, sizeof(uint8_t));
                break;

            default:
                end = true;
                break;
        }
    }
}

bool is_two_byte_insn(uint8_t b)
{
    return (b == 0x0F);
}

bool is_group(uint8_t b)
{
    switch (b)
    {
        case 0x80:
        case 0x81:
        case 0x82:
        case 0x83:
        case 0x8F:
        case 0xC0:
        case 0xC1:
        case 0xC6:
        case 0xC7:
        case 0xD0:
        case 0xD1:
        case 0xD2:
        case 0xD3:
        case 0xD8:
        case 0xD9:
        case 0xDA:
        case 0xDB:
        case 0xDC:
        case 0xDD:
        case 0xDE:
        case 0xDF:
        case 0xF6:
        case 0xF7:
        case 0xFE:
        case 0xFF:
            return true;

        default:
            return false;
    }
}

bool has_secondary_opcode(uint8_t po)
{
    switch (po)
    {
        case 0xD4:
        case 0xD5:
            return true;

        default:
            return false;
    }
}

