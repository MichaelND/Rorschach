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
	int spaces = 1;
	for (size_t i = 0; i < cppaction.length(); i++) {
		if (cppaction[i] == ' ') {
			spaces++;
		}
	}

	int j = 0;
	char *arr[spaces];
	for (char *tok = strtok((char *)cppaction.c_str(), " "); tok != NULL; tok = strtok(NULL, " ")) {
		arr[j] = tok;
		j++;
	}

	for (int k = 0; k < spaces; k++) {
		cout << "ARRAY[" << k << "]: " << arr[k] << endl;
	}

	char garbo[BUFSIZ];
	sscanf(action, "%s %[^\n]", command, garbo);

	// if (!sprintf(command, "%s %s", basepath, cppaction)) {
	// 	cout << "fail sprintf" << endl;
	// }
	cout << "command: " << command << endl;

	cout << "Executing action " << cppaction << " on " << basepath << endl;


	if (execvp(arr[0], arr)) {
		cout << "Success: " << arr[0] << endl;
	} else {
		cout << "execvp failed: " << strerror(errno) << endl;
	}
}