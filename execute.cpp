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

	// Replace BASEPATH and FULLPATH.
	string cppaction(action);
	size_t b_pos = cppaction.find("${BASEPATH}");
	cppaction.replace(b_pos, string("${BASEPATH}").length(), basepath);
	size_t f_pos = cppaction.find("${FULLPATH}");
	cppaction.replace(f_pos, string("${FULLPATH}").length(), fullpath);

	// int i = 0;
	// char 
	// for (char *tok = strtok(cppaction.c_str(), " "); tok != NULL; tok = strtok(NULL, " ")) {

	// }

	char garbo[BUFSIZ];
	sscanf(action, "%s %[^\n]", command, garbo);

	// if (!sprintf(command, "%s %s", basepath, cppaction)) {
	// 	cout << "fail sprintf" << endl;
	// }
	cout << "command: " << command << endl;

	cout << "Executing action " << cppaction << " on " << basepath << endl;


	if (execvp(command, (char* const*)(cppaction.c_str()))) {
		cout << "Success: " << cppaction << endl;
	} else {
		cout << "execvp failed: " << strerror(errno) << endl;
	}
}