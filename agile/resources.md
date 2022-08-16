# Allowed Functions

### `malloc()`

- https://man7.org/linux/man-pages/man3/malloc.3.html
- https://gustedt.wordpress.com/2011/11/05/chasing-a-phantom-checking-the-return-of-malloc/
- https://www.youtube.com/watch?v=NKTfNv2T0FE&t=4361s

### `free()`

- https://linux.die.net/man/3/free

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

### `rl_clear_history()`

### `rl_on_new_line()`

### `rl_replace_line()`

- https://stackoverflow.com/questions/68003253/error-implicit-declaration-of-function-rl-replace-line-is-invalid-in-c99-we

### `rl_redisplay()`

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

---

# Tutorials

- https://harm-smits.github.io/42docs/projects/minishell
- https://www.notion.so/Acelera-Minishell-f6c3f8463e3e4580b4e61f4886036faf
- https://www.geeksforgeeks.org/making-linux-shell-c/
- https://linuxgazette.net/111/ramankutty.html
- https://www.3till7.net/2008/11/29/c-shell-with-forks-and-pipes/index.html
- https://gist.github.com/parse/966049
- https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
- https://velog.io/@hidaehyunlee/minishell-1.-과제소개-및-선행지식
- http://www.staroceans.org/minishell.htm
- https://brennan.io/2015/01/16/write-a-shell-in-c/
- https://www.youtube.com/watch?v=k6TTj4C0LF0

### \***\*Indradhanush Gupta’s Tutorial\*\***

- https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/
- https://indradhanush.github.io/blog/writing-a-unix-shell-part-2/
- https://indradhanush.github.io/blog/writing-a-unix-shell-part-3/

### \***\*Mohammed Isam’s Tutorial\*\***

- https://blog.devgenius.io/lets-build-a-linux-shell-part-i-954c95911501
- https://medium.com/swlh/lets-build-a-linux-shell-part-ii-340ecf471028
- https://medium.com/swlh/lets-build-a-linux-shell-part-iii-a472c0102849
- https://blog.devgenius.io/lets-build-a-linux-shell-part-iv-cefdd8f58138
- https://blog.devgenius.io/building-a-linux-shell-part-v-9cf3c0e31269

---

# Bash

- https://linux.die.net/man/1/bash
- https://www.youtube.com/playlist?list=PLFAC320731F539902
- https://opensource.com/resources/what-bash
- https://opensource.com/sites/default/files/gated-content/cheat_sheet_bash.pdf
- https://www.tutorialspoint.com/unix_commands/bash.htm
- https://tldp.org/LDP/Bash-Beginners-Guide/html/index.html
- https://datacadamia.com/lang/bash/start#grammar

### \***\*Builtin Commands\*\***

- https://www.makeuseof.com/shell-builtin-commands-in-linux/

### `cd`

- https://unix.stackexchange.com/questions/50022/why-cant-i-redirect-a-path-name-output-from-one-command-to-cd
- https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/

### Pipes & Redirectors

- https://wikiless.org/wiki/Pipeline\_(Unix)?lang=en
- https://wikiless.org/wiki/Unix_philosophy?lang=en
- https://devhints.io/bash
- https://stackoverflow.com/questions/9834086/what-is-a-simple-explanation-for-how-pipes-work-in-bash
- https://stackoverflow.com/questions/21287848/function-to-find-the-maximum-number-of-pipes
- https://linuxconfig.org/introduction-to-named-pipes-on-bash-shell
- https://linuxhint.com/bash_pipe_tutorial/
- https://www.delftstack.com/howto/linux/pipes-in-bash/
- https://devdocs.io/bash/
- https://dev.to/oyagci/shell-redirections-explained-2h9

### `< infile cmd`

Redirect `infile` ’s contents to `cmd` ’s `STDIN`

```bash
python hello.py < foo.txt      # feed foo.txt to stdin for python
diff <(ls -r) <(ls)            # Compare two stdout without files
```

### `cmd1 | cmd2`

Redirects previous `cmd1`'s `STDOUT` to `cmd2` ’s `STDIN`

```bash
ls -la | wc -l
```

### `cmd > outfile`

Truncates `outfile` with `cmd` ’s `STDOUT`

```bash
ls > output.txt   # stdout to (file)
ls >> output.txt  # stdout to (file), append
ls 2> error.log   # stderr to (file)
ls 2>&1           # stderr to stdout
ls 2>/dev/null    # stderr to (null)
ls &>/dev/null    # stdout and stderr to (null)
```

### Eval Order

- https://www.gnu.org/software/bash/manual/html_node/Pipelines.html
- https://www.gnu.org/software/bash/manual/html_node/Lists.html
- https://stackoverflow.com/questions/66511243/bash-pipe-execution-order
- https://unix.stackexchange.com/questions/37508/in-what-order-do-piped-commands-run
- https://linuxhint.com/bash_pipe_tutorial/

### Prompt

### Lexer

- https://en.wikipedia.org/wiki/Lexical_analysis
- https://github.com/Swoorup/mysh/blob/master/lexer.c
- https://towardsdatascience.com/why-are-there-so-many-tokenization-methods-for-transformers-a340e493b3a8
- https://nlp.stanford.edu/IR-book/html/htmledition/tokenization-1.html
- https://www.youtube.com/watch?v=SNyh-cubxaU

