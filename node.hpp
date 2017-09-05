/* node.hpp */

#ifndef NODE_HPP
#define	NODE_HPP

#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

/* Macros */
#define	    streq(s0, s1)   (strcmp((s0), (s1)) == 0)

/* Node Class Interface */
class Node
{
public:
	// Constructor and Deconstructor
	Node();
	Node(string path, time_t m_time);
	~Node();

	// Returns file path and sets file path.
	string  getPath();
	void 	setPath(string path);

	// Returns file modification time and sets file modification time.
	time_t 	getMTime();
	void 	setMTime(time_t m_time);

private:
	string path;
	time_t m_time; // Modification time
};


/* Search Prototype */
int search(const char *root);

#endif
