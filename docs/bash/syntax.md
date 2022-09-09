# Bash Syntax

### Process Command

```bash
foo      # in dirs of PATH
/bin/foo # in root dir
bin/foo  # in the PWD (current dir)
./foo    # foo in the PWD (current dir)
```

### Meta Characters

- `'` `"` `\` `$` <code>\`</code> `=` `*` `@` `~` `?` `<` `>` `(` `)` `!` `|` `&` `;` `space` `newline`

### Quotes

- Signifies a character or characters is no longer special.
- Prevents the shell from interpreting the meta characters.

```bash
\  # Quotes the next character or starts an escape sequence
'' # Qoutes EVERY enclosed metacharacter
"" # Qoutes the enclosed metacharacters EXCEPT $ ` \ ! * @

# Examples:

# Run ls with argument '-la bin'
ls -la\ bin
# Run ls with argument '-la\ bin'
ls '-la\ bin'
# Run ls with argument '-labin'
ls -la\
bin
# Run foo with argument '$bar'
foo \$bar
# If bar=42 run foo with argument 'baz42'
foo "baz$bar"
```

---

## Pipes & Redirectors

- https://wikiless.org/wiki/Pipeline\_(Unix)?lang=en
- https://wikiless.org/wiki/Unix_philosophy?lang=en
- https://devhints.io/bash
- https://stackoverflow.com/questions/9834086/what-is-a-simple-explanation-for-how-pipes-work-in-bash
- https://stackoverflow.com/questions/21287848/function-to-find-the-maximum-number-of-pipes
- https://linuxconfig.org/introduction-to-named-pipes-on-bash-shell
- https://linuxhint.com/bash_pipe_tutorial/
- https://www.delftstack.com/howto/linux/pipes-in-bash/
- https://devdocs.io/bash/
- https://dev.to/oyagci/shell-redirections-explained-2h9

### File Redirection

- Redirects a command’s `STDIN`, `STDOUT` or `STDERR` a file or files

```bash
# Close fd 0 and open file for reading
< file
# Close fd 1 and open file for truncated writing
> file

# Examples:

# Run foo with arguments 'bar' and '35'
# Redirect STDIN to read from notes.txt
# Redirect STDOUT to write to /dev/null
foo bar 35 <notes.txt >/dev/null
```

### `< infile cmd`

Redirect `infile` ’s contents to `cmd` ’s `STDIN`

```bash
python hello.py < foo.txt      # feed foo.txt to stdin for python
diff <(ls -r) <(ls)            # Compare two stdout without files
```

### `cmd > outfile`

Truncates `outfile` with `cmd` ’s `STDOUT`

```bash
ls > output.txt   # stdout to (file)
ls >> output.txt  # stdout to (file), append
ls 2> error.log   # stderr to (file)
ls 2>&1           # stderr to stdout
ls 2>/dev/null    # stderr to (null)
ls &>/dev/null    # stdout and stderr to (null)
```

### Pipeline

- One or more commands separated by `|`

```bash
# Creates a pipe linking foo's STDOUT to bar's STDIN
foo | bar
# Creates a pipe linking foo's STDOUT and STDERR to bar's STDIN
foo |& bar

# Examples:

# Run ls with arguments '-la' and 'bin'
# Redirect its STDOUT to a pipe
# Run less with its STDIN reading from the pipe
ls -la bin | less

# Run ls with argument '-la'
# Redirect its STDOUT to a pipe, then to result.txt
# Run cat with its STDIN reading from the pipe
# Due to the double redirection cat doesn't recieve anything in STDIN
ls -la > result.txt | cat
```

### `cmd1 | cmd2`

Redirects previous `cmd1`'s `STDOUT` to `cmd2` ’s `STDIN`

```bash
ls -la | wc -l
```

---

### Command-list

- One or more pipelines separated and terminated by `;` `&` `&&` `||` or `newline`

```bash
# Examples:

