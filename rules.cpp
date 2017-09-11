/* rules.cpp */
#include "node.hpp"
#include <string.h>
#include <errno.h>
#include <fnmatch.h>

#include <list>

int rules (char *fullpath, vector<inputrules> &rulesVector) {
	// Updates and populates the vector with inputrules.
    FILE * file;
    char buffer[BUFSIZ];
    char event[BUFSIZ], pattern[BUFSIZ], action[BUFSIZ];

    // TODO: Debug vector.push_back()
    file = fopen(fullpath, "r");
    if (file != NULL) {
    	while (fgets(buffer, BUFSIZ, file) != nullptr && !streq(buffer, "\n")) { // NOTE: if rules file has extra endline then the && streq avoids that
	        sscanf(buffer, "%s %s %[^\n]" , event, pattern, action);
            rulesVector.push_back(inputrules(event, pattern, action));
    	}
    } else {
        cout << "Fopen failed: " << strerror(errno) << endl;
        fclose(file);
        return EXIT_FAILURE;
    }
    fclose(file);

    // DEBUG:
    for (vector<inputrules>::iterator it = rulesVector.begin(); it != rulesVector.end(); it++) {
        cout << "RULE EVENT IN RULES.CPP: " << (*it).event << endl;
        cout << "RULE PATTERN: " << (*it).pattern << endl;
        cout << "RULE ACTION: " << (*it).action << endl;
    }

    return 0;
}