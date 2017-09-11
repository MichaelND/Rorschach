/*utilities.c */

#include "node.hpp"

int match(const char *event, const char *fullpath, vector<inputrules> &rulesVector) {
	int rv = 0; // return value

	for (auto it = rulesVector.begin(); it != rulesVector.end(); it++) {
		cout << "Rules Vector Event: " << (*it).event << endl;
	}

	// for (auto rule : rulesVector) {
	// 	cout << "checking rules vector" << endl;
	// 	if (streq(event, rule.event) && (fnmatch(rule.pattern, fullpath, FNM_FILE_NAME) == 0)) { // Event matches a rule set in rules file and file matches pattern.
	// 		cout << "matched event and pattern" << endl;
 //            rv = 1;
	// 	}

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