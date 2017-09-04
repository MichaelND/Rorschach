#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <unistd.h>

/* Globals */
char * PROGRAM_NAME = NULL;
char * RULES = "rules";
int SECONDS = 5;


/* Functions */
void usage(const char *program_name, int status) {
	fprintf(stderr, "Usage: %s [OPTIONS] ROOT\n", program_name);
	fprintf(stderr, "\nOptions:\n");
	fprintf(stderr, "-h          Print this help message\n");
    fprintf(stderr, "-f RULES    Load rules from this file (default is rules)\n");
    fprintf(stderr, "-t SECONDS  Time between scans (default is 5 seconds)\n");
    exit(status);
}

/* Main Execution */
int	main(int argc, char *argv[]) {
    
    PROGRAM_NAME = argv[0];

    int argind = 2;
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char * arg = argv[argind++];

        if (arg[1] == 'h')
            usage(PROGRAM_NAME, 0);
        else if (arg[1] == 'f')
        	RULES = strdup(argv[2]);
        else if (arg[1] == 't')
        	SECONDS = stoi(argv[2]);
    }

    return EXIT_SUCCESS;
}
