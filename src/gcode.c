#include "gcode.h"

/*
 * Reads the first string in each line of the file.
 *
 * Returns 'false' if string is not declared in 'operators'
 */
bool check_instructions(FILE * f, char op[][4], int total){
    /*file buffer*/
    char buffer[255];
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
	    printf("Invalid operation on line %d: %s",
		    line, buffer);
	    printf("\nTerminating!");
	    return false;
	}
    }
    if (feof(f)){
	printf("Valid file format.\n");
	return true;
    } else {
	printf("Unknown fatal error! Aborting!");
	return false;
    }
}
