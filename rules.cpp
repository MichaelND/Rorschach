/* rules.cpp */
#include "node.hpp"
#include <string.h>
#include <errno.h>
#include <fnmatch.h>
#include <cstdlib> 
#include <ctype.h>

#include <list>

int rules (char *fullpath, vector<inputrules> &rulesVector) {
	// Updates and populates the vector with inputrules.
    FILE * file;
    char buffer[BUFSIZ];

    //open file for reading
    file = fopen(fullpath, "r");
    if (file != NULL) {
    	while (fgets(buffer, BUFSIZ, file) != nullptr) { // NOTE: if rules file has extra endline then the && streq avoids that
            if ((strncmp(buffer, "\n", strlen("\n")) == 0) || (strncmp(buffer, "#", strlen("#")) == 0))
                continue;

            char* event = (char*) calloc(1, BUFSIZ);
            char* pattern = (char*) calloc(1, BUFSIZ);
            char* action = (char*) calloc(1, BUFSIZ);

            sscanf(buffer, "%s %s %[^\n]" , event, pattern, action); //read from buffer and store into event, pattern, action
            

            if (streq(pattern, "") || streq(action, "")) {
                free(event);
                free(pattern);
                free(action);
                fclose(file);
                return EXIT_FAILURE;
            }

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