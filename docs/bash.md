# Bash

- https://www.gnu.org/savannah-checkouts/gnu/bash/manual/
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
