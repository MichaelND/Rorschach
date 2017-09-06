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
 * @param   u_set       Unordered set
 * @return  Whether or not the search was successful.
 */
int	    search(const char *root, unordered_set<Node> &setOfNodes) {	
    DIR * parent_dir = opendir(root);
    if (parent_dir == NULL) { return EXIT_FAILURE; }    // Check if directory is openable

    struct dirent * dentry;
    while ((dentry = readdir(parent_dir))) {            // Read
        
        if (streq(dentry->d_name, ".") || streq(dentry->d_name, ".."))
            continue;

        // TODO : Verify if File --> Store Into U_Set

        char path[BUFSIZ];
        sprintf(path, "%s/%s", root, dentry->d_name);   // Store path of file

        // if (filter(path,settings) == false)
        //     execute(path,settings);
        if (dentry->d_type == DT_DIR)
            search(path, setOfNodes);
        if (dentry->d_type == DT_REG) {
            struct stat s;
            if (stat(dentry->d_name, &s) == 0) {
                Node file(path, s.st_mtime, s.st_ino);
                unordered_set<Node>::const_iterator got = setOfNodes.find(s.st_ino);
                if ( got != setOfNodes.end()) {         // The file has been created.
                    
                    setOfNodes.insert(file);
                        // Handle rule for creation.
                }
            }
        }
    }
    closedir(parent_dir);                               // Close

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
