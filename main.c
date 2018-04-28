#include "mdisass.h"

int main(int argc, char *argv[])
{
    list_head list;
    unsigned char *buf;
    disass_data data;
    disass_code *code;
    uint32_t read = 0;
    int ret = 0;

    buf = disass_init(argc, argv, &data);

    if (buf == NULL) {
        ret = 1;
        goto end;
    }

    INIT_LIST_HEAD(&list);

    code = data.code;

    while (read < data.size) {
        list_head *insn = get_insn(&data, &list);

        if (insn != NULL) print_insn(&data, code, insn);

        data.address += data.read;
        code = data.code;
        read += data.read;
        data.read = 0;

        list_free(&list);
    }

    list_free(&list);

end:
    if (buf != NULL) free(buf);

    return ret;
}

