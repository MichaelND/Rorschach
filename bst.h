<<<<<<< HEAD

=======
/* bst.h */

#ifndef BST_H
#define	BST_H

#include <stdio.h>
#include <time.h>

/* Macros */
#define	    streq(s0, s1)   (strcmp((s0), (s1)) == 0)

/* Type definitions */

typedef struct {

	char *path;			/* Get the path of the file so stat can be called */
	time_t time;       /* File was modified more recently than file (-newer) */ 

} Leaf;

/* Function prototypes */

// int	    search(const char *root, const Settings *settings);
// bool	    filter(const char *path, const Settings *settings);
// int         execute(const char *path, const Settings *settings);

// bool        is_directory_empty(const char *path);
// time_t      get_mtime(const char *path);

#endif
>>>>>>> f0db03be9182f5e7a85c48875914508dd2abc8bb
