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

### Examples

```c
prompt() => "ls -la $foo | grep \"main\">output"
expander() => "ls -la bar | grep \"main\">output"
lexer() => {"ls", "-la", "bar", "|", "grep", "\"main\"", ">", "output", NULL }
syntax() => true
trimmer() => {"ls", "-la", "bar", "|", "grep", "main", ">", "output", NULL }
parser() => (t_dlist){
	{tokens: {"ls", "-la", "bar", NULL}, type: "executable"},
	{tokens: "|", type: "pipe"},
	{tokens: {"grep", "main", NULL}, type: "executable"},
	{tokens: ">", file: "output", type: "truncate"}
}
syntax() => true
executor()
```
