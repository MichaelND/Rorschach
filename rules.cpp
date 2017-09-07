#include "node.hpp"
#include <string.h>
#include <errno.h>
#include <fnmatch.h>

int rules (char *fullpath, vector<inputrules> &rulesVector) {
	// Updates and populates the array of vectors with rules.
    FILE * file;
    char buffer[BUFSIZ];
    char event[BUFSIZ], pattern[BUFSIZ], action[BUFSIZ];

    file = fopen(fullpath, "r");
    if (file != NULL) {
    	while (fgets(buffer, BUFSIZ, file) != nullptr && !streq(buffer, "\n")) { // NOTE: if rules file has extra endline then the && streq avoids that
    		inputrules i_struct;

	        sscanf(buffer, "%s %s %[^\n]" , event, pattern, action);
	        i_struct.event = event;
	        i_struct.pattern = pattern;
	        i_struct.action = action;
	        cout << " >> " <<i_struct.event << " >> " <<i_struct.pattern << " >> " <<i_struct.action << endl;

	        rulesVector.push_back(i_struct);
    	}

        
    } else {
        cout << "Fopen failed: " << strerror(errno) << endl;
        return EXIT_FAILURE;
    }
    return 0;
}