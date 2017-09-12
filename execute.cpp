/* execute.cpp */

#include "node.hpp"

//execute after detection of created, deleted, or modified event
void	   execute(const char *action) {
	// char *basepath = getenv("BASEPATH");
	// char *fullpath = getenv("FULLPATH");
	// char *event = getenv("EVENT");
	// char *timestamp = getenv("TIMESTAMP");
	// char e_basepath[strlen(basepath) + sizeof("PATH=")];
	// char e_fullpath[strlen(fullpath) + sizeof("PATH=")];
	// char e_event[strlen(event) + sizeof("PATH=")];
	// char e_timestamp[strlen(timestamp) + sizeof("PATH=")];
	// char command[BUFSIZ];

	// if (!sprintf(command, "%s %s", basepath, action)) {
	// 	cout << "fail sprintf" << endl;
	// }

	// sprintf(e_basepath, "BASEPATH=%s", getenv("BASEPATH"));
	// sprintf(e_fullpath, "FULLPATH=%s", getenv("FULLPATH"));
	// sprintf(e_event, "EVENT=%s", getenv("EVENT"));
	// sprintf(e_timestamp, "TIMESTAMP=%s", getenv("TIMESTAMP"));

	// char *envVariables[] {e_basepath, e_fullpath, e_event, e_timestamp, NULL};

	pid_t pid = fork();
    switch (pid) {
        case -1:        // Error
            fprintf(stderr, "Unable to fork: %s\n", strerror(errno));
            break;
        case  0:        // Child
            execlp("/bin/sh", "/bin/sh", "-c", action, NULL);
            _exit(EXIT_FAILURE);
        default:        // Parent
            wait(NULL);
            break;
    }

}