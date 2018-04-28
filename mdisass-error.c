#include "mdisass.h"

extern int errno;

void disass_error(char *str)
{
    if (errno != -1) {
        fprintf(stderr, "error: %s - %d - %s\n", str, errno, strerror(errno));
    }
    else {
        fprintf(stderr, "error: %s\n", str);
    }
}
