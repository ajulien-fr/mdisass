#include "mdisass.h"

void print_help(char *name);
int str2hex(char **buf, unsigned int *len, char *arg);

unsigned char *disass_init(int argc, char **argv, disass_data *data)
{
    int opt;
    char *buf = NULL;
    unsigned int len = 0;

    if (argc == 1) return NULL;

    while ((opt = getopt(argc, argv, "hs:")) != -1) {
        switch (opt) {
            case 'h':
                print_help(argv[0]);
                exit(0);
            case 's':
                if (str2hex(&buf, &len, optarg) == -1) {
                    disass_error("unable to convert the string to disass in hexadecimal");
                    return NULL;
                }
                break;
            default:	/* '?' */
                print_help(argv[0]);
                return NULL;
        }
    }

    if ((buf == NULL) && (*argv[optind] == '-')) {
        if ((len = getline(&buf, (size_t *) &len, stdin)) == -1) {
            disass_error("unable to get the string to disass");
            return NULL;
        }
    }

    memset(data, 0, sizeof(disass_data));

    data->code = (disass_code *) buf;
    data->size = len;

    return (unsigned char *)buf;
}

int str2hex(char **buf, unsigned int *len, char *arg)
{
    char *src = arg;
    unsigned int src_len = strlen(src);
    char *dst;
    unsigned int value;

    for (unsigned int i = 0; i < src_len; i++) {
        if (!isxdigit(src[i])) {
            disass_error("the string to disass is not in hexadecimal");
            return -1;
        }
    }

    if ((src_len % 2) != 0) {
        disass_error("the length of the string to disass have to be a multiple of 2");
        return -1;
    }

    *len = src_len / 2;

    *buf = calloc(src_len / 2 + 1, sizeof(unsigned char));

    dst = *buf;

    while (*src && (sscanf(src, "%2x", &value) == 1)) {
        *dst = (unsigned char)value;
        src += 2;
        dst++;
    }

    return 0;
}

void print_help(char *name)
{
    printf("%s -h for print this help.\n", name);
    printf("%s - for disass from stdin.\n", name);
    printf("%s -s <string> for disass from string in argument.\n", name);
}

