#include "mdisass.h"

const char *names_r8[8] = {
    "al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"
};

const char *names_r16[8] = {
    "ax", "cx", "dx", "bx", "sp", "bp", "si", "di"
};

const char *names_r32[8] = {
    "eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"
};

const char *names_rm_32b[8] = {
    "eax", "ecx", "edx", "ebx", NULL, "ebp", "esi", "edi"
};

const char *names_rm_16b[8] = {
    "bx+si", "bx+di", "bx+si", "bp+di", "si", "di", "bp", "bx"
};

const char *names_mod_11[6][8] = {
    {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"},
    {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"},
    {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"},
    {"st0", "st1", "st2", "st3", "st4", "st5", "st6", "st7"},
    {"mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7"},
    {"xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7"}
};

const char *names_index[4][8] = {
    { "eax", "ecx", "edx", "ebx", "", "ebp", "esi", "edi" },
    { "eax*2", "ecx*2", "edx*2", "ebx*2", "", "ebp*2", "esi*2", "edi*2" },
    { "eax*4", "ecx*4", "edx*4", "ebx*4", "", "ebp*4", "esi*4", "edi*4" },
    { "eax*8", "ecx*8", "edx*8", "ebx*8", "", "ebp*8", "esi*8", "edi*8" },
};

const char *names_base[8] = {
    "eax", "ecx", "edx", "ebx", "esp", NULL, "esi", "edi"
};

