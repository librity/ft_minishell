# Minishell Built-ins

## `echo`

```c
"echo    '  \"   'sdsa dasd asd a"
=> "  \"   sdsa dasd asd a\n"

"echo    '  \"   'sdsa dasd asd a|cat"
=> "  \"   sdsa dasd asd a\n"

"echo    '  \"   'sdsa dasd asd a|cat"
=> "  \"   sdsa dasd asd a\n"

"echo      \"   sdsa dasd asd a|cat"
=> "   sdsa dasd asd a|cat\n"

"echo      \"   sdsa dasd asd      a|cat"
=> "   sdsa dasd asd      a|cat"

"echo         sdsa dasd asd a|cat"
=> "sdsa dasd asd a\n"

"echo         sdsa dasd asd a$cat"
=> "sdsa dasd asd a\n"

"echo         sdsa dasd asd a$cat das"
=> "sdsa dasd asd a das\n"

"echo         sdsa dasd asd a$cat           das"
=> "sdsa dasd asd a das\n"

"echo  -n        sdsa dasd asd a$cat           das"
=> "sdsa dasd asd a das"

"echo          sdsa dasd asd a$cat           das -n"
=> "sdsa dasd asd a das -n\n"
```

## `export`

```c
// One variable
"export foo=4"

// Multiple variable
"export foo=4 bar=2 baz=fizz"

// Print all exported vars (like env but with the "declare -x")
"export"
=> "declare -x ALACRITTY_LOG=\"/tmp/Alacritty-3396198.log\"
declare -x ALACRITTY_SOCKET=\"/run/user/1000/Alacritty-:1-3396198.sock\"
declare -x COLORTERM=\"truecolor\"
...
"
```

## `cat`

- Prints the last command THEN hangs the shell for input.

```bash
$ cat | cat | ls
agile     docs      includes  LICENSE  Makefile   objects        README.md  snippets  test
archives  examples  libs      main.c   minishell  readline.supp  scripts    sources   tests
das
das
```
