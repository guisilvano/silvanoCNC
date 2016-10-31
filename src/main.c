#include "gcode.h"

#define VERSION "0.0.1"

char operators[][4] = {
    "(",
    
    "G00", "G01", "G02", "G03", "G20", "G64", "G90", 
    
    "M03", "M05", "M06", "M30"
};
size_t total_operators = sizeof(operators)/sizeof(operators[0]);

int main(int argc, char *argv[]){
    bool check;

    printf("Silvano's CNC - V. %s\n",VERSION);

    /*
     * If path is not specified from cmd line
     */
    if (argc == 1){
	char path[128];
	printf("Path to file: ");
	scanf("%s",path);
	argv[1]=path;
    }

    printf("Checking file... ");

    FILE* f=fopen(argv[1],"r");

    if (f == NULL){
	printf("Unable to read file.");
	return -1;
    }
    
    /*
     * Beta feature: Checks for uninplemented instructions
     */
    check = check_instructions(f, operators, total_operators);
    if(check == false) return -2;

    return 0;
}
