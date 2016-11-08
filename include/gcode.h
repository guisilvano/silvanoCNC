#ifndef _GCODE_
#define _GCODE_

#include <stdio.h>

extern int errno;

void check_instructions(FILE * f);
void begin_print(FILE * f);
void begin_operation(FILE * f, char op[]);

#endif
