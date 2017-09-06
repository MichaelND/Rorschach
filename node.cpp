#include "node.hpp"

using namespace std;

// Constructors
Node::Node()
	: path(""), m_time(0), inode(0)
	{ }

Node::Node(string p, time_t m_t, int i)
	: path(p), m_time(m_t), inode(i)
	{ }

// Deconstructor
Node::~Node() { }

// Path Methods
string Node::getPath() const { return path; }
void Node::setPath(string path) { this->path = path; }

// M Time Methods
time_t Node::getMTime() const { return m_time; }
void Node::setMTime(time_t m_time) { this->m_time = m_time; }

// Inode Methods
int Node::getINode() const { return inode; }
void Node::setINode(int inode) { this->inode = inode; } 
