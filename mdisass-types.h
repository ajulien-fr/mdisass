#ifndef __MDISASS_TYPES_H__
#define __MDISASS_TYPES_H__

typedef struct list_head {
    struct list_head *next, *prev;
} list_head;

enum { TYPE_STR, TYPE_INT8, TYPE_INT16, TYPE_INT32, TYPE_ADDR8, TYPE_ADDR16, TYPE_ADDR32, TYPE_REL8, TYPE_REL16, TYPE_REL32 };
enum { MODRM_32b, MODRM_16b };
enum { MOD_11_8b, MOD_11_16b, MOD_11_32b };

typedef struct {
    struct list_head list;
    const char *format;
    int type;
    const void *value;
} list_insn_entry;

typedef struct {
    struct list_head list;
    uint8_t pf;
    uint32_t pos;
} list_pfx_entry;

typedef union {
    uint8_t b;

    int8_t val8;
    int16_t val16;
    int32_t val32;

    struct {
        uint8_t rm:3;
        uint8_t reg:3;
        uint8_t mod:2;
    };

    struct {
        uint8_t base:3;
        uint8_t index:3;
        uint8_t ss:2;
    };
} disass_code;

typedef struct {
    disass_code *code;
    uint32_t address;
    uint32_t size;
    uint32_t read;
} disass_data;

typedef struct
{
    list_head * (*disass_fn)(disass_data *data, list_head *insn_list, list_head *pfx_list);
} disass_insn;

#endif // __MDISASS_TYPES_H__

