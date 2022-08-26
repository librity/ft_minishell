### Dicas do `anjose-d`

1. Lexer
2. Parser
3. Interpretar e executar os builtins
4. Pipes
5. Executor
6. Heredoc
7. Readline ou implementação própia

### Dicas do `vwildner`

- Erro quando recebe argumento `if (argc != 1) ft_die();`.
- Usar `enum` já no lexer para escapar metacharacters.
- Pensar em como tratar o `cat | cat | ls`.
- Fazer Pair Programming com TDD:
  - https://marketplace.visualstudio.com/items?itemName=MS-vsliveshare.vsliveshare-pack
- Definir as responsabilidades de cada abstração do Minishell.
- Definir interfaces e assinaturas comuns, e trabalhar encima delas:
  - Exemplo:
    - Todos os built-ins recebem a mesma `struct`.
    - Definir a entrada de cada etapa do Minishell:
      - O que o lexer recebe
      - O que o expansor recebe
      - etc.
- Aspas que não fecham:
  - 3 opções:
    - Erro de sintaxe.
    - `rl_on_new_line()` talvez?
    - Tratar como se fosse um heredoc (`while` + `gnl()`/`readline()` + `strchr()`)
      - Não recomendado.
- Lexer MUITO robusto:
  - Mini `Lex`/`Yacc`/`Bison`.
  - Vai demorar.
