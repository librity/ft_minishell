# Allowed Functions

- https://github.com/hashlyschool/42_minishell#%D1%80%D0%B0%D0%B7%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%BD%D1%8B%D0%B5-%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B8-external-functs

### `malloc()`

- https://man7.org/linux/man-pages/man3/malloc.3.html
- https://gustedt.wordpress.com/2011/11/05/chasing-a-phantom-checking-the-return-of-malloc/
- https://www.youtube.com/watch?v=NKTfNv2T0FE&t=4361s

### `free()`

- https://linux.die.net/man/3/free
- https://stackoverflow.com/questions/2354658/freeing-a-null-pointer

### `printf()`

- https://www.man7.org/linux/man-pages/man3/printf.3.html

### `perror()`

- https://www.man7.org/linux/man-pages/man3/perror.3.html

### **`strerror()`**

- https://linux.die.net/man/3/strerror
- https://www.geeksforgeeks.org/error-handling-c-programs/

### `open()`

- https://www.man7.org/linux/man-pages/man2/open.2.html
- https://jameshfisher.com/2017/02/24/what-is-mode_t/

### `read()`

### `write()`

### `close()`

- https://www.man7.org/linux/man-pages/man2/close.2.html

### **`access()`**

Checks if the calling process can access a specific file

- https://www.man7.org/linux/man-pages/man2/access.2.html

### `stat()`, `fstat()` & `lstat()`

- https://linux.die.net/man/2/stat
- https://linux.die.net/man/2/fstat
- https://linux.die.net/man/2/lstat
- https://www.emblogic.com/blog/12/diffrence-between-statfstat-and-lstat/
- https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/stat.html
- https://stackoverflow.com/questions/4553012/checking-if-a-file-is-a-directory-or-just-a-file
- https://www.youtube.com/watch?v=LERSkW_pLBs

### `pipe()`

Creates a pipe: a data channel through which processes can communicate.
Emitting processes can write to`pipefd[1]`,
and receiving ones can read from `pipefd[0]`.

- https://www.man7.org/linux/man-pages/man2/pipe.2.html
- https://man7.org/linux/man-pages/man7/pipe.7.html
- https://www.programacaoprogressiva.net/2014/09/Pipes-em-C-Comunicao-entre-Processos-IPC-Interprocess-Communication.html
- http://www.cse.cuhk.edu.hk/~ericlo/teaching/os/lab/6-IPC1/pipe-fork.html
- https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/
- https://medium.com/swlh/understanding-pipes-in-unix-with-a-sample-implementation-9fe110d36412
- https://www.youtube.com/watch?v=6xbLgZpOBi8

### **`dup()` & `dup2()`**

Adjust file descriptors so they reference the same file.

- https://www.man7.org/linux/man-pages/man2/dup.2.html
- https://www.geeksforgeeks.org/dup-dup2-linux-system-call/
- https://stackoverflow.com/questions/1720535/practical-examples-use-dup-or-dup2
- https://www.youtube.com/watch?v=5fnVr-zH-SE
- https://www.youtube.com/watch?v=EqndHT606Tw

### `fork()`

Forks the parent process, creating a child process.
The child process is almost identical to its parent,
with a copy of its memory space at the time of fork.

- https://www.man7.org/linux/man-pages/man2/fork.2.html
- https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
- https://cs61.seas.harvard.edu/wiki/images/b/ba/Cs61-2013-l21-scribe1.pdf
- https://www.youtube.com/watch?v=9seb8hddeK4
- https://www.youtube.com/watch?v=PwxTbksJ2fo
- https://www.youtube.com/watch?v=TJzltwv7jJs
- https://www.youtube.com/watch?v=\_kUiH8DG-Ao
- https://www.youtube.com/watch?v=cex9XrZCU14

### **`execve()`**

Replaces the current process with a system call.

- https://jameshfisher.com/2017/02/05/how-do-i-use-execve-in-c/
- https://stackoverflow.com/questions/29615540/using-execve-in-c
- https://www.tutorialspoint.com/unix_system_calls/execve.htm
- https://www.man7.org/linux/man-pages/man2/execve.2.html
- https://stackoverflow.com/questions/5429141/what-happens-to-malloced-memory-after-exec-changes-the-program-image/5429592#5429592
- https://medium.com/@SergioPietri/behind-the-scenes-what-happens-when-you-execute-a-command-in-the-shell-9fef53832f6a

### **`unlink()`**

- https://linux.die.net/man/2/unlink

### `POSIX` signals

- https://man7.org/linux/man-pages/man2/signal.2.html
- https://man7.org/linux/man-pages/man7/signal.7.html
- https://www.youtube.com/watch?v=83M5-NPDeWs

### **`wait()` & `waitpid()`**

Wait for a process to change state.

- https://man7.org/linux/man-pages/man2/wait.2.html
- https://www.man7.org/linux/man-pages/man3/waitpid.3p.html
- https://programmer.help/blogs/linux-kernel-learning-notes-4-wait-waitpid-wait3-and-wait4.html#:~:text=The difference between wait3(),of the waitpid() function
  of%20the%20waitpid()%20function>)
- https://www.programmersought.com/article/67266178599/

### **`wait3()` & `wait4()`**

- https://linux.die.net/man/2/wait3
- https://linux.die.net/man/2/wait4

### `kill()`

- https://man7.org/linux/man-pages/man2/kill.2.html
- https://aljensencprogramming.wordpress.com/2014/05/15/the-kill-function-in-c/

### `readline()`

- https://en.wikipedia.org/wiki/GNU_Readline
- https://man7.org/linux/man-pages/man3/readline.3.html
- https://tiswww.case.edu/php/chet/readline/readline.html
- https://web.mit.edu/gnu/doc/html/rlman_2.html#SEC31
- https://www.gnu.org/software/bash/manual/html_node/Readline-Interaction.html

```bash
$ sudo apt-get install libreadline-dev
```

### `rl_clear_history()`

### `rl_on_new_line()`

### `rl_replace_line()`

- https://stackoverflow.com/questions/68003253/error-implicit-declaration-of-function-rl-replace-line-is-invalid-in-c99-we

### `rl_redisplay()`

- https://tiswww.case.edu/php/chet/readline/readline.html#index-rl_005fredisplay

### `add_history()`

- https://tiswww.case.edu/php/chet/readline/history.html
- https://www.man7.org/linux/man-pages/man3/history.3.html

### `signal()`

- https://www.man7.org/linux/man-pages/man7/signal.7.html

### `sigaction()`

- https://www.man7.org/linux/man-pages/man3/sigaction.3p.html
- https://www.man7.org/linux/man-pages/man2/sigaction.2.html

### `sigemptyset()`

- https://linux.die.net/man/3/sigemptyset
- https://stackoverflow.com/questions/20684290/signal-handling-and-sigemptyset
- https://stackoverflow.com/questions/20684290/signal-handling-and-sigemptyset

### `sigaddset()`

- https://linux.die.net/man/3/sigaddset

### `exit()`

- https://www.man7.org/linux/man-pages/man3/exit.3.html

### `getcwd()`

- https://www.man7.org/linux/man-pages/man3/getcwd.3.html
- https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program

### `chdir()`

- https://linux.die.net/man/2/chdir

### `opendir()`

- https://linux.die.net/man/3/opendir

### `readdir()`

- https://linux.die.net/man/3/readdir

### `closedir()`

- https://linux.die.net/man/3/closedir

### `isatty()`

- https://man7.org/linux/man-pages/man3/isatty.3.html

### `ttyname()`

- https://www.man7.org/linux/man-pages/man3/ttyname.3.html

### `ttyslot()`

- https://www.man7.org/linux/man-pages/man3/ttyslot.3.html

### `ioctl()`

- https://man7.org/linux/man-pages/man2/ioctl.2.html

### `getenv()`

- https://linux.die.net/man/3/getenv

### `tcsetattr()`

- https://linux.die.net/man/3/tcsetattr

### `tcgetattr()`

- https://linux.die.net/man/3/tcgetattr

### `tgetent()`

- https://linux.die.net/man/3/tgetent

### `tgetflag()`

- https://linux.die.net/man/3/tgetflag

### `tgetnum()`

- https://linux.die.net/man/3/tgetnum

### `tgetstr()`

- https://linux.die.net/man/3/tgetstr

### `tgoto()`

- https://linux.die.net/man/3/tgoto

### `tputs()`

- https://linux.die.net/man/3/tputs
