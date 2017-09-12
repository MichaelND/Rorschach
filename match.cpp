/* match.cpp */

#include "node.hpp"
#include <time.h>

int match(const char *event, const char *fullpath, vector<inputrules> &rulesVector, const char* name) {
	int rv = 0; // return value, if 1 then match occurred, else then no match

	for (auto rule : rulesVector) {
		if (streq(event, rule.event) && ((fnmatch(rule.pattern, fullpath, 0) == 0) || streq(rule.pattern, name))) { // Event matches a rule set in rules file and file matches pattern.
			cout << "Matched \"" << rule.pattern << "\" pattern on \"" << name << "\"" << endl; 

			setenv("EVENT", event, 1);
            setenv("BASEPATH", name, 1);
            setenv("FULLPATH", fullpath, 1);

            time_t timestamp;
            time(&timestamp);
            setenv("TIMESTAMP", ctime(&timestamp), 1);

            execute(rule.action);
            rv = 1;
		}
	}
	return rv;
}