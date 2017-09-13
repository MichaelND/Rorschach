#include "node.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

#include <iostream>

using namespace std;


/* Global Variables */
vector<inputrules> rulesVector;   // Vector of vectors for rules
char *ROOT = NULL;
char *PROGRAM_NAME = NULL;
std::string RULES = "rules";
char real[BUFSIZ];

/* Functions */
void usage(const char *program_name, int status) {
	fprintf(stderr, "Usage: %s [OPTIONS] ROOT\n", program_name);
	fprintf(stderr, "\nOptions:\n");
	fprintf(stderr, "-h          Print this help message\n");
    fprintf(stderr, "-f RULES    Load rules from this file (default is rules)\n");
    fprintf(stderr, "-t SECONDS  Time between scans (default is 5 seconds)\n");
    exit(status);
}

/* Signal Handler */
void signal_handler(int signal_number) {
    cout << endl;
    cout << "Cleaning up" << endl;
    // Clean up anything if need be...

    for (auto rule : rulesVector) {
        free(rule.event);
        free(rule.pattern);
        free(rule.action);
    }

    cout << "Bye!" << endl;
    exit(EXIT_SUCCESS);
}

/* Main Execution */
int	main(int argc, char *argv[]) {
    // Declare variables.
    int SECONDS = 5;
    unordered_map<int, Node> mapOfNodes;

    // Parse Command Line Arguments
    PROGRAM_NAME = argv[0];
    int argind = 1;

    if (argc == 1) {
        usage(PROGRAM_NAME, 1); // No command line arguments given
    }

    // Handle signal interrupts
    signal(SIGINT, signal_handler);

    // Parse through flags
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char * arg = argv[argind++];

        if (arg[1] == 'h')
            usage(PROGRAM_NAME, 0);
        else if (arg[1] == 'f')
        	RULES = argv[argind];
        else if (arg[1] == 't') 
        	SECONDS = atoi(argv[argind]);

        argind++;
    }

    // Set the root path.
    ROOT = argv[argind];

    realpath(ROOT, real); // Find the realpath and store it into real

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
        search(ROOT, mapOfNodes, rulesVector, 1);
        examine(mapOfNodes, rulesVector);
        sleep(SECONDS);
    }

   

    return EXIT_SUCCESS;
}
