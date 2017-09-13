/* execute.cpp */

#include "node.hpp"

//execute after detection of created, deleted, or modified event
void	   execute(const char *action) {
	char *basepath = getenv("BASEPATH");

	pid_t pid = fork();
    switch (pid) {
        case -1:        // Error
            fprintf(stderr, "Unable to fork: %s\n", strerror(errno));
            break;
        case  0:        // Child
        	cout << "Executing action \"" << action << "\" on \"" << basepath << "\""<< endl;

       	 	if (execlp("/bin/sh", "/bin/sh", "-c", action, NULL) < 0)
       	 		_exit(EXIT_FAILURE);
        	
            break;
        default:        // Parent
            wait(NULL);
            break;
    }

}