# Mandatory

- [ ] Don't turn in libs as sobmodules.
- [ ] Makefile should explicitly name all source files (`make dump_sources`).
- [ ] Make must compile without relinking
  - [ ] `make all` shouldn't recompile/rearchive any objects or sources.
  - [ ] Add `.keep` to object dirs
  - [ ] Create non-phony rule for each lib archive
- [ ] Follows `norminette 3.3.51`
- [ ] Compiles with `-Wall -Wextra -Werror`
- [ ] Makefile rules: `$(NAME)` `all` `clean` `fclean` `re`
- [ ] Should not quit unexpectedly (segmentation fault, bus error, double
      free, etc.)
- [ ] All allocated heap memory properly freed, no memory leaks.
  - [ ] Use gcc `-fsanitize=leak` flag.
  - [ ] Check memory leaks with `valgrind`.
- [ ] `.linux` file (42 Workspaces)
- [ ] Test in workspaces
- [ ] Program name `minishell`
- [ ] Turn in `Makefile`, `*.h`, `*.c` , `.linux` , `.gitignore`
- [ ] Allowed functions:
  - [ ] `readline` `rl_clear_history` `rl_on_new_line` `rl_replace_line`
  - [ ] `rl_redisplay` `add_history` `printf` `malloc` `free` `write` `access`
  - [ ] `open` `read` `close` `fork` `wait` `waitpid` `wait3` `wait4` `signal`
  - [ ] `sigaction` `sigemptyset` `sigaddset` `kill` `exit` `getcwd` `chdir`
  - [ ] `stat` `lstat` `fstat` `unlink` `execve` `dup` `dup2` `pipe` `opendir`
  - [ ] `readdir` `closedir` `strerror` `perror` `isatty` `ttyname` `ttyslot`
  - [ ] `ioctl` `getenv` `tcsetattr` `tcgetattr` `tgetent` `tgetflag` `tgetnum`
  - [ ] `tgetstr` `tgoto` `tputs`
  - [ ] `libft` allowed
- [ ] Not use more than one global variable. Think about it. You will have to explain its purpose.
- [ ] Pass all testers
  - [ ] https://github.com/LucasKuhn/minishell_tester

### Prompt

- [ ] Display a prompt when waiting for a new command.
- [ ] Have a working history.
- [ ] Handle `Ctrl-C`, `Ctrl-D` and `Ctrl-\` which should behave like in bash.
- [ ] In interactive mode:
  - [ ] `Ctrl-C` displays a new prompt on a new line.
  - [ ] `Ctrl-D` exits the shell.
  - [ ] `Ctrl-\` does nothing.

### Lexer

- [ ] Not interpret unclosed quotes or special characters which are not required by the subject such as `\` (backslash) or `;` (semicolon).
- [ ] Handle `'` (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- [ ] Handle `"` (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for `$` (dollar sign).

### Expansor

- [ ] Handle environment variables (`$` followed by a sequence of characters) which should expand to their values.
- [ ] Handle `$?` which should expand to the exit status of the most recently executed foreground pipeline.

### Parser

- [ ] Implement pipes (`|` character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- [ ] Implement redirections:
  - [ ] `<` should redirect input.
  - [ ] `>` should redirect output.
  - [ ] `<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
  - [ ] `>>` should redirect output in append mode.

### Executor

- [ ] Search and launch the right executable (based on the `PATH` variable or using a relative or an absolute path).
- [ ] Your shell must implement the following builtins:
  - [ ] `echo` with option `-n`
  - [ ] `cd` with only a relative or absolute path
  - [ ] `pwd` with no options
  - [ ] `export` with no options
  - [ ] `unset` with no options
  - [ ] `env` with no options or arguments
  - [ ] `exit` with no options

# Bonus

- [ ] && and || with parenthesis for priorities.
- [ ] Wildcards \* should work for the current working directory.
