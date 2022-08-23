# Minishell Trimmer

## Remover aspas simples

```c
"foo'bar'"
=> "foobar"

"'baz$foo'12''"
=> "baz$foo12"
```

## Remover aspas duplas

```c
"foo\"bar\""
=> "foobar"

"\"baz12\"12\"\""
=> "baz1212"
```

## Remover aspas simples e duplas

```c
"'foo\"bar\"'"
=> "foo\"bar\""

"\"baz12'12\"'"
=> "baz12'12'"
```
