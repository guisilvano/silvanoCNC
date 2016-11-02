#include "gcode.h"
#include <stdbool.h>

#define OPERATOR_LENGHT 4

char operators[][OPERATOR_LENGHT] = {
    "(",
    "G00", "G01", "G02", "G03", "G20", "G64", "G90", 
    "M03", "M05", "M06", "M30"
};
size_t total_operators = sizeof(operators)/sizeof(operators[0]);

/*
 * Reads the first string in each line of the file.
 *
 * Exit with an error if string is not declared in 'operators'
 * or if there's any trouble opening the file itself.
 */
void check_instructions(FILE * f)
{
    /* File buffer */
    char buffer[OPERATOR_LENGHT];
    int line = 1;

    while (fscanf(f,"%s%*[^\n]",buffer) == 1) {
	bool try = false;

	/* Compares each line's first string to the operators */
	for (int i=0;i<total_operators;i++) {
	    if (strcmp(buffer, operators[i]) == 0) {
		try = true;
		line++;
		
		break;
	    } else {
		try = false;
	    }
	}

	/* Checks for invalid operator */
	if (try == false) {
	    errno = 38;
	    
	    printf("Invalid operation on line %d: %s", line, buffer);
	    fflush(stdout);
	    
	    perror("\nERROR");
	    exit(errno);
	}
    }

    /* Unindentified error: shouldn't ever happen */
    if (!feof(f)) {
	errno = 5;
	fflush(stdout);
	
	perror("\nERROR");
	exit(errno);
    }
    
    printf("Valid file format.\n");
    return;
}
