/* execute.cpp */

#include "node.hpp"

//execute after detection of created, deleted, or modified event
void	   execute(const char *action) {
	char *basepath, *fullpath, *event, *timestamp;
	char command[BUFSIZ];

	basepath = getenv("BASEPATH");
	fullpath = getenv("FULLPATH");
	event = getenv("EVENT");
	timestamp = getenv("TIMESTAMP");

	cout << "base: " << basepath << " full: " << fullpath << " event: " << event << " time :" << timestamp << endl;

	if (!sprintf(command, "%s %s", basepath, action)) {
		cout << "fail sprintf" << endl;
	}
	cout << "command:" << command << endl;

	cout << "Executing action " << action << " on " << basepath << endl;

	if (execvp(basepath, (char* const*)command)) {
		cout << "Success" << endl;
	} else {
		cout << "execvp failed: " << strerror(errno) << endl;
	}
}