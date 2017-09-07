#include "node.hpp"
#include <string.h>
#include <errno.h>
#include <fnmatch.h>

int rules (char *fullpath, vector<inputrules> &rulesVector) {
	// Updates and populates the array of vectors with rules.
    FILE * file;
    char buffer[BUFSIZ];

    file = fopen(fullpath, "r");
    if (file != NULL) {
        fgets(buffer, BUFSIZ, file);
        //puts(buffer);
    } else {
        cout << "Fopen failed: " << strerror(errno) << endl;
        return EXIT_FAILURE;
    }
    return 0;
}