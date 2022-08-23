# C

- https://stackoverflow.com/questions/2407605/c-warning-missing-sentinel-in-function-call
- https://people.cs.rutgers.edu/~pxk/416/notes/c-tutorials/index.html
- https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/

### Data Types, `limits.h` and `stdint.h`

- https://en.wikipedia.org/wiki/C_data_types
- https://www.geeksforgeeks.org/data-types-in-c/
- https://stackoverflow.com/questions/2053843/min-and-max-value-of-data-type-in-c
- https://stackoverflow.com/questions/1577172/cross-platform-selecting-data-types-to-use-32-64-bit
- The standard only specifies the minimum int size.
- 32-bit compiler `int` = 16 bits (2 bytes)
- 64-bit compiler `int` = 32 bits (4 bytes)

### `UNIX` Processes

- https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY

### `char **envp`

A string array with all the environment variables of the parent shell.

- https://www.geeksforgeeks.org/c-program-print-environment-variables/
- https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
- https://stackoverflow.com/questions/54723587/what-does-envp-stand-for

### `termios.h`

- https://man7.org/linux/man-pages/man0/termios.h.0p.html

### `curses.h` (ncurses)

- https://linux.die.net/man/3/ncurses

### `termcap` (obsolete)

- https://linux.die.net/man/5/termcap
- https://en.wikipedia.org/wiki/Termcap
- http://academy.delmar.edu/Courses/ITSC1358/eBooks/man-termcap.pdf

### `term.h`

- https://pubs.opengroup.org/onlinepubs/7908799/xcurses/term.h.html

### `terminfo`

- https://linux.die.net/man/5/terminfo

### Hash Table

- https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus

### **`errno.h`**

- https://www.man7.org/linux/man-pages/man3/errno.3.html

```bash
# GET ALL ERRNO CODES
$ sudo apt install moreutils
$ errno -l
```

### **`execvp()` & `execlp()` (forbidden)**

- https://www.cs.uleth.ca/~holzmann/C/system/pipeforkexec.html
- http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html
- https://www.youtube.com/watch?v=OVFEWSP7n8c
- https://www.youtube.com/watch?v=mj2VjcOXXs4

### Max File Descriptors

- https://docs.oracle.com/cd/E19476-01/821-0505/file-descriptor-requirements.html

### Arrays vs. Pointers

- https://stackoverflow.com/questions/8108416/excess-elements-of-scalar-initializer-for-pointer-to-array-of-ints
