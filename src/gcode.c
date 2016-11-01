#include "gcode.h"
#include <stdbool.h>

/*
 * Reads the first string in each line of the file.
 *
 * Returns 'false' if string is not declared in 'operators'
 */
void check_instructions(FILE * f, char op[][4], int total){
    /*file buffer*/
    char buffer[4];
    int line = 1;

    while (fscanf(f,"%s%*[^\n]",buffer) == 1){
	bool try = false;

	for(int i=0;i<total;i++){
	    if (strcmp(buffer, op[i]) == 0){
		try = true;
		line++;
		break;
	    } else {
		try = false;
	    }
	}

	/*checks invalid operation*/
	if (try == false){
	    errno = 38;
	    printf("Invalid operation on line %d: %s",
		    line, buffer);
	    fflush(stdout);
	    perror("\nERROR");
	    exit(errno);
	}
    }
    
    if (!feof(f)){
	errno = 5;
	fflush(stdout);
	perror("\nERROR");
	exit(errno);
    }
    
    printf("Valid file format.\n");
    return;
}
