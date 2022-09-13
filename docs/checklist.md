# Mandatory

- [ ] Don't turn in libs as submodules.
- [ ] Makefile should explicitly name all source files (`make dump_sources`).
- [ ] Make must compile without relinking
  - [ ] `make all` shouldn't recompile/rearchive any objects or sources.
  - [ ] Add `.keep` to object dirs
  - [ ] Create non-phony rule for each lib archive
- [ ] Follows `norminette 3.3.51`
- [ ] Compiles with workspace's `clang` (version `12.0.1`)
  - [ ] Switch Makefile's `CC`to `clang` before submitting.
- [ ] Compiles with `-Wall -Wextra -Werror`
- [ ] Makefile rules: `$(NAME)` `all` `clean` `fclean` `re`
- [ ] Should not quit unexpectedly (segmentation fault, bus error, double
      free, etc.)
- [ ] All allocated heap memory properly freed, no memory leaks.
  - [ ] Use gcc `-fsanitize=leak` flag.
  - [ ] Check memory leaks with `valgrind`.
- [ ] `.linux` file (42 Workspaces)
- [ ] Test in workspaces
- [ ] Program name `myshell`
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
  - [ ] https://github.com/LucasKuhn/myshell_tester

## Variáveis

- [x] Implementar uma Hash Table:
  - [x] Implementar uma função criptográfica com poucas colisões (`md5()`).
  - [x] Calcular o `index` de um elemento a partir da chave.
  - [x] Inicializar a Hash Table.
  - [x] Inicializar um elemento da Hash Table.
  - [x] Destruir a Hash Table.
  - [x] Destruir elementos da Hash Table (liberar memória).
  - [x] Inserir uma variável (chave + valor).
  - [x] Recuperar uma variável a partir da chave.
  - [x] Deletar uma variável a partir da chave.
  - [x] Lidar com colisões (variáveis com o mesmo `index`).
  - [x] Testar e tratar inputs inválidos (`NULL` `table`, `key`, `value`, etc.)
  - [x] Inserir array de string.
  - [x] Gerar array de strings com todas as variáveis.
- [x] Definir `envht`.
- [x] Inserir `envp` no `envht` na inicialização do shell.
- [x] Gerar `envp` a partir do `envht` (para os `execve()`).

## Built-ins

- [ ] Your shell must implement the following built-ins:
  - [ ] `echo` with option `-n`
  - [ ] `cd` with only a relative or absolute path
  - [ ] `pwd` with no options
  - [ ] `export` with no options
    - [ ] Verificar nome de variável com erro.
  - [ ] `unset` with no options
  - [ ] `env` with no options or arguments
  - [ ] `exit` with no options
  - [ ] (OPTIONAL) `help` prints a help message listing all commands

## Prompt

- [ ] Display a prompt when waiting for a new command.
- [ ] Have a working history.
- [ ] Handle `Ctrl-C`, `Ctrl-D` and `Ctrl-\` which should behave like in bash.
- [ ] In interactive mode:
  - [ ] `Ctrl-C` displays a new prompt on a new line.
  - [ ] `Ctrl-D` exits the shell.
  - [ ] `Ctrl-\` does nothing.

## Expander

- [ ] Handle environment variables (`$` followed by a sequence of characters) which should expand to their values.
- [x] Handle `$?` which should expand to the exit status of the most recently executed foreground pipeline.
  - [x] Adicionar variável `last_exit` ao `t_minishell`.
  - [x] Inicializar `$?` com `"0"`.
  - [x] Verificar se a variável é `$?` e inserir-la corretamente.
- [x] Casos:
  - [x] Sem variáveis.
  - [x] Variável que não existe.
  - [x] Variáveis de ambiente.
  - [x] Variáveis dentro de aspas simples.
  - [x] Variáveis dentro de aspas duplas.
  - [x] Variáveis dentro de aspas simples e duplas.
  - [x] String vazia.
  - [x] Ponteiro nulo.
  - [ ] Não expandir delimitador de heredoc.
- [x] Renomear Expansor para Expander

## Lexer

- [ ] Not interpret unclosed quotes or special characters which are not required by the subject such as `\` (backslash) or `;` (semicolon).
- [ ] Handle `'` (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- [ ] Handle `"` (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for `$` (dollar sign).
- [x] Casos:
  - [x] Tokenização simples
  - [x] Tokenização com aspas simples `'`
  - [x] Tokenização com aspas duplas `"`
  - [x] Tokenização com aspas misturadas
  - [x] Tokenização com aspas intercaladas
  - [x] Tokenização com aspa avulsa
  - [x] Tokenização por pipe `|`
  - [x] Tokenização por redireção truncada `>`
  - [x] Tokenização por redireção de entrada `<`
  - [x] Tokenização por redireção concatenada `>>`
  - [x] Tokenização por redireção heredoc `<<`
  - [ ] (OPCIONAL) Tokenização por comentário `#`

## Parser

- [x] `t_parse`:
  - [x] Criar nó para executável.
  - [x] Criar nó para pipe.
  - [x] Criar nó para truncate.
  - [x] Criar nó para append.
  - [x] Criar nó para read file.
  - [x] Criar nó para heredoc.
- [x] `t_parse_list`:
  - [x] Criar uma lista linkada onde cada nó é um operador ou um executável.
  - [x] Lidar com redirecionamentos intercalados.

## Syntax Validator

- [ ] Aspas:
  - [ ] Aspas simples que não fecham.
  - [ ] Aspas duplas que não fecham.
- [ ] Variáveis:
  - [ ] Nome de variáveis não pode começar com número.
  - [ ] Nome de variáveis não pode conter metacharacters:
    - `?`, `'`, `"`, `\`, `$`, <code>\`</code>, `=`, `*`, `@`, `~`, `<`, `>`, `(`, `)`, `!`, `|`, `&`, `;`, `space`, `newline`
- [ ] Nome de arquivo:
  - [ ] Linux: não pode conter `/`.
  - [ ] Não pode conter characters especias fora de aspas: `|`, `;`, <code>\`</code>, `(`, `)`, `!`, `!`.
- [ ] Input do usuário:
  - [ ] Não pode ter `;` fora de aspas.
  - [ ] Não pode ter `\` fora de aspas.
  - [ ] Não pode ter `>` sem nome do arquivo.
  - [ ] Não pode ter `>>` sem nome do arquivo.
  - [ ] Não pode ter `<` sem nome do arquivo.
  - [ ] Não pode ter `<<` sem delimitador.
  - [ ] Não pode ter `<<` seguido de outro operador: `|`, `>`, `>>`, `<`, `<<`.
  - [ ] Não pode ter `|` sem próximo commando.
  - [ ] Não pode ter `|` seguido de `|`.
  - [ ] Primeiro token não pode ser `|`.

## Trimmer

- [x] Remover aspas para o parser.
- [x] Casos:
  - [x] Remover aspas simples
  - [x] Remover aspas duplas
  - [x] Não remover aspas simples dentro de aspas duplas.
  - [x] Não remover aspas duplas dentro de aspas simples.

## Executor

- [ ] Implement pipes (`|` character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- [ ] Implement redirections:
  - [x] `<` should redirect input.
  - [x] `>` should redirect output.
  - [ ] `<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
  - [x] `>>` should redirect output in append mode.
- [x] Search and launch the right executable (based on the `PATH` variable or using a relative or an absolute path).
- [ ] Se o commando é um builtin executá-lo antes buscá-lo no sistema.

# Bonus

- [ ] && and || with parenthesis for priorities.
- [ ] Wildcards \* should work for the current working directory.
