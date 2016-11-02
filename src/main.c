#include "gcode.h"

#define VERSION "0.0.1"

int main(int argc, char **argv)
{
    char *path_to_file;
    
    printf("Silvano's CNC - V. %s\n",VERSION);

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

    /* Beta feature: Checks for uninplemented instructions */
    check_instructions(f);

    return 0;
}
