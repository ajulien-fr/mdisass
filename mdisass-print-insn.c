#include "mdisass.h"

void print_str(disass_data *data, list_insn_entry *entry);
void print_int8(disass_data *data, list_insn_entry *entry);
void print_int16(disass_data *data, list_insn_entry *entry);
void print_int32(disass_data *data, list_insn_entry *entry);
void print_addr8(disass_data *data, list_insn_entry *entry);
void print_addr16(disass_data *data, list_insn_entry *entry);
void print_addr32(disass_data *data, list_insn_entry *entry);
void print_rel8(disass_data *data, list_insn_entry *entry);
void print_rel16(disass_data *data, list_insn_entry *entry);
void print_rel32(disass_data *data, list_insn_entry *entry);

void (*print_insn_entry[])(disass_data *data, list_insn_entry *entry) =
{
    print_str,

    print_int8,
    print_int16,
    print_int32,

    print_addr8,
    print_addr16,
    print_addr32,

    print_rel8,
    print_rel16,
    print_rel32,
};

void print_insn(disass_data *data, disass_code *code, list_head *insn_list)
{
    list_head *list;

    printf("%.8X  ", data->address);

    for (unsigned int i = 0; i < data->read; i++, code = (disass_code *)((unsigned char *)(code)+sizeof(unsigned char)))
    {
        printf("%.2X", code->b);
    }

    printf("      ");

    list_for_each(list, insn_list)
    {
        list_insn_entry *entry = (list_insn_entry *)list;
        print_insn_entry[entry->type](data, entry);
    }

    printf("\n");
}

void print_str(disass_data *data, list_insn_entry *entry)
{
    char *value = (char *)(entry->value);
    printf(entry->format, value);
}

/*
 * abs = valeur absolue
 * abs(x) = ( x >= 0) ? x : -x
 */

void print_int8(disass_data *data, list_insn_entry *entry)
{
    char value = *(char *)(entry->value);
    printf(entry->format, abs(value));
}

void print_int16(disass_data *data, list_insn_entry *entry)
{
    short int value = *(short int *)(entry->value);
    printf(entry->format, abs(value));
}

void print_int32(disass_data *data, list_insn_entry *entry)
{
    int value = *(int *)(entry->value);
    printf(entry->format, abs(value));
}

/*
 * 0xFFFFFFFF = 1111 1111 1111 1111 1111 1111 1111 1111 = 32 bits
 * 0x0000FFFF = 0000 0000 0000 0000 1111 1111 1111 1111 = 16 bits
 * 0x000000FF = 0000 0000 0000 0000 0000 0000 1111 1111 = 8 bits
 *
 * Something like 0xAARRGGBB (alpha, red, green, blue).
 * By and-ing with 0xFF, you keep just the last part, which is blue.
 */

void print_addr8(disass_data *data, list_insn_entry *entry)
{
    char value = *(char *)(entry->value);
    printf(entry->format, value & 0xFF);
}

void print_addr16(disass_data *data, list_insn_entry *entry)
{
    short int value = *(short int *)(entry->value);
    printf(entry->format, value & 0xFFFF);
}

void print_addr32(disass_data *data, list_insn_entry *entry)
{
    int value = *(int32_t *)(entry->value);
    printf(entry->format, value & 0xFFFFFFFF);
}

void print_rel8(disass_data *data, list_insn_entry *entry)
{
    char value = *(char *)(entry->value);
    printf(entry->format, (data->address + data->read) + value);
}

void print_rel16(disass_data *data, list_insn_entry *entry)
{
    short int value = *(short int *)(entry->value);
    printf(entry->format, (data->address + data->read) + value);
}

void print_rel32(disass_data *data, list_insn_entry *entry)
{
    int value = *(int *)(entry->value);
    printf(entry->format, (data->address + data->read) + value);
}

