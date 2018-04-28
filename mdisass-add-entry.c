#include "mdisass.h"

void add_entry_str(list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_STR;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);
}

bool add_entry_int8(disass_data *data, list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry;

    if (data->size < data->read + sizeof(int8_t)) return false;

    entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_INT8;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);

    return true;
}

bool add_entry_int16(disass_data *data, list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry;

    if (data->size < data->read + sizeof(int16_t)) return false;

    entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_INT16;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);

    return true;
}

bool add_entry_int32(disass_data *data, list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry;

    if (data->size < data->read + sizeof(int32_t)) return false;

    entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_INT32;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);

    return true;
}

bool add_entry_addr8(disass_data *data, list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry;

    if (data->size < data->read + sizeof(int8_t)) return false;

    entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_ADDR8;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);

    return true;
}

bool add_entry_addr16(disass_data *data, list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry;

    if (data->size < data->read + sizeof(int16_t)) return false;

    entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_ADDR16;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);

    return true;
}

bool add_entry_addr32(disass_data *data, list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry;

    if (data->size < data->read + sizeof(int32_t)) return false;

    entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_ADDR32;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);

    return true;
}

bool add_entry_rel8(disass_data *data, list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry;

    if (data->size < data->read + sizeof(int8_t)) return false;

    entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_REL8;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);

    return true;
}

bool add_entry_rel16(disass_data *data, list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry;

    if (data->size < data->read + sizeof(int16_t)) return false;

    entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_REL16;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);

    return true;
}

bool add_entry_rel32(disass_data *data, list_head *list, const char *format, const void *value)
{
    list_insn_entry *entry;

    if (data->size < data->read + sizeof(int32_t)) return false;

    entry = malloc(sizeof(list_insn_entry));

    entry->type = TYPE_REL32;
    entry->format = format;
    entry->value = value;

    list_add_tail(&entry->list, list);

    return true;
}

