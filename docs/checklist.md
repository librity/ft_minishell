# Mandatory

- [ ] Don't turn in libs as submodules.
- [ ] Makefile should explicitly name all source files (`make dump_sources`).
- [ ] Make must compile without relinking
  - [ ] `make all` shouldn't recompile/rearchive any objects or sources.
  - [ ] Add `.keep` to object dirs
  - [ ] Create non-phony rule for each lib archive
- [ ] Follows `norminette 3.3.51`
- [ ] Compiles with workspace's `cc` (`clang` version `12.0.1`)
  - [ ] Switch Makefile's `clang-12` to `CC` before submitting.
- [ ] Compiles with `-Wall -Wextra -Werror`
- [ ] Makefile rules: `$(NAME)` `all` `clean` `fclean` `re`
- [ ] Should not quit unexpectedly (segmentation fault, bus error, double
      free, etc.)
- [ ] All allocated heap memory properly freed, no memory leaks.
  - [ ] Use gcc `-fsanitize=leak` flag.
  - [ ] Check memory leaks with `valgrind`.
- [x] `.linux` file (42 Workspaces)
- [ ] Test in workspaces
- [x] Program name `minishell`
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
- [x] Not use more than one global variable. Think about it. You will have to explain its purpose.
- [ ] Pass all testers
  - [ ] https://github.com/LucasKuhn/myshell_tester
    - [ ] Habilitar testes desativados (`pipes_bckp` e `redirects_bckp`).
- [ ] Add `debug()` messages:
  - [x] Prompt
  - [x] Expander
  - [x] Lexer
  - [x] Syntax Validator
  - [x] Trimmer
  - [x] Parser
  - [ ] Executor
- [x] Add `-d` and `--debug` flags (`./minishell -d`)

## REPL

- [x] Ler commando do usuário
- [x] Expandir
- [x] Lexar
- [x] Vericar Sintaxe
- [x] Remover Aspas
- [x] Parsear
- [x] Executar
- [x] Repetir

## Memória

- [x] Adicionar toda memoria do loop (REPL) no `lalloc()`
  - [x] Prompt
  - [x] Expander
  - [x] Lexer
  - [x] Parser
- [x] Liberar memória antes de sair do loop com `free_lalloc()`
- [x] Remover todos os usos de `destroy_parse()`
- [x] Liberar histroy do readline com `rl_clear_history()`

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

- [x] Your shell must implement the following built-ins:
  - [x] `echo` with option `-n`
  - [x] `cd` with only a relative or absolute path
    - [x] Testar caminhos relativos.
    - [x] Testar caminhos absolutos.
    - [x] Sem argumentos vai para a `HOME`.
    - [x] Mostrar erro caso tenha mais de 1 argumento.
    - [x] Mostrar erro caso o caminho não existe.
    - [x] Mostrar erro caso o caminho não seja um diretório.
    - [x] Atualizar `PWD`.
    - [x] Atualizar `OLD_PWD`.
    - [ ] (OPCIONAL) `cd -` te leva ao `$OLD_PWD`.
  - [x] `pwd` with no options
  - [x] `export` with no options
    - [x] Sem argumentos, jogar as variáveis na tela.
    - [x] Inserir uma ou mais variáveis.
    - [x] Pular variáveis sem atribuição (sem `=`).
    - [x] Adicionar variável com atribuição e sem valor (`value = ""`).
    - [x] Verificar variável sem chave com erro.
    - [x] Verificar variável vazia com erro.
    - [x] Verificar nome de variável com erro.
  - [x] `unset` with no options
  - [x] `env` with no options or arguments
    - [x] Mostrar erro caso tenha mais de 1 argumento.
  - [x] `exit` with no options
    - [x] Mostrar `exit`.
    - [x] Se não recebe argumento, utiliza o codigo de saida do último commando (`last_exit`).
    - [x] Se recebe um argumento, utilizá-lo como código de saida.
    - [x] Mostrar erro caso tenha mais de 1 argumento.
    - [x] Se o argumento não é um número retornar erro.
  - [x] (OPTIONAL) `help` prints a help message listing all commands

## Prompt

- [x] Display a prompt when waiting for a new command.
- [ ] Adicionar PS1 (ex: `lgeniole@dev1:~/code/ft/minishell$`):
  - [x] Nome do usuário.
  - [ ] Hostname.
  - [x] Current dir.
  - [ ] Com cores.
- [x] Have a working history.
  - [x] Não adicionar linha vazia (`""`)
