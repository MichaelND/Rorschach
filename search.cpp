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
int	    search(const char *root, unordered_map<int, Node> &mapOfNodes, bool flag) {	
    DIR * parent_dir = opendir(root);
    if (parent_dir == NULL) { return EXIT_FAILURE; }    // Check if directory is openable

    struct dirent * dentry;
    while ((dentry = readdir(parent_dir))) {            // Read
        
        if (streq(dentry->d_name, ".") || streq(dentry->d_name, ".."))
            continue;

        char path[BUFSIZ];
        sprintf(path, "%s/%s", root, dentry->d_name);   // Store path of file

        if (dentry->d_type == DT_DIR) {
            search(path, mapOfNodes, flag);
        }
        if (dentry->d_type == DT_REG) {
            struct stat s;
            if (stat(path, &s) == 0) {
                Node file(path, s.st_mtime, s.st_ino);
                unordered_map<int, Node>::const_iterator got = mapOfNodes.find(s.st_ino);
                if ( got == mapOfNodes.end()) {         // The file has been created.
                    mapOfNodes.insert({s.st_ino, file});
                    if (flag) {   // Handle rule for creation.
                        cout << "Detected \"CREATION\" event on \"" << path << "\"" << endl;
                    }
                }
            } else {
                cout << "Stat failed: " << strerror(errno) << endl;
            }
        }
    }
    closedir(parent_dir);                               // Close

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
