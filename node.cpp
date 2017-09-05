#include "node.hpp"
#include <unordered_set>

using namespace std;

// Constructors
Node::Node()
	: path(""), m_time(0)
	{ }

Node::Node(string p, time_t m_t)
	: path(p), m_time(m_t)
	{ }

// Deconstructor
Node::~Node() { }

// Path Methods
string Node::getPath() { return path; }

void Node::setPath(string path) { this->path = path; }

// M Time Methods
time_t Node::getMTime() { return m_time; }

void Node::setMTime(time_t m_time) { this->m_time = m_time; }