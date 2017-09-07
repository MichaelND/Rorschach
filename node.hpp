/* node.hpp */

#ifndef NODE_HPP
#define	NODE_HPP

#include <iostream>
#include <sys/stat.h>

#include <stdio.h>
#include <string>
#include <time.h>

#include <unordered_map>
#include <vector>

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

struct inputrules{
	string event;
	string pattern;
	string action;
};

namespace std {
    template<> struct hash<Node> {
    	size_t operator()(const Node & n) const {
    		return hash<int>()(n.getINode());
    	}
	};
}


/* Search Prototype */
int search(const char *root, unordered_map<int, Node> &mapOfNodes, bool flag);

/* Examine Prototype */
void examine (unordered_map<int, Node> &mapOfNodes);

/* Execute Prototype */
void execute();

/* Rules Prototype */
int rules(char *fp, vector<inputrules> &v);

/* Match Prototype */
int match();

#endif
