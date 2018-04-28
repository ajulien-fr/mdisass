#ifndef __MDISASS_H__
#define __MDISASS_H__

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#include "mdisass-types.h"
#include "mdisass-list.h"
#include "mdisass-tables.h"
#include "mdisass-names.h"
#include "mdisass-add-entry.h"
#include "insn/mdisass-insn.h"
#include "insn/mdisass-insn-utils.h"

unsigned char * disass_init(int argc, char **argv, disass_data *data);
void disass_error(char *str);
bool fetch_data(disass_data *data, uint32_t size);
list_head * get_insn(disass_data *data, list_head *insn_list);
void print_insn(disass_data *data, disass_code *code, list_head *insn_list);

#endif // __MDISASS_H__

