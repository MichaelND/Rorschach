/* execute.cpp */

#include "node.hpp"

//execute after detection of created, deleted, or modified event
void	   execute(const char *action) {
	char *basepath, *fullpath, *event, *timestamp;

	basepath = getenv("BASEPATH");
	fullpath = getenv("FULLPATH");
	event = getenv("EVENT");
	timestamp = getenv("TIMESTAMP");

	cout << "Executing action " << action << " on " << basepath << endl;

	// if (execvp(basepath, action)) {
	// 	cout << "Success" << endl;
	// } else {
	// 	cout << "execvp failed: " << strerror(errno) << endl;
	// }
}