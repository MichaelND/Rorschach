#include "node.hpp"

using namespace std;

void examine(unordered_set<Node> &setOfNodes) {
	
    for (auto it = setOfNodes.begin(); it != setOfNodes.end(); it++) {
        int 		inode 	= (*it).getINode();
        const char *path 	= (*it).getPath().c_str();
        time_t 		m_time 	= (*it).getMTime();

        struct stat s;
        if (stat(path, &s) == 0) {
        	// File exists.
        	cout << "File " << path << " exists." << endl;
        } else {
        	// File does not exist.
        	cout << "Detected\"DELETE\" event on \"" << path << "\"" << endl;
        }
    }
}