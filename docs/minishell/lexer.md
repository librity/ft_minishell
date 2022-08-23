# Minishell Lexer

## Tokenização simples

```c
"ls -la .."
=> "ls", "-la", ".."

"ls -la .. | cat -e | wc -l"
=> "ls", "-la", "..", "|", "cat", "-e", "|", "wc", "-l"

"MAKE_PATH=./libs/libft ; cd .. ; ls && make -C $MAKE_PATH ; ./minshell"
=> "infile", "<", "tr", "a", "'   '", "|", "tr", "' '", "x", ">", "outfile"
```

## Tokenização com aspas simples

```c
"infile   < tr a '   ' |   tr ' ' x > outfile"
=> "infile", "<", "tr", "a", "\"   \"", "|", "tr", "\" \"", "x", ">", "outfile"

".gitignore < tr ex ' X' | tr pi 'P ' > outfile"
=> ".gitignore", "<", "tr", "ex", "' X'", "|", "tr", "pi", "'P '", ">", "outfile"
```

## Tokenização com aspas duplas

```c
"infile   < tr a \"   \" |   tr \" \" x > outfile"
=> "infile", "<", "tr", "a", "\"   \"", "|", "tr", "\' \'", "x", ">", "outfile"
```

## Tokenização com aspas misturadas

```c
"infile   < tr a \"   \" |   tr \' \' x > outfile"
=> "infile", "<", "tr", "a", "\"   \"", "|", "tr", "\' \'", "x", ">", "outfile"
```

## Tokenização com aspas intercaladas

```c
"infile   < tr a \"   \' |   tr \' \" x > outfile"
=> "infile", "<", "tr", "a", "\"   \' |   tr \' \"", "x", ">", "outfile"

"infile   < tr a   \'  \"   \' |   tr \' \"     \' x > outfile"
=> "infile", "<", "tr", "a", "\'  \"   \' |   tr \' \"     \'", "x", ">", "outfile"
```

## Tokenização com aspa avulsa

```c
"inf'ile"
=> "inf'ile"

"inf\"ile"
=> "inf\"ile"

"infile   < tr a   \'  \"   \' |   tr \' \"      x > outfile"
=> "infile", "<", "tr", "a", "\'  \"   \' |   tr \' \"      x > outfile"
```

O prompt do `bash` continua recebendo bytes até receber outra aspa.
Já que vamos usar `readline()` não é necessário/possível tratar isso,
e basta considerar o token com a aspa avulsa.

## Tokenização por pipe `|`

```c
"help| rg unset"
=> "help", "|", "rg", "unset"

"help|rg unset"
=> "help", "|", "rg", "unset"
```

## Tokenização por redireção truncada `>`

```c
"ls> out"
=> "ls", ">", "out"

"ls>out"
=> "ls", ">", "out"
```

## Tokenização por redireção de entrada `<`

```c
"out<rg ."
=> "out", "<", "rg", "."

"cat<out"
=> "cat", "<", "out"

"<cat out"
=> "<", "cat", "out"

"<out rg '.'"
=> "<", "out", "rg", "'.'"
```

## Tokenização por redireção concatenada `>>`

```c
"rg a>>out"
=> "rg", "a", ">>", "out"
```

## Tokenização por redireção heredoc `<<`

```c
"<<. cat"
=> "<<", ".", "cat"

"cat<<."
=> "cat" "<<", "."
```

## (OPCIONAL) Tokenização por comentário `#`

```c
"ls -la#comment"
=> "ls", "-la"
```

## Resources

- https://en.wikipedia.org/wiki/Lexical_analysis
- https://github.com/Swoorup/mysh/blob/master/lexer.c
- https://towardsdatascience.com/why-are-there-so-many-tokenization-methods-for-transformers-a340e493b3a8
- https://nlp.stanford.edu/IR-book/html/htmledition/tokenization-1.html
- https://www.youtube.com/watch?v=SNyh-cubxaU

### The Extended ASCII Myth

- https://www.joelonsoftware.com/2003/10/08/the-absolute-minimum-every-software-developer-absolutely-positively-must-know-about-unicode-and-character-sets-no-excuses/
- https://www.quora.com/How-can-I-print-extended-ASCII-characters-in-C
- https://stackoverflow.com/questions/618332/c-extended-ascii-characters
- https://www.ascii-code.com/
- https://en.wikipedia.org/wiki/Extended_ASCII
- https://en.wikipedia.org/wiki/Input_method
- https://en.wikipedia.org/wiki/Unicode
- https://medium.com/bobble-engineering/emojis-from-a-programmers-eye-ca65dc2acef0
- https://en.wikipedia.org/wiki/Emoji

### Finite State Machine

- https://stackoverflow.com/questions/5491775/how-to-write-a-shell-lexer-by-hand
- https://en.wikipedia.org/wiki/Finite-state_machine

### LEX (Lexer)

- https://en.wikipedia.org/wiki/Lex\_(software)
- https://github.com/ckshitij/LEX-AND-YACC
