#include "node.hpp"

using namespace std;

void examine(unordered_map<int, Node> &mapOfNodes) {
	
    for (auto it = mapOfNodes.begin(); it != mapOfNodes.end(); it++) {
        int 		inode 	= (*it).second.getINode();
        const char *path 	= (*it).second.getPath().c_str();
        time_t 		m_time 	= (*it).second.getMTime();

        struct stat s;
        if (stat(path, &s) == 0) {
        	// File exists.
        	if (s.st_mtime != m_time) {
        		cout << "Detected \"MODIFICATION\" event on \"" << path << "\"" << endl;
        		(*it).second.setMTime(s.st_mtime);	// Update m_time of file node.
        	}
        } else {
        	// File does not exist.
        	cout << "Detected \"DELETE\" event on \"" << path << "\"" << endl;
        }
    }
}