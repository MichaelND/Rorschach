/* match.cpp */

#include "node.hpp"

int match(const char *event, const char *fullpath, vector<inputrules> &rulesVector, const char* name) {
	int rv = 0; // return value

	// TODO: FIX fnmatch()
	for (auto rule : rulesVector) {
		if (streq(event, rule.event) && (fnmatch(rule.pattern, fullpath, FNM_FILE_NAME) == 0)) { // Event matches a rule set in rules file and file matches pattern.
			cout << "matched event and pattern" << endl;
			setenv("EVENT", "CREATE", 1); //set environment variable event to delete
            setenv("BASEPATH", name, 1);
            setenv("FULLPATH", fullpath, 1);
            setenv("TIMESTAMP", (char*)time(0), 1);
            execute(rule.action);
            rv = 1;
		}
	}

	// DEBUG:
	// 	if (streq(event, rule.event)) {
	// 		cout << "streq success" << endl;
	// 	} else {
	// 		cout << "streq failed gg - Event: " << event << " and Rule.Event " << rule.event << endl;
	// 	}

	// 	if ((fnmatch(rule.pattern, fullpath, FNM_FILE_NAME) == 0)) {
	// 		cout << "fnmatch success" << endl;
	// 	} else {
	// 		cout << "fnmatch failed gg" << endl;
	// 	}
	// }

	return rv;
}