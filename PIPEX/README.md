## PIPEX  PROJECT (42CURSUS)

The objective of the project is to code the Pipex program. The executable file must be named pipex.

It has to be executed in this way:

``` $> ./pipex file1 cmd1 cmd2 file2 ```

The execution of the Pipex program should do the the same as the next Shell command:

```$> < file1 cmd1 | cmd2 > file2```

---
For example: ```$> ./pipex infile "ls -l" "wc -l" outfile``` should be  the same as ```<infile ls -l | wc -l >outfile”```



***The following functions are allowed:***
◦ access
◦ open
◦ unlink
◦ close
◦ read
◦ write
◦ malloc
◦ waitpid
◦ wait
◦ free
◦ pipe
◦ dup
◦ dup2
◦ execve
◦ fork
◦ perror
◦ strerror
◦ exit

In no way the program can quit unexpectedly (Segmentation fault, Bus error...) and the program cannot have memory leeaks.

## Result 
[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/rufernan/pipex)](https://github.com/JaeSeoKim/badge42)

## Compilation

```make all``` to compile the whole project. The result will be the program ```pipex```, ready to use in the described way.

-------

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)

