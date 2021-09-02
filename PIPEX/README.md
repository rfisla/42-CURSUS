## PIPEX  PROJECT (42CURSUS)

The objective of the project is to code the Pipex program. The executable file must be name pipex.

It has to be executed in this way:

``` $> ./pipex file1 cmd1 cmd2 file2 ```

The execution of the Pipex program should do the the same as the next Shell command:

```$> < file1 cmd1 | cmd2 > file2```

---
For example: ```$> ./pipex infile "ls -l" "wc -l" outfile``` should be  the same as ```<infile ls -l | wc -l >outfile”```

---


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
