/*
 * Detects user operating system
 * based on compilation flags
 */

#if defined (__gnu_linux__)
#define OS "GNU/Linux"

#elif defined (__APPLE__)
#define OS "OSx"

#elif defined (_WIN32)
#define OS "Windows x86"

#elif defined (_WIN64)
#define OS "Windows x64"

#else
#define OS "unknown OS"

#endif

/*
 * Define g-code libraries
 */

#ifndef __GCODE
#define __GCODE

#include <stdio.h>

extern int errno;

void check_instructions(FILE * f);
void begin_print(FILE * f);
void begin_operation(FILE * f, char op[]);

#endif
