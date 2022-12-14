# - [x] Mandatory

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
  - [ ] Remove flag before submitting (`readline()` leaks).
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

## - [x] REPL

- [x] Ler commando do usu??rio
- [x] Expandir
- [x] Lexar
- [x] Vericar Sintaxe
- [x] Remover Aspas
- [x] Parsear
- [x] Executar
- [x] Repetir

## - [x] Mem??ria

- [x] Adicionar toda memoria do loop (REPL) no `lalloc()`
  - [x] Prompt
  - [x] Expander
  - [x] Lexer
  - [x] Parser
- [x] Liberar mem??ria antes de sair do loop com `free_lalloc()`
- [x] Remover todos os usos de `destroy_parse()`
- [x] Liberar histroy do readline com `rl_clear_history()`

## - [x] Vari??veis

- [x] Implementar uma Hash Table:
  - [x] Implementar uma fun????o criptogr??fica com poucas colis??es (`md5()`).
  - [x] Calcular o `index` de um elemento a partir da chave.
  - [x] Inicializar a Hash Table.
  - [x] Inicializar um elemento da Hash Table.
  - [x] Destruir a Hash Table.
  - [x] Destruir elementos da Hash Table (liberar mem??ria).
  - [x] Inserir uma vari??vel (chave + valor).
  - [x] Recuperar uma vari??vel a partir da chave.
  - [x] Deletar uma vari??vel a partir da chave.
  - [x] Lidar com colis??es (vari??veis com o mesmo `index`).
  - [x] Testar e tratar inputs inv??lidos (`NULL` `table`, `key`, `value`, etc.)
  - [x] Inserir array de string.
  - [x] Gerar array de strings com todas as vari??veis.
- [x] Definir `envht`.
- [x] Inserir `envp` no `envht` na inicializa????o do shell.
- [x] Gerar `envp` a partir do `envht` (para os `execve()`).

## - [x] Built-ins

- [x] Your shell must implement the following built-ins:
  - [x] `echo` with option `-n`
  - [x] `cd` with only a relative or absolute path
    - [x] Testar caminhos relativos.
    - [x] Testar caminhos absolutos.
    - [x] Sem argumentos vai para a `HOME`.
    - [x] Mostrar erro caso tenha mais de 1 argumento.
    - [x] Mostrar erro caso o caminho n??o existe.
    - [x] Mostrar erro caso o caminho n??o seja um diret??rio.
    - [x] Atualizar `PWD`.
    - [x] Atualizar `OLD_PWD`.
    - [ ] (OPCIONAL) `cd -` te leva ao `$OLD_PWD`.
  - [x] `pwd` with no options
  - [x] `export` with no options
    - [x] Sem argumentos, jogar as vari??veis na tela.
    - [x] Inserir uma ou mais vari??veis.
    - [x] Pular vari??veis sem atribui????o (sem `=`).
    - [x] Adicionar vari??vel com atribui????o e sem valor (`value = ""`).
    - [x] Verificar vari??vel sem chave com erro.
    - [x] Verificar vari??vel vazia com erro.
    - [x] Verificar nome de vari??vel com erro.
  - [x] `unset` with no options
  - [x] `env` with no options or arguments
    - [x] Mostrar erro caso tenha mais de 1 argumento.
  - [x] `exit` with no options
    - [x] Mostrar `exit`.
    - [x] Se n??o recebe argumento, utiliza o codigo de saida do ??ltimo commando (`last_exit`).
    - [x] Se recebe um argumento, utiliz??-lo como c??digo de saida.
    - [x] Mostrar erro caso tenha mais de 1 argumento.
    - [x] Se o argumento n??o ?? um n??mero retornar erro.
  - [x] (OPTIONAL) `help` prints a help message listing all commands

## - [x] Prompt

