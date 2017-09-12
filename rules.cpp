/* rules.cpp */
#include "node.hpp"
#include <string.h>
#include <errno.h>
#include <fnmatch.h>
#include <cstdlib> 

#include <list>

int rules (char *fullpath, vector<inputrules> &rulesVector) {
	// Updates and populates the vector with inputrules.
    FILE * file;
    char buffer[BUFSIZ];

    //open file for reading
    file = fopen(fullpath, "r");
    if (file != NULL) {
    	while (fgets(buffer, BUFSIZ, file) != nullptr && !streq(buffer, "\n")) { // NOTE: if rules file has extra endline then the && streq avoids that
            char* event = (char*) malloc(BUFSIZ);
            char* pattern = (char*) malloc(BUFSIZ);
            char* action = (char*) malloc(BUFSIZ);

            sscanf(buffer, "%s %s %[^\n]" , event, pattern, action); //read from buffer and store into event, pattern, action
            inputrules ptr = inputrules(event, pattern, action); 
            rulesVector.push_back(ptr);
    	}
    } else {
        cout << "Fopen failed: " << strerror(errno) << endl;
        fclose(file);
        return EXIT_FAILURE;
    }
    fclose(file);

    return 0;
}