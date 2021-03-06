#include "node.hpp"

using namespace std;

void examine(unordered_map<int, Node> &mapOfNodes, vector<inputrules> &rulesVector) {
    vector<int>	v_inodes;
	
    for (auto it = mapOfNodes.begin(); it != mapOfNodes.end(); it++) {
        int 		inode 	= (*it).second.getINode();
        const char *path 	= (*it).second.getPath().c_str();
        time_t 		m_time 	= (*it).second.getMTime();
        char 	   *base    = basename((char*)path);

        struct stat s;
        if (stat(path, &s) == 0) {
        	// File exists.
        	if (s.st_mtime > m_time) {
        		cout << "Detected \"MODIFY\" event on \"" << path << "\"" << endl;
        		const char *pattern = "MODIFY";
        		(*it).second.setMTime(s.st_mtime);	// Update m_time of file node.
                if (!match(pattern, path, rulesVector, base)) {
                    continue;
                }
        	}
        } else {
        	// File does not exist.
        	cout << "Detected \"DELETE\" event on \"" << path << "\"" << endl;
        	const char *pattern = "DELETE";
        	v_inodes.push_back(inode);
            if (!match(pattern, path, rulesVector, base)) {
                continue;
            }
        }
    }

    // Delete members from map if there are detected delete events.
    if (!v_inodes.empty()) {
    	for (auto it = v_inodes.begin(); it != v_inodes.end(); it++) {
    		mapOfNodes.erase(*it);				// Remove file node from unordered map.
    	}
    }
}