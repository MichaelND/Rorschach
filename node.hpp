/* node.hpp */

#ifndef NODE_HPP
#define	NODE_HPP

#include <iostream>
#include <sys/stat.h>
#include <sys/wait.h>

#include <stdio.h>
#include <string>
#include <string.h> // strcmp()
#include <libgen.h> // basename()
#include <fnmatch.h>
#include <time.h>
#include <unistd.h> // exec()

#include <unordered_map>
#include <vector>
#include <csignal>

using namespace std;


/* Macros */
#define	    streq(s0, s1)   (strcmp((s0), (s1)) == 0)

/* Node Class Interface */
class Node
{
public:
	// Constructor and Deconstructor
	Node();
	Node(string path, time_t m_time, int inode);
	~Node();

	// Returns file path and sets file path.
	string  getPath() const;
	void 	setPath(string path);

	// Returns file modification time and sets file modification time.
	time_t 	getMTime() const;
	void 	setMTime(time_t m_time);

	// Returns inode of the file.
	int 	getINode() const;
	void	setINode(int inode);

	bool operator==(const Node & n) const {
	if (inode == n.inode)
  		return true;
	else
		return false;
	}

private:
	string 	path;
	time_t 	m_time; 	// Modification time
	int 	inode;		// Inode
};

struct inputrules {
	inputrules(char *e, char *p, char *a)
		: event(e), pattern(p), action(a)
		{ }

	char *event;
	char *pattern;
	char *action;
};

namespace std {
    template<> struct hash<Node> {
    	size_t operator()(const Node & n) const {
    		return hash<int>()(n.getINode());
    	}
	};
}

/* Search Prototype */
int search(const char *root, unordered_map<int, Node> &mapOfNodes, vector<inputrules> &rulesVector, bool flag);

/* Examine Prototype */
void examine (unordered_map<int, Node> &mapOfNodes, vector<inputrules> &rulesVector);

/* Execute Prototype */
void execute(const char *action);

/* Rules Prototype */
int rules(char *filepath, vector<inputrules> &rulesVector);

/* Match Prototype */
int match(const char *event, const char *filepath, vector<inputrules> &rulesVector, const char *name);

#endif
