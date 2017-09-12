/* match.cpp */

#include "node.hpp"

int match(const char *event, const char *fullpath, vector<inputrules> &rulesVector, const char* name) {
	int rv = 0; // return value, if 1 then match occurred, else then no match

	for (auto rule : rulesVector) {
		if (streq(event, rule.event) && (fnmatch(rule.pattern, fullpath, 0) == 0)) { // Event matches a rule set in rules file and file matches pattern.
			cout << "Matched \"" << rule.pattern << "\" event on \"" << name << "\"" << endl;

			setenv("EVENT", "CREATE", 1); //set environment variable event to delete
            setenv("BASEPATH", name, 1);
            setenv("FULLPATH", fullpath, 1);
            setenv("TIMESTAMP", ctime(NULL), 1);
            execute(rule.action);
            rv = 1;
		}
	}
	return rv;
}