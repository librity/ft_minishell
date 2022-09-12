# Minishell

- [Variables](./variables.md)
- [Built-ins](./builtins.md)

## Interpreter

1. [Prompt](./prompt.md)
2. [Expander](./expander.md)
3. [Lexer](./lexer.md)
4. [Parser](./parser.md)
5. [Syntax](./syntax.md)
6. [Trimmer](./trimmer.md)
7. [Executor](./executor.md)

### Examples

```c
prompt() => "ls -la $foo | grep \"main\">output"
expander() => "ls -la bar | grep \"main\">output"
lexer() => {"ls", "-la", "bar", "|", "grep", "\"main\"", ">", "output", NULL }
syntax() => true
parser() => (t_dlist){
	{argv: {"ls", "-la", "bar", NULL},  type: "executable"},
	{                                   type: "pipe"},
	{argv: {"grep", "\"main\"", NULL},  type: "executable"},
	{file: "output",                    type: "truncate"}
}
syntax() => true
trimmer() => (t_dlist){
	{argv: {"ls", "-la", "bar", NULL},  type: "executable"},
	{                                   type: "pipe"},
	{argv: {"grep", "main", NULL},      type: "executable"},
	{file: "output",                    type: "truncate"}
}
executor()
```
