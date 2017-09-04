/* bst.h */

#ifndef BST_H
#define	BST_H

#include <stdio.h>
#include <time.h>

/* Macros */
#define	    streq(s0, s1)   (strcmp((s0), (s1)) == 0)

/* Type definitions */

typedef struct Leaf {

	Leaf *left;
	Leaf *right;
	char *path;			/* Get the path of the file so stat can be called */
	time_t time;       /* File was modified more recently than file (-newer) */ 

} Leaf;

/* Function prototypes */

int	    search(const char *root);
// bool	    filter(const char *path, const Settings *settings);
// int         execute(const char *path, const Settings *settings);

// bool        is_directory_empty(const char *path);
// time_t      get_mtime(const char *path);

#endif
