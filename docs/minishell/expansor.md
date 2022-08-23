# Minishell Expansor

## Sem variáveis

```c
"foo'bar'"
=> "foo'bar'"
```

## Variáveis de ambiente

```c
"$EDITOR"
=> "nano"

"bar$EDITOR"
=> "barnano"
```

## Variáveis dentro de aspas simples

```c
export foo=42

"'$foo'"
=> "'$foo'"

"baz$foo'bar'"
=> "baz42'bar'"

"baz$foo'$foo'"
=> "baz42'$foo'"
```

## Variáveis dentro de aspas duplas

```c
export foo=42

"\"$foo\""
=> "\"42\""

"baz$foo\"$foo\""
=> "baz42\"42\""
```

## Variáveis dentro de aspas simples e duplas

```c
export foo=42

"baz$foo\"$foo'\""
=> "baz42\"42'\""

"\"baz$foo'$foo'\""
=> "\"baz42'42'\""

"'baz$foo'$foo''"
=> "'baz$foo'42''"
```

## (OPCIONAL) Variáveis locais/do processo

```c
foo=42

"$foo"
=> "42"

"bar$foo"
=> "bar42"
```

## Resources

- https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html
- https://pubs.opengroup.org/onlinepubs/9699919799.2008edition/utilities/V3_chap02.html

### Hash Table

- https://en.wikipedia.org/wiki/Hash_table
- https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
- https://medium.com/omarelgabrys-blog/hash-tables-2fec6870207f
- https://stackoverflow.com/questions/730620/how-does-a-hash-table-work
- https://benhoyt.com/writings/hash-table-in-c/