```bash
MAKE_PATH=./libs/libft
cd .. ; ls && make -C $MAKE_PATH ; ./minshell
```

### Expansor

- https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html
- https://pubs.opengroup.org/onlinepubs/9699919799.2008edition/utilities/V3_chap02.html

### Parser

- https://dev.to/oyagci/generating-a-parse-tree-from-a-shell-grammar-f1
- https://www.cs.princeton.edu/courses/archive/spring20/cos320/LL1/
- https://www.cs.princeton.edu/courses/archive/spring20/cos320/LR0/

### Executor

- https://github.com/librity/ft_pipex

### `export`

- https://unix.stackexchange.com/questions/130985/if-processes-inherit-the-parents-environment-why-do-we-need-export

---

# C

- https://stackoverflow.com/questions/2407605/c-warning-missing-sentinel-in-function-call
- https://people.cs.rutgers.edu/~pxk/416/notes/c-tutorials/index.html
- https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/

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

---

### Testers

- https://github.com/LucasKuhn/minishell_tester

### LEX (Lexer)

- https://en.wikipedia.org/wiki/Lex\_(software)
- https://github.com/ckshitij/LEX-AND-YACC

### YACC (Parser)

- https://en.wikipedia.org/wiki/Yacc
- https://en.wikipedia.org/wiki/LALR_parser
- https://www.geeksforgeeks.org/introduction-to-yacc/
- https://www.lysator.liu.se/c/ANSI-C-grammar-y.html
- https://stackoverflow.com/questions/613479/where-can-i-find-standard-bnf-or-yacc-grammar-for-c-language
- https://silcnitc.github.io/yacc.html
- https://gist.github.com/codebrainz/2933703

### GNU Bison (Parser)

- https://en.wikipedia.org/wiki/GNU_Bison
- https://www.gnu.org/software/bison/

### **ANTLR (Parser)**

- https://en.wikipedia.org/wiki/ANTLR
- https://github.com/antlr/antlr4
- https://www.antlr.org/

### Valgrind Quirks

- https://wiki.wxwidgets.org/Valgrind_Suppression_File_Howto
- https://stackoverflow.com/questions/16847385/valgrind-to-detect-memory-leak-in-child-process

### Valgrind Readline Leaks Supression

Publicado pelo Denny no Discord, link pra msg original:

- https://discord.com/channels/706206701598277681/805218563194355732/923621489079615489

Para ajudar na verificação dos leaks no minishell com o Valgrind,
eu montei um arquivo de supressão que limpa os erros que vêm do Readline.
À princípio está suprimindo 100% dos leaks do Readline no nosso minishell,
mas se ainda retornar algum leak nas funções dessa família,
me mandem pra gente ir atualizando esse arquivo e deixá-lo mais completo.
O uso é bem simples, só salvar o arquivo como **readline.supp** no diretório
do minishell e adicionar a flag abaixo quando chamar o valgrind:
**`--suppressions=readline.supp`**

```bash
{
   <Readline>
   Memcheck:Leak
   match-leak-kinds: reachable
   ...
   fun:readline
   ...
}
{
   <Readline>
   Memcheck:Leak
   match-leak-kinds: definite
   fun:malloc
   fun:xmalloc
   fun:rl_add_undo
   fun:rl_insert_text
   fun:_rl_insert_char
   fun:rl_insert
   fun:_rl_dispatch_subseq
   fun:readline_internal_char
   fun:readline
   ...
}
{
   <AddHistory>
   Memcheck:Leak
   match-leak-kinds: reachable
   fun:malloc
   fun:xmalloc
   fun:add_history
   ...
}
```

Quem tiver interesse em entender como funciona a supressão, segue um HowTo:

- https://wiki.wxwidgets.org/Valgrind_Suppression_File_Howto

### `echo`

- https://unix.stackexchange.com/questions/63658/redirecting-the-content-of-a-file-to-the-command-echo

### `ls` - Behind the Scenes

- https://levelup.gitconnected.com/what-happens-where-you-type-ls-l-in-a-linux-shell-98ad95430cbf
- https://dev.to/moez/what-happens-when-you-type-ls-l-in-the-shell-simpleshell-project-26kf
- https://medium.com/@dalzuga/what-happens-inside-the-bash-shell-when-you-enter-ls-l-54adb7cf61cb
- https://medium.com/@danielavasquez_77768/what-happens-when-you-type-ls-l-in-your-shell-2043c55530b6
- https://medium.com/basic-command-ls-linux/what-happens-when-you-type-ls-l-in-the-shell-df224d5c727e
- https://medium.com/meatandmachines/what-really-happens-when-you-type-ls-l-in-the-shell-a8914950fd73

### Computer History

- https://en.wikipedia.org/wiki/Computer_terminal
- https://en.wikipedia.org/wiki/Teleprinter
- https://www.youtube.com/watch?v=4RPtJ9UyHS0
- https://www.youtube.com/watch?v=6dME3wgaQpM
- https://www.youtube.com/watch?v=qundvme1Tik

### Binary Executable Exploit

- https://www.youtube.com/watch?v=WnqOhgI_8wA