- [ ] Handle `Ctrl-C`, `Ctrl-D` and `Ctrl-\` which should behave like in bash.
  - [x] In interactive mode:
    - [x] `Ctrl-C` displays a new prompt on a new line (`SIGINT` signal).
    - [x] `Ctrl-D` exits the shell (`EOF` no `STDIN`).
    - [x] `Ctrl-\` does nothing (`SIGQUIT` signal).
  - [ ] No fork (processo filho):
    - [ ] `Ctrl-C` (`SIGINT` signal).
    - [ ] `Ctrl-D` (`EOF` no `STDIN`).
    - [ ] `Ctrl-\` (`SIGQUIT` signal).
  - [ ] Criar e utilizar
    - [ ] `sigemptyset_or_die()`
    - [ ] `sigaction_or_die()`
    - [ ] `rl_on_new_line_or_die()`
    - [ ] `rl_replace_line_or_die()`
    - [ ] `rl_redisplay_or_die()`

## Expander

- [x] Handle environment variables (`$` followed by a sequence of characters) which should expand to their values.
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
  - [ ] (OPCIONAL) Não expandir delimitador de heredoc.
  - [ ] (OPCIONAL) Expandir `~` para `$HOME` (Tilde Expansion).
- [x] Renomear Expansor para Expander

## Lexer

- [x] Not interpret unclosed quotes or special characters which are not required by the subject such as `\` (backslash) or `;` (semicolon).
- [x] Handle `'` (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- [x] Handle `"` (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for `$` (dollar sign).
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
- [ ] Fix `ft_dlst_addb_lalloc()` and `ft_dlst_add_lalloc()`.

## Syntax Validator

- [x] Aspas:
  - [x] Aspas simples que não fecham.
  - [x] Aspas duplas que não fecham.
- [x] Variáveis:
  - [x] Nome de variáveis não pode começar com número.
  - [x] Nome de variáveis não pode conter metacharacters:
    - `?`, `'`, `"`, `\`, `$`, <code>\`</code>, `=`, `*`, `@`, `~`, `<`, `>`, `(`, `)`, `!`, `|`, `&`, `;`, `space`, `newline`
- [x] Nome de arquivo:
  - [x] Linux: não pode conter `/`.
  - [x] Não pode conter characters especias fora de aspas: `|`, `;`, <code>\`</code>, `(`, `)`, `!`, `!`.
- [x] Input do usuário:
  - [x] Não pode ter `;` fora de aspas.
  - [x] Não pode ter `\` fora de aspas.
  - [x] Não pode ter `>` sem nome do arquivo.
  - [x] Não pode ter `>>` sem nome do arquivo.
  - [x] Não pode ter `<` sem nome do arquivo.
  - [x] Não pode ter `<<` sem delimitador.
  - [x] Não pode ter `<<` seguido de outro operador: `|`, `>`, `>>`, `<`, `<<`.
  - [x] Não pode ter `|` sem próximo commando.
  - [x] Não pode ter `|` seguido de `|`.
  - [x] Primeiro token não pode ser `|`.
- [x] Validar sintaxe dos `char **tokens`
  - [ ] Com mensagems de erro.
- [ ] (OPCIONAL) Validar sintaxe da `t_parse_list plist`

## Trimmer

- [x] Remover aspas para o parser.
- [x] Casos:
  - [x] Remover aspas simples
  - [x] Remover aspas duplas
  - [x] Não remover aspas simples dentro de aspas duplas.
  - [x] Não remover aspas duplas dentro de aspas simples.

## Executor

- [x] Implement pipes (`|` character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- [ ] Implement redirections:
  - [x] `<` should redirect input.
  - [x] `>` should redirect output.
  - [ ] `heredoc`: `<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
    - [ ] Heredoc roda antes que todos os outros redirecionamentos, possivelmente dentro do processo pai.
    - [ ] Resolver os leaks de memória (`hdoc.c`).
  - [x] `>>` should redirect output in append mode.
- [x] Search and launch the right executable (based on the `PATH` variable or using a relative or an absolute path).
- [x] Executar pipe com `fork()` e redirecionamentos.
- [ ] Testar múltiplos redirecionamentos no mesmo pipe.
- [x] Executar todos os pipes de uma pipeline.
- [ ] Testar múltiplos redirecionamentos na mesma pipeline.
- [x] Último pipe é redirecionado para `STDOUT`.
- [x] Atualiza o `last_exit` com o exit status do foreground pipeline.
- [ ] Built-ins:
  - [x] Se o commando é um builtin executá-lo antes buscá-lo no sistema.
  - [x] Se o commando é um builtin dentro de uma pipeline executá-lo em um `fork()`.
  - [x] Se o commando é um builtin fora de uma pipeline executá-lo sem `fork()`.
    - [x] Salvar e restaurar `STDIN`, `STDOUT` e `STDERR` no processo principal.
  - [ ] Testar múltiplos redirecionamentos no mesmo builtin.
  - [ ] Testar múltiplos redirecionamentos na mesma pipeline comm builtins.
- [x] Fechar fds de redirecionamento depois de executar o builtin isolado
  - [ ] Com testes
- [x] Criar e utilizar `wait_or_die()` `waitpid_or_die()`
- [x] Executar pipes sem bloquear processos (`forks()` -> `waits()`)

# Bonus

- [ ] && and || with parenthesis for priorities.
- [ ] Wildcards \* should work for the current working directory.