# Run foo then run bar on the same shell
foo
bar
# Run foo then run bar on the same shell
foo ; bar
# Run foo asynchronously (background subshell) and run bar in the current shell
# Pipeline can't read from the terminal
foo & bar
# Runs foo in bg, runs bar, runs fizz, runs buzz in bg
foo & bar ; fizz ; buzz &
# Run bar if foo returns an exit status of zero (success).
foo && bar
# Run bar if foo returns a non-zero exit status (failure).
foo || bar
# In all cases, foo and bar can be single commands or pipelines.
foo | bar ; fizz | buzz
```

### Pipeline/Command-list Priority

- https://www.gnu.org/software/bash/manual/html_node/Pipelines.html
- https://www.gnu.org/software/bash/manual/html_node/Lists.html
- https://stackoverflow.com/questions/66511243/bash-pipe-execution-order
- https://unix.stackexchange.com/questions/37508/in-what-order-do-piped-commands-run
- https://linuxhint.com/bash_pipe_tutorial/

### Exit code/status

```bash
foo
if [ "$?" -eq "0" ]; then
   echo "foo command executed without an error"
fi

foo
if [ "$?" -ne "0" ]; then
   echo "foo command executed with an error"
fi
```

### Variables

```bash
# Set variable name to "01234567890abcdefgh"
name=01234567890abcdefgh
# Evaluate de value of name as a process command
$name
# Print the value of name
echo $name
# Print the value of name followed by "rocks"
echo ${name}rocks
# Print the value of name from the 8th character onwards
echo ${name:7}
# Double quotes expands the variable
echo "$name"
# Single quotes doesn't
echo '$name'
# Uninitialized variables expand to an empty string ""
echo $idontexist
```

### `if` and `while`

- Uses the last exit status `$?` of the `command_list` as its condition
- If exit status `$?` is `0` it’s considered `true`
- Else it’s considered `false`

```bash
if command_list then command_list fi
while command_list do command_list done
```

### Functions

- Functions and Variables exist on separate namespaces

```bash
function name () { command_list }
# OR
name () { command_list }
# Call function
name args
# Access parameters with $1, $2, $3, etc.
# Functions implicitly return the exit code of the last command
foo () { cd $2; ls $1; }
foo /bin /home
echo $?
# We can explicity set the exit code or exit early with return
baz () { cd $2; return 1 }
```

### _Function/Command Call Priority_

1. Function call
2. Built-in command
3. Process command
4. `foobarbaz: command not found`

### Brace Expansion

- `preamble{comma-separated-list}postscript`

```bash
# Exapnds to "fooapplebar foobananabar"
echo foo{apple,banana}bar
# Preamble and postscript are optional
echo {35,14,hi}barr
```

### `~` Expansion

- Expands to `$HOME`

### Command Substitution

- Execute command and save its `STDOUT` to a string

```bash
$(command_list)
`command_list`

# Use $() to nest command substitutions
echo $(echo foo $(echo bar))
echo `echo foo `echo bar``
```

### Arithmetic Substitution

- Does basic math

```bash
$((expression))

echo $((3 + 5))
echo $(((3 + 5) * 2))
foo=7
echo $((3 + $foo))
```

### Filename Expansion

- `*` match any character
- `?` match any single character

```bash
touch foo3bar fooADSADSASDADSDbar foobar fooack
echo foo*bar
echo foo?bar
echo foo*
```

### _Expansion/Substitution Priority_

1. Brace expansion
2. Tilde expansion
3. Variable expansion, arithmetic expansion, command substitution
   1. Evaluated inside out, from the most nested to the least
4. Filename expansion

### Subshell Execution

```bash
# Run command_list in a subshell
(command_list)

(cd /; ls -la;)
```

### Current Shell Execution

```bash
# Run command_list in the current shell
{command_list}

# Useful for having the same redirection on multiple commands
{ cd /; ls -la; } > result.txt
# Results in the same behavior. The first one spawns 2 subshells.
( cd /; ls -la; ) &
{ cd /; ls -la; } &
```

### HereDoc

- https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html#Here-Documents
- Delimiter is not expanded:

```bash
$ export foo=bar
$ << $foo
> asd
> asd
> bar
> $foo
```
