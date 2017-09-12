/* search.c */

#include "node.hpp"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include <iostream>

/**
 * Recursively search through the provided root directory
 * @param   root        Path to directory
 * @param   mapOfNodes  Unordered map of nodes
 * @return  Whether or not the search was successful.
 */
int	    search(const char *root, unordered_map<int, Node> &mapOfNodes, vector<inputrules> &rulesVector, bool flag) {	
    DIR * parent_dir = opendir(root);
    if (parent_dir == NULL) { return EXIT_FAILURE; }    // Check if directory is openable

    struct dirent * dentry;
    while ((dentry = readdir(parent_dir))) {            // Read
        
        if (streq(dentry->d_name, ".") || streq(dentry->d_name, ".."))
            continue;

        char path[BUFSIZ];
        sprintf(path, "%s/%s", root, dentry->d_name);   // Store path of file

        //check if directory 
        if (dentry->d_type == DT_DIR) {
            search(path, mapOfNodes, rulesVector, flag);
        }

        //check if file
        if (dentry->d_type == DT_REG) {
            struct stat s;

            if (stat(path, &s) == 0) {
                //create node with file data into class
                Node file(path, s.st_mtime, s.st_ino);

                unordered_map<int, Node>::const_iterator got = mapOfNodes.find(file.getINode());

                if (got == mapOfNodes.end()) {         // The file has been created.
                    mapOfNodes.insert({s.st_ino, file});

                    // Handle rule for creation.
                    if (flag) {   
                        cout << "Detected \"CREATE\" event on \"" << path << "\"" << endl;
                        const char *pattern = "CREATE";
                        setenv("EVENT", "CREATE", 1); //set environment variable event to delete

                        if (!match(pattern, path, rulesVector, dentry->d_name)) {
                            continue;
                        }
                    }
                }
            } 
            else {
                cout << "Stat failed: " << strerror(errno) << endl;
            }
        }
    }
    closedir(parent_dir); // Close

    return EXIT_SUCCESS;
}