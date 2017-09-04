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
    if (parent_dir == NULL) { return EXIT_FAILURE; }//check if directory is openable

    struct dirent * dentry;
    while ((dentry = readdir(parent_dir))) { //read
        
        if (streq(dentry->d_name, ".") || streq(dentry->d_name, ".."))
            continue;

        puts(dentry->d_name);

        // if (filter(path,settings) == false)
        //     execute(path,settings);
        // if (dentry->d_type == DT_DIR) 
        //     search(path,settings);

    }
    closedir(parent_dir); //close
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
