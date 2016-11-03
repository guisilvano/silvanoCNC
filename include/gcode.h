#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern int errno;

void check_instructions(FILE * f);
void begin_print(FILE * f);
void begin_operation(FILE * f, char op[]);
