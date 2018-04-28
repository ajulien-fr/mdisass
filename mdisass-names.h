#ifndef __MDISASS_NAMES_H__
#define __MDISASS_NAMES_H__

// Registers
extern const char *names_r8[];
extern const char *names_r16[];
extern const char *names_r32[];

// 32-bit && 16-bit ModR/M Byte
extern const char *names_rm_32b[8];
extern const char *names_rm_16b[8];

extern const char *names_mod_11[6][8]; // Multi-dimensional Array

// 32-bit SIB Byte
extern const char *names_index[4][8];
extern const char *names_base[8];

#endif // __MDISASS_NAMES_H__

