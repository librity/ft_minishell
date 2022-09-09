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
prompt() => "< ds < ds grep < ds | ls"
expander() => "< ds < ds grep < ds | ls"
lexer() => {"<", "ds", "<", "ds", "grep", "<", "ds", "|", "ls", NULL }
syntax() => true
trimmer() => {"<", "ds", "<", "ds", "grep", "<", "ds", "|", "ls", NULL }

parser() => (t_dlist){
	{command: "<", args: NULL, file: "ds", type: "read_file"},
	{command: "<", args: NULL, file: "ds", type: "read_file"},
	{command: "grep", args: NULL, type: "executable"},
	{command: "<", args: NULL, file: "ds", type: "read_file"},
	{command: "|", args: NULL, type: "pipe"},
	{command: "ls", args: NULL, type: "truncate"}
}

syntax() => true
executor()
```

```c
prompt() => "< ds < grep < ds | ls"
expander() => "< ds < grep < ds | ls"
lexer() => {"<", "ds", "<", "grep", "<", "ds", "|", "ls", NULL }
syntax() => true
trimmer() => {"<", "ds", "<", "grep", "<", "ds", "|", "ls", NULL }

parser() => (t_dlist){
	{command: "<", args: NULL, file: "ds", type: "read_file"},
	{command: "<", args: NULL, file: "grep" type: "read_file"},
	{command: "<", args: NULL, file: "ds", type: "read_file"},
	{command: "|", args: NULL, type: "pipe"},
	{command: "ls", args: NULL, type: "truncate"}
}

syntax() => true
executor()
```

```c
prompt() => "< ds << ds grep a > ds >> ds | ls"
expander() => "< ds << ds grep a > ds >> ds | ls"
lexer() => {"<", "ds", "<<", "ds", "grep", "a", ">", "ds", ">>", "ds", "|", "ls", NULL }
syntax() => true
trimmer() => {"<", "ds", "<<", "ds", "grep", "a", ">", "ds", ">>", "ds", "|", "ls", NULL }

parser() => (t_dlist){
	{command: "<", args: NULL, file: "ds", type: "read_file"},
	{command: "<<", args: NULL, delimiter: "ds", type: "heredoc"},
	{command: "grep", args: {"a", NULL}, type: "executable"},
	{command: ">", args: NULL, file: "ds", type: "truncate"},
	{command: ">>", args: NULL, file: "ds", type: "append"},
	{command: "|", args: NULL, type: "pipe"},
	{command: "ls", args: NULL, type: "truncate"}
}

syntax() => true
executor()
```
