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
	{command: "ls", args: {"-la", "bar", NULL}, type: "executable"},
	{command: "|", args: NULL, type: "pipe"},
	{command: "grep", args: {"main", NULL}, type: "executable"},
	{command: ">", args: {"output", NULL}, type: "truncate"}
}
OU:
parser() => (t_tree) {
	{command: "|", args: NULL, type: "pipe"
		nexts: {
			{command: "ls", args: {"-la", "bar", NULL}, type: "executable"},
		}
	},
	{command: "|", args: NULL, type: "pipe"
		nexts: {
			{command: "grep", args: {"main", NULL}, type: "executable"},
			{command: ">", args: {"output", NULL}, type: "truncate"}
		}
	}
}

syntax() => true
executor()
```

```c
prompt() => "< foo < foo grep < foo | ls"
expander() => "< foo < foo grep < foo | ls"
lexer() => {"<", "foo", "<", "foo", "grep", "<", "foo", "|", "ls", NULL }
syntax() => true
trimmer() => {"<", "foo", "<", "foo", "grep", "<", "foo", "|", "ls", NULL }

parser() => (t_dlist){
	{command: "<", args: NULL, file: "foo", type: "read_file"},
	{command: "<", args: NULL, file: "foo", type: "read_file"},
	{command: "grep", args: NULL, type: "executable"},
	{command: "<", args: NULL, file: "foo", type: "read_file"},
	{command: "|", args: NULL, type: "pipe"},
	{command: "ls", args: NULL, type: "executable"}
}

syntax() => true
executor()
```

```c
prompt() => "< foo < grep < foo | ls"
expander() => "< foo < grep < foo | ls"
lexer() => {"<", "foo", "<", "grep", "<", "foo", "|", "ls", NULL }
syntax() => true
trimmer() => {"<", "foo", "<", "grep", "<", "foo", "|", "ls", NULL }

parser() => (t_dlist){
	{command: "<", args: NULL, file: "foo", type: "read_file"},
	{command: "<", args: NULL, file: "grep" type: "read_file"},
	{command: "<", args: NULL, file: "foo", type: "read_file"},
	{command: "|", args: NULL, type: "pipe"},
	{command: "ls", args: NULL, type: "executable"}
}

syntax() => true
executor()
```

```c
prompt() => "< foo << foo grep a > foo >> foo | ls"
expander() => "< foo << foo grep a > foo >> foo | ls"
lexer() => {"<", "foo", "<<", "foo", "grep", "a", ">", "foo", ">>", "foo", "|", "ls", NULL }
syntax() => true
trimmer() => {"<", "foo", "<<", "foo", "grep", "a", ">", "foo", ">>", "foo", "|", "ls", NULL }

parser() => (t_dlist){
	{command: "<", args: NULL, file: "foo", type: "read_file"},
	{command: "<<", args: NULL, delimiter: "foo", type: "heredoc"},
	{command: "grep", args: {"a", NULL}, type: "executable"},
	{command: ">", args: NULL, file: "foo", type: "truncate"},
	{command: ">>", args: NULL, file: "foo", type: "append"},
	{command: "|", args: NULL, type: "pipe"},
	{command: "ls", args: NULL, type: "executable"}
}

syntax() => true
executor()
```
