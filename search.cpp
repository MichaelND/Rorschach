/* search.c */

#include "bst.hpp"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

/**
 * Recursively search through the provided root directory
 * @param   root        Path to directory
 * @return  Whether or not the search was successful.
 */
int	    search(const char *root) {	
    DIR * parent_dir = opendir(root);
    if (parent_dir == NULL) { return EXIT_FAILURE; }    // Check if directory is openable

    struct dirent * dentry;
    while ((dentry = readdir(parent_dir))) {            // Read
        
        if (streq(dentry->d_name, ".") || streq(dentry->d_name, ".."))
            continue;

        puts(dentry->d_name);

        char path[BUFSIZ];
        sprintf(path, "%s/%s", root, dentry->d_name);    // Store path of file

        // if (filter(path,settings) == false)
        //     execute(path,settings);
        if (dentry->d_type == DT_DIR)
            search(path);


    }
    closedir(parent_dir);                               // Close
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