- [x] Display a prompt when waiting for a new command.
- [x] Adicionar PS1 (ex: `lgeniole@dev1:~/code/ft/minishell$`):
  - [x] Nome do usu??rio.
  - [x] Current dir.
    - [x] Com `~`.
  - [x] Com cores.
- [x] Have a working history.
  - [x] N??o adicionar linha vazia (`""`)
- [x] Handle `Ctrl-C`, `Ctrl-D` and `Ctrl-\` which should behave like in bash.
  - [x] In interactive mode:
    - [x] `Ctrl-C` displays a new prompt on a new line (`SIGINT` signal).
    - [x] `Ctrl-D` exits the shell (`EOF` no `STDIN`).
    - [x] `Ctrl-\` does nothing (`SIGQUIT` signal).
  - [x] No fork (processo filho):
    - [x] `Ctrl-C` (`SIGINT` signal).
    - [x] `Ctrl-D` (`EOF` no `STDIN`).
    - [x] `Ctrl-\` (`SIGQUIT` signal).
  - [ ] Criar e utilizar
    - [ ] `sigemptyset_or_die()`
    - [ ] `sigaction_or_die()`
    - [ ] `rl_on_new_line_or_die()`
    - [ ] `rl_replace_line_or_die()`
    - [ ] `rl_redisplay_or_die()`

## - [x] Expander

- [x] Handle environment variables (`$` followed by a sequence of characters) which should expand to their values.
- [x] Handle `$?` which should expand to the exit status of the most recently executed foreground pipeline.
  - [x] Adicionar vari??vel `last_exit` ao `t_minishell`.
  - [x] Inicializar `$?` com `"0"`.
  - [x] Verificar se a vari??vel ?? `$?` e inserir-la corretamente.
- [x] Casos:
  - [x] Sem vari??veis.
  - [x] Vari??vel que n??o existe.
  - [x] Vari??veis de ambiente.
  - [x] Vari??veis dentro de aspas simples.
  - [x] Vari??veis dentro de aspas duplas.
  - [x] Vari??veis dentro de aspas simples e duplas.
  - [x] String vazia.
  - [x] Ponteiro nulo.
  - [ ] (OPCIONAL) N??o expandir delimitador de heredoc.
  - [ ] (OPCIONAL) Expandir `~` para `$HOME` (Tilde Expansion).
- [x] Renomear Expansor para Expander

## - [x] Lexer

- [x] Not interpret unclosed quotes or special characters which are not required by the subject such as `\` (backslash) or `;` (semicolon).
- [x] Handle `'` (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- [x] Handle `"` (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for `$` (dollar sign).
- [x] Casos:
  - [x] Tokeniza????o simples
  - [x] Tokeniza????o com aspas simples `'`
  - [x] Tokeniza????o com aspas duplas `"`
  - [x] Tokeniza????o com aspas misturadas
  - [x] Tokeniza????o com aspas intercaladas
  - [x] Tokeniza????o com aspa avulsa
  - [x] Tokeniza????o por pipe `|`
  - [x] Tokeniza????o por redire????o truncada `>`
  - [x] Tokeniza????o por redire????o de entrada `<`
  - [x] Tokeniza????o por redire????o concatenada `>>`
  - [x] Tokeniza????o por redire????o heredoc `<<`
  - [ ] (OPCIONAL) Tokeniza????o por coment??rio `#`

## - [x] Parser

- [x] `t_parse`:
  - [x] Criar n?? para execut??vel.
  - [x] Criar n?? para pipe.
  - [x] Criar n?? para truncate.
  - [x] Criar n?? para append.
  - [x] Criar n?? para read file.
  - [x] Criar n?? para heredoc.
- [x] `t_parse_list`:
  - [x] Criar uma lista linkada onde cada n?? ?? um operador ou um execut??vel.
  - [x] Lidar com redirecionamentos intercalados.
- [ ] Fix `ft_dlst_addb_lalloc()` and `ft_dlst_add_lalloc()`.

## - [x] Syntax Validator

