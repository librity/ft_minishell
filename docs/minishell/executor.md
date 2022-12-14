# Minishell Executor

- https://github.com/librity/ft_pipex

## Examples

- Prints the last command THEN hangs the shell for input.

```bash
$ cat | cat | ls
agile     docs      includes  LICENSE  Makefile   objects        README.md  snippets  test
archives  examples  libs      main.c   minishell  readline.supp  scripts    sources   tests
das
das
```

```bash
$ grep < Makefile < main.c main
# /*   main.c                                             :+:      :+:    :+:   */
# int     main(int argc, char **argv, char **envp)
```

```bash
$ grep < Makefile < main.c < Makefile main
# M_MAIN = ./main.c
```

```bash
$ grep << Makefile < main.c < Makefile main
# > Makefile
# M_MAIN = ./main.c
```

```bash
$ grep << Makefile < main.c main
# > Makefile
# /*   main.c                                             :+:      :+:    :+:   */
# int     main(int argc, char **argv, char **envp)
```

```bash
$ grep << Makefile < main.cdsad < Makefile main
# > Makefile
# -bash: main.cdsad: No such file or directory
```

```bash
$ grep < main.cdsad << Makefile < Makefile main
# > Makefile
# -bash: main.cdsad: No such file or directory
```

```bash
$ grep < main.cdsad < Makefile main
# -bash: main.cdsad: No such file or directory
```

```bash
$ grep << Makefile < main.cdsad < Makefile main
# Makefile
# -bash: main.cdsad: No such file or directory
```

```bash
$ grep << Makefile < main.cdsad < Makefile main
# > main
# > main
# > Makefile
# -bash: main.cdsad: No such file or directory
```

```bash
$ grep < main.cds < Makefile <main.c main
# -bash: main.cds: No such file or directory
```

```bash
$ grep << Makefile < main.c < Makefile main
# main
# Makefile
# M_MAIN = ./main.c
```

```bash
$ grep << m < main.c < Makefile main
# > dsa
# > main
# > main main
# > m
# M_MAIN = ./main.c
```

```bash
$ grep < main.cds < Makefile <main.c main | cat
# -bash: main.cds: No such file or directory
```

```bash
$ grep < main.c < Makefile <main.c main | cat
# /*   main.c                                             :+:      :+:    :+:   */
# int     main(int argc, char **argv, char **envp)
```

```bash
$ grep < main.c << m < Makefile <main.c main | cat
# > main
# > m
# /*   main.c                                             :+:      :+:    :+:   */
# int     main(int argc, char **argv, char **envp)
```

```bash
$ grep < main.c < Makefile <main.c main | ls
# archives  docs  examples  includes  libs  LICENSE  main.c  Makefile  minishell  objects  readline.supp  README.md  scripts  snippets  sources  tests
```

```bash
$ grep < main.c << m < Makefile <main.c main | ls
# > dsa
# > m
# archives  docs  examples  includes  libs  LICENSE  main.c  Makefile  minishell  objects  readline.supp  README.md  scripts  snippets  sources  tests
```

### Heredoc

- Heredoc runs before all redirections.

```bash
$ grep < p << l a | cat
> l
# -bash: p: No such file or directory
```

```bash
$ grep << p < p << l a | cat
> p
> l
# -bash: p: No such file or directory
```

- Uses last heredoc

```bash
$ grep << p << l a | cat
> a
> b
> l
> abc
> p
> a
> v
> aaaaa
> l
# a
# aaaaa
```

- Uses last heredoc

```bash
$ grep << p < main.c << l a | cat
> a
> a
> a
> l
> p
> a
> a
> aaaaa
> l
# a
# a
# aaaaa
```

- Except if there's an input redirection afterwards

```bash
$ grep << p << l < main.c a | cat
> a
> aa
> p
> sd
> as
> l
# /*   main.c                                             :+:      :+:    :+:   */
# /*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
# ...
```

# aaaaa

- Built-ins outside a pipeline don't run in a fork.

```bash
lgeniole@dev1:~/code/ft/minishell$ cd sources/
lgeniole@dev1:~/code/ft/minishell/sources$
```

- All Built-ins run in forks if part of a pipeline

```bash
lgeniole@dev1:~/code/ft/minishell$ echo oi | cd sources
lgeniole@dev1:~/code/ft/minishell$
```

```bash
$ export abc=2 | export dfg=3
$ echo $abc $dfg

```

## Resources

### Pipes and File Descriptors

- https://stackoverflow.com/questions/50669417/piping-to-stdout
- https://stackoverflow.com/questions/31074433/can-i-dump-stdin-with-gdb
- https://unix.stackexchange.com/questions/115313/dump-processs-stdin-and-stdout
- https://www.rozmichelle.com/pipes-forks-dups/

### Clear `STDIN`

- https://stackoverflow.com/questions/36715002/how-to-clear-stdin-before-getting-new-input
