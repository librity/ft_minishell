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
