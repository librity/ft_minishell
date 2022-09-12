# Minishell Parser

- https://wikiless.org/wiki/Parsing?lang=en
- https://wikiless.org/wiki/Abstract_syntax_tree?lang=en
- https://wikiless.org/wiki/Parse_tree?lang=en
- https://dev.to/oyagci/generating-a-parse-tree-from-a-shell-grammar-f1
- https://www.cs.princeton.edu/courses/archive/spring20/cos320/LL1/
- https://www.cs.princeton.edu/courses/archive/spring20/cos320/LR0/

## Examples

```c
{"ls", "-la", "bar", "|", "grep", "main", ">", "output", NULL }

=> (t_dlist){
	{argv: {"ls", "-la", "bar"},  type: PT_EXEC},
	{                             type: PT_PIPE},
	{argv: {"grep", "main"},      type: PT_EXEC},
	{file: "output",              type: PT_TRUNCATE}
}
```

```c
{"<", "foo", "<", "foo", "grep", "<", "foo", "|", "ls", NULL }

=> (t_dlist){
	{file: "foo",                   type: PT_READ_FILE},
	{file: "foo",                   type: PT_READ_FILE},
	{argv: {"grep"},                type: PT_EXEC},
	{file: "foo",                   type: PT_READ_FILE},
	{                               type: PT_PIPE},
	{argv: {"ls"},                  type: PT_EXEC}
}
```

```c
{"<", "foo", "<", "grep", "<", "foo", "|", "ls", NULL }

=> (t_dlist){
	{file: "foo",                 type: PT_READ_FILE},
	{file: "grep"                 type: PT_READ_FILE},
	{file: "foo",                 type: PT_READ_FILE},
	{                             type: PT_PIPE},
	{argv: {"ls"},                type: PT_EXEC}
}
```

```c
{"<", "foo", "<<", "foo", "grep", "a", ">", "foo", ">>", "foo", "|", "ls", NULL }

=> (t_dlist){
	{file: "foo",                             type: PT_READ_FILE},
	{delimiter: "foo",                        type: PT_HEREDOC},
	{argv: {"grep", "a"},                     type: PT_EXEC},
	{file: "foo",                             type: PT_TRUNCATE},
	{file: "foo",                             type: PT_APPEND},
	{                                         type: PT_PIPE},
	{argv: {"ls"},                            type: PT_EXEC}
}
```

### Redirection in the middle of a command

```c
{
	"ls", "<", "README.md", "-l", "-a",
	"|",

	"grep", ">", "file", "read",
	NULL }

=> (t_dlist){
	{file: "README.md",                             type: PT_READ_FILE},
	{argv: {"ls", "-l", "-a"},                      type: PT_EXEC},
	{                                               type: PT_PIPE},
	{file: "file",                                  type: PT_TRUNCATE},
	{argv: {"grep", "read"},                        type: PT_EXEC},
}
```

## Resources

### YACC (Parser)

- https://en.wikipedia.org/wiki/Yacc
- https://en.wikipedia.org/wiki/LALR_parser
- https://www.geeksforgeeks.org/introduction-to-yacc/
- https://www.lysator.liu.se/c/ANSI-C-grammar-y.html
- https://stackoverflow.com/questions/613479/where-can-i-find-standard-bnf-or-yacc-grammar-for-c-language
- https://silcnitc.github.io/yacc.html
- https://gist.github.com/codebrainz/2933703

### GNU Bison (Parser)

- https://en.wikipedia.org/wiki/GNU_Bison
- https://www.gnu.org/software/bison/

### **ANTLR (Parser)**

- https://en.wikipedia.org/wiki/ANTLR
- https://github.com/antlr/antlr4
- https://www.antlr.org/
