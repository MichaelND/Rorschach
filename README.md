CSE.30341.FA17: Project 01
==========================

This is the documentation for [Project 01] of [CSE.30341.FA17].

[Project 01]:       https://www3.nd.edu/~pbui/teaching/cse.30341.fa17/project01.html
[CSE.30341.FA17]:   https://www3.nd.edu/~pbui/teaching/cse.30341.fa17/

Members
-------

1. Anthony Luc (aluc@nd.edu)
2. Donald Luc (dluc@nd.edu)
3. Michael Wang (mwang6@nd.edu)

Design
------

> Explain how you would periodically scan the `root` the directory and detect
> if a file has been created, modified, or removed.
>
>   1. What system calls would you need to use?
>         To scan and search directories, you would need to use opendir(),
>     readdir(), and closedir(). We will certainly use the stat() function to
>     determine the metadata information about the file.
>
>   2. What information would you need to store and what data structures would
>      you need?
>         We will need to store the root directory. Also, we would need to store
>     the modification time and the last scan time. Then, we need to store the
>     inode number and the file path. Our data structure will be an unordered
>	  set of structs, stored by inode. These structs store only the file path,
>	  and modification time. For creations and  modifications, we expect O(1)
>     search. For removals, we expect O(n) time to simply iterate through the
>     set and stat each element. If the stat fails, then we know that it was
>     removed. If it succeeds, then we can determine, based on the modification
>     time, if the file was just created or modified.
>         For storing rules, we will use separate lists for the create,
>     modified, and removed rules. These lists will store structs that contain
>     the pattern and the action.

.

> Explain how you would check if a rule matched an event and execute the
> corresponding action.
>
>   1. What system calls would you need to use?
>         To execute the corresponding action, we'd need to use execvp(). We
>     will use regexec() to determine if the file matches a provided pattern.
>         We also will use basename() to aqcuire the basename of the file.
>         We will need to use fopen() and fgets() to open the rules file and
>     read in the rules line by line.
>
>   2. How would you pass the environment variables to the command?
>         To pass environment variables to the command, we are storing all of
>      the important variables in our data structure and then passing them to
>      our function that handles the command.

.

> Explain how you would handle a [SIGINT] signal and what you would need to
> cleanup?
>
>   1. What system calls would you need to use?
>         We will need to use signal() to catch the signal as well as our
>     own signal handler.
>
>   2. How would you know what resources to cleanup?
>         We will cleanup anything we malloc() such as our structs in our
>     unordered set and our structs in our linked lists.

Testing
-------

> Describe how you tested and verified that `rorschach` met the project
> requirements.

Analysis
--------

> How is what `rorschach` does similar to how a [system call] operates?

.

> As described in the project requirements, `rorschach` periodically scans the
> `root` directory to detect changes in files.  This process can be described
> as a form of [busy waiting].
>
>   1. In this specific context, why could this be considered a possible
>      negative design flaw?
>
>   2. Consider [inotify(7)] provided by [Linux].  How would these system calls
>      help address the problem of [busy waiting]?
>
>   3. Why might we still consider using [busy waiting] as specified in the
>      original design rather than use something like [inotify(7)]?

[Linux]:        https://kernel.org
[busy waiting]: https://en.wikipedia.org/wiki/Busy_waiting
[system call]:  https://en.wikipedia.org/wiki/System_call
[inotify(7)]:   http://man7.org/linux/man-pages/man7/inotify.7.html

Errata
------

> Describe any known errors, bugs, or deviations from the requirements.

Extra Credit
------------

> Describe what extra credit (if any) that you implemented.

Grader
------

- John "Jeffrey" Westhoff (jwesthof@nd.edu)
