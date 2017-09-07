/* execute.cpp */

#include "node.hpp"

//execute after detection of created, deleted, or modified event
void	   execute() {
	char *basepath, *fullpath, *event, *timestamp;

	basepath = getenv("BASEPATH");
	fullpath = getenv("FULLPATH");
	event = getenv("EVENT");
	timestamp = getenv("TIMESTAMP");


}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
