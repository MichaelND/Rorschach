#include "node.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>

#include <unistd.h>

#include <iostream>

using namespace std;

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
    // Declare variables.
    char *PROGRAM_NAME = NULL;
    std::string RULES = "rules";
    char *PATH = NULL;
    int SECONDS = 5;
    unordered_map<int, Node> mapOfNodes;
    vector<inputrules> rulesVector;   // Vector of vectors for rules

    // Parse Command Line Arguments
    PROGRAM_NAME = argv[0];
    int argind = 1;

    if (argc == 1) {
        usage(PROGRAM_NAME, 1); // No command line arguments given
    }

    // Parse through flags
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char * arg = argv[argind++];

        if (arg[1] == 'h')
            usage(PROGRAM_NAME, 0);
        else if (arg[1] == 'f')
        	RULES = argv[2];
        else if (arg[1] == 't') 
        	SECONDS = atoi(argv[2]);

        argind++;
    }

    //check for improper formatting
    if (argind >= argc) 
        usage(PROGRAM_NAME, 1); //CHECK FOR INVALID COMMAND LINE ARGUMENTS

    // Set the root path.
    PATH = argv[argind];

    char real[BUFSIZ];
    realpath(PATH, real); //find the realpath and store it into real

    cout << "Monitoring " << real << endl;

    // Get file full path.
    char rulefullpath[BUFSIZ]; 
    realpath(RULES.c_str(), rulefullpath);

    // Store rules.
    if (rules(rulefullpath, rulesVector) != 0) {
        return EXIT_FAILURE;
    }

    search(real, mapOfNodes, rulesVector, 0);
    while (1) {
        sleep(SECONDS);
        search(real, mapOfNodes, rulesVector, 1);
        examine(mapOfNodes);
        cout << endl;

    }

    return EXIT_SUCCESS;
}
