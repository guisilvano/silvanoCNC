#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "gcode.h"

#define VERSION "0.0.1 alpha"

int main(int argc, char **argv)
{
    char *path_to_file;
    
    /* Stopwatvh used to show progress time */
    struct timeval start, stop;
    int milsec;		/* Time in milliseconds */

    printf("Silvano's CNC - V. %s for %s\n", VERSION, OS);

    /* If path is not specified from cmd line */
    /* TODO: use GNU's getopt to parse arguments */
    if (argc > 1) {
	path_to_file = argv[1];
    } else {
	char path[128];
	
	printf("Path to file: ");
	scanf("%s",path);
	
	path_to_file = path;
    }
    
    FILE * f=fopen(path_to_file, "r");

    if (f == NULL) {
	perror("ERROR");
	exit(errno);
    }
    
    printf("Checking file... ");

    /* Beta feature: Checks for unimplemented instructions */
    check_instructions(f);
    
    printf("Valid file format.\n");
    printf("Begin.\n");

    /* Starts stopwatch */
    gettimeofday(&start, NULL);

    begin_print(f);
    
    /* Stops stopwatch */
    gettimeofday(&stop, NULL);
    
    /* Calculates time in miliseconds */
    milsec = (int) (1000 * (stop.tv_sec - start.tv_sec)
	    + (stop.tv_usec - start.tv_usec) / 1000);
    
    printf("Printing complete after %d milliseconds!", milsec);

    return 0;
}