- [x] Aspas:
  - [x] Aspas simples que n??o fecham.
  - [x] Aspas duplas que n??o fecham.
- [x] Vari??veis:
  - [x] Nome de vari??veis n??o pode come??ar com n??mero.
  - [x] Nome de vari??veis n??o pode conter metacharacters:
    - `?`, `'`, `"`, `\`, `$`, <code>\`</code>, `=`, `*`, `@`, `~`, `<`, `>`, `(`, `)`, `!`, `|`, `&`, `;`, `space`, `newline`
- [x] Nome de arquivo:
  - [x] Linux: n??o pode conter `/`.
  - [x] N??o pode conter characters especias fora de aspas: `|`, `;`, <code>\`</code>, `(`, `)`, `!`, `!`.
- [x] Input do usu??rio:
  - [x] N??o pode ter `;` fora de aspas.
  - [x] N??o pode ter `\` fora de aspas.
  - [x] N??o pode ter `>` sem nome do arquivo.
  - [x] N??o pode ter `>>` sem nome do arquivo.
  - [x] N??o pode ter `<` sem nome do arquivo.
  - [x] N??o pode ter `<<` sem delimitador.
  - [x] N??o pode ter `<<` seguido de outro operador: `|`, `>`, `>>`, `<`, `<<`.
  - [x] N??o pode ter `|` sem pr??ximo commando.
  - [x] N??o pode ter `|` seguido de `|`.
  - [x] Primeiro token n??o pode ser `|`.
- [x] Validar sintaxe dos `char **tokens`
  - [x] (OPCIONAL) Com mensagens de erro.
- [ ] (OPCIONAL) Validar sintaxe da `t_parse_list plist`

## - [x] Trimmer

- [x] Remover aspas para o parser.
- [x] Casos:
  - [x] Remover aspas simples
  - [x] Remover aspas duplas
  - [x] N??o remover aspas simples dentro de aspas duplas.
  - [x] N??o remover aspas duplas dentro de aspas simples.

## - [x] Executor

- [x] Implement pipes (`|` character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- [x] Implement redirections:
  - [x] `<` should redirect input.
  - [x] `>` should redirect output.
  - [x] `heredoc`: `<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn???t have to update the history!
    - [x] Heredoc roda antes que todos os outros redirecionamentos.
    - [x] Resolver os leaks de mem??ria (`hdoc.c`).
  - [x] `>>` should redirect output in append mode.
- [x] Search and launch the right executable (based on the `PATH` variable or using a relative or an absolute path).
- [x] Executar pipe com `fork()` e redirecionamentos.
- [ ] Testar m??ltiplos redirecionamentos no mesmo pipe.
- [x] Executar todos os pipes de uma pipeline.
- [ ] Testar m??ltiplos redirecionamentos na mesma pipeline.
- [x] ??ltimo pipe ?? redirecionado para `STDOUT`.
- [x] Atualiza o `last_exit` com o exit status do foreground pipeline.
- [ ] Built-ins:
  - [x] Se o commando ?? um builtin execut??-lo antes busc??-lo no sistema.
  - [x] Se o commando ?? um builtin dentro de uma pipeline execut??-lo em um `fork()`.
  - [x] Se o commando ?? um builtin fora de uma pipeline execut??-lo sem `fork()`.
    - [x] Salvar e restaurar `STDIN`, `STDOUT` e `STDERR` no processo principal.
  - [ ] Testar m??ltiplos redirecionamentos no mesmo builtin.
  - [ ] Testar m??ltiplos redirecionamentos na mesma pipeline comm builtins.
- [x] Fechar fds de redirecionamento depois de executar o builtin isolado
- [x] Criar e utilizar `wait_or_die()` `waitpid_or_die()`
- [x] Executar pipes sem bloquear processos (`forks()` -> `waits()`)

# - [ ] Bonus

- [ ] Wildcards \* should work for the current working directory.
- [ ] && and || with parenthesis for priorities.
