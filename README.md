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
>	  map of structs, stored by inode. These structs store only the file path,
>	  and modification time. For creations and  modifications, we expect O(1)
>     search. For removals, we expect O(n) time to simply iterate through the
>     map and stat each element. If the stat fails, then we know that it was
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
>         To execute the corresponding action, we'd need to use fork(), wait(), and execlp(). We
>     will use fnmatch() and streq() to determine if the file matches a provided pattern.
>         We also will use basename() to aqcuire the basename of the file.
>         We will need to use fopen() and fgets() to open the rules file and
>     read in the rules line by line.
>
>   2. How would you pass the environment variables to the command?
>         To pass environment variables to the command, we are storing all of
>      the important variables in our data structure and then passing them to
>      our function that handles the command. We used setenv() as well.

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
>     unordered map and our structs in our linked lists.

Testing
-------

> Describe how you tested and verified that `rorschach` met the project
> requirements.
	We verified that rorscach met the project requirements by first running the test script and making sure that the program passed all the tests. We also indvidually created, modified, and deleted files in the root directory. Modified the rules file so that we could check to if a pattern was matched, and if it did, to execute a certain action on the file. We checked for sigint manually. We ran gdb and valgrind to check for memory leaks. We also ran different inputs on the rorschach file to make sure that it parses rules correctly.

Analysis
--------

> How is what `rorschach` does similar to how a [system call] operates?
	Rorschach is similar to how a system call operates because it provides an interface for when you create, modify, and delete a file. A system call is when we request certain system resources during a running program and will be handled by the operating system. We create a set of rules within a rules file and give it to rorschach to handle. Rorschach will handle file events based on these rules by executing a certain action on that file. 
.

> As described in the project requirements, `rorschach` periodically scans the
> `root` directory to detect changes in files.  This process can be described
> as a form of [busy waiting].
>
>   1. In this specific context, why could this be considered a possible
>      negative design flaw?
		This can be a negative design flaw because it will use CPU cycles that don't perform an action. If the time of detecting a change of the file is too far apart, then it may miss a change in the file. If the time to detect the change in file too fast, then the user will not be able to keep track of all the updates if many updates occur.
>
>   2. Consider [inotify(7)] provided by [Linux].  How would these system calls
>      help address the problem of [busy waiting]?
		Instead of busy waiting, intotify(7) will only detect events when they happen rather than at a fixed time interval. This event based function helps us reduce wasted CPU cycles. 
>
>   3. Why might we still consider using [busy waiting] as specified in the
>      original design rather than use something like [inotify(7)]?
		We might use busy waiting over inotify(7) because we might want to keep track of when an event happens in the past at a certain time. We may also want to focus on a single processor which would utilize busy waiting. 

[Linux]:        https://kernel.org
[busy waiting]: https://en.wikipedia.org/wiki/Busy_waiting
[system call]:  https://en.wikipedia.org/wiki/System_call
[inotify(7)]:   http://man7.org/linux/man-pages/man7/inotify.7.html

Errata
------

> Describe any known errors, bugs, or deviations from the requirements.
	TODO: DONALD
	We assume we are on a single partition and so we use inodes as the key for our map. 

Extra Credit
------------

> Describe what extra credit (if any) that you implemented.

Grader
------

- John "Jeffrey" Westhoff (jwesthof@nd.edu)
