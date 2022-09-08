# Minishell

- [Variables](./variables.md)
- [Built-ins](./built-ins.md)

## Interpreter

1. [Prompt](./prompt.md)
2. [Expander](./expander.md)
3. [Lexer](./lexer.md)
4. [Syntax](./syntax.md)
5. [Trimmer](./trimmer.md)
6. [Parser](./parser.md)
7. [Executor](./executor.md)

```c
prompt() => "ls -la $foo | grep main>output"
expander() => "ls -la bar | grep main>output"
lexer() => {"ls", "-la", "bar", "|", "grep", "main", ">", "output", NULL }
parser() => {
	{command: "ls", args: {"-la", "bar", NULL}, type: "executable"},
	{command: "|", args: NULL, type: "pipe"},
	{command: "grep", args: {"main", NULL}, type: "executable"},
	{command: ">", args: {"output", NULL}, type: "truncate"}
}
```
