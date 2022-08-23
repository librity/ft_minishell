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
"export foo=4 bar=2"
```
