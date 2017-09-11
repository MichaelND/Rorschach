#include "node.hpp"
#include <string.h>
#include <errno.h>
#include <fnmatch.h>

#include <list>

int rules (char *fullpath, vector<inputrules> &rulesVector) {
	// Updates and populates the array of vectors with rules.
    FILE * file;
    char buffer[BUFSIZ];
    char event[BUFSIZ], pattern[BUFSIZ], action[BUFSIZ];


    file = fopen(fullpath, "r");
    if (file != NULL) {
    	while (fgets(buffer, BUFSIZ, file) != nullptr && !streq(buffer, "\n")) { // NOTE: if rules file has extra endline then the && streq avoids that
	        sscanf(buffer, "%s %s %[^\n]" , event, pattern, action);
            rulesVector.push_back(inputrules(event, pattern, action));


            // DBEUG:
            // cout << "STORING EVENT: " << i_struct.event << " IN RULES.CPP" << endl;
            // cout << "STORING PATTERN: " << i_struct.pattern << endl;
            // cout << "STORING ACTION: " << i_struct.action << endl;


            // auto it = rulesVector.begin();
            // rulesVector.insert(it, i_struct);
            // cout << "EVENT IN RULES.CPP: " << rulesVector.begin()->event << endl;
            // cout << "PATTERN: " << rulesVector.begin()->pattern << endl;
            // cout << "ACTION: " << rulesVector.begin()->action << endl;

            // for (vector<inputrules>::iterator it = rulesVector.begin(); it != rulesVector.end(); it++) {
            //     cout << "RULE EVENT IN RULES.CPP: " << (*it).event << endl;
            //     cout << "RULE PATTERN: " << (*it).pattern << endl;
            //     cout << "RULE ACTION: " << (*it).action << endl;
            // }
    	}

        cout << "VECTOR SIZE: " << rulesVector.size() << endl;
        // for (vector<inputrules>::iterator it = rulesVector.begin(); it != rulesVector.end(); it++) {
        //     cout << "RULE EVENT IN RULES.CPP: " << (*it).event << endl;
        //     cout << "RULE PATTERN: " << (*it).pattern << endl;
        //     cout << "RULE ACTION: " << (*it).action << endl;
        // }

        
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