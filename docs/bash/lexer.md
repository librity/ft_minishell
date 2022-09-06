# Bash Lexer

## Attributions

- Doesn't tokenize attributions until execution.

```bash
$ ls baz=ds
# ls: cannot access 'baz=ds': No such file or directory
$ ls baz="ds"
# ls: cannot access 'baz=ds': No such file or directory
```
