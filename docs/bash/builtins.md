# Bash Built-ins

- https://www.makeuseof.com/shell-builtin-commands-in-linux/
- Executed in the shell or subshell
- Can be redirected/piped like a process command
  - Built-ins receive a duplicate of `STDIN`, `STDOUT` and `STDERR`

## `help`

- Prints the general usage and lists built-ins
- Can also print built-in-specific help: `help echo`

## `echo`

- https://unix.stackexchange.com/questions/63658/redirecting-the-content-of-a-file-to-the-command-echo
- Writes arguments to `STDOUT`
- `-n` flag doesn’t append a new line

```bash
# Prints "foo 3245\n" to STDOUT
echo foo 3245
# Prints "foo 3245" to STDOUT
echo -n foo 3245
# Prints "foo 3245 -n\n" to STDOUT
echo foo 3245 -n
```

## `cd`

- https://unix.stackexchange.com/questions/50022/why-cant-i-redirect-a-path-name-output-from-one-command-to-cd
- https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/
- Set the shell’s current working directory
- Forks and subshells inherit the parent’s working directory

## `pwd`

- Print the shell’s current directory

## `export`

- https://unix.stackexchange.com/questions/130985/if-processes-inherit-the-parents-environment-why-do-we-need-export
- https://superuser.com/questions/821094/what-is-the-difference-between-set-env-declare-and-export-when-setting-a-varia/1404741#1404741
- Marks a shell variable as an environment variable
- Forks and subshells inherit environment variables

```bash
run_in_tandem () {
	echo '========================================='
	echo -n "SUBSHELL: "
	bash -c 'echo $foo baz'
	echo -n "PARENT SHELL: "
	echo $foo baz
}

# Unset foo to reset test
unset foo

# Declare foo and expand it on parent and sub shell
foo=8
run_in_tandem

# Export foo to access it on the subshell
export foo
run_in_tandem

# Changing the value of foo also changes the environment variable
foo=10
run_in_tandem
```

### Arguments

```bash
# One variable
$ export foo=4

# Multiple variable
$ export foo=4 bar=2 baz=fizz

# Print all exported vars (like env but with the "declare -x")
$ export
declare -x ALACRITTY_LOG=/tmp/Alacritty-3396198.log
declare -x ALACRITTY_SOCKET=/run/user/1000/Alacritty-:1-3396198.sock
declare -x COLORTERM=truecolor
...

# Empty exported variables show up on export but not on env
$ export empty
$ export | grep empty
declare -x empty
$ env | grep empty

$ export not_empty=42
$ export | grep not_empty
declare -x not_empty="42"
$ env | grep not_empty
not_empty=42
```

## `unset`

- Uninitializes variable: removes it from local variables and environment variables

```bash
# Initializes buzz
buzz=dsa
echo $buzz
# Exports buzz
export buzz
echo $buzz
# Uninitializes buzz
unset buzz
echo $buzz
```

## `env`

- Prints all environment variables
- Not a built-in in Ubuntu

```bash
# Initialize bozia
unset bozia
bozia=42
env | grep bozia
# Export bozia
export bozia
env | grep bozia
# Uninitialize bozia
unset bozia
env | grep bozia
```

## `exit`

- Exits the shell
- C `exit()`
- Same as `Ctrl+D`

## `jobs`, `bg` and `fg`

![Shell Session and Jobs](./jobs.png)

- Shell starts as a session with one foreground job in the controlling terminal
- Background jobs receive the `SIGTTIN` when they try to read from the controlling terminal
- `Ctrl+Z` sends `SIGTSTP` to the foreground job and `SIGCONT` to processes of the next job, moving them to the foreground
- `jobs` list background jobs and their job number
- `bg job_number` send `SIGCONT` to a background job
- `fg job_number` send `SIGCONT` to a background job and move it to the foreground

## `source`

- Executes commands from the file in the current shell

```bash
# This is what happens when you create a new shell
source ~/.bashrc
```

## Shebang

- Tells the executor to run the script with the specified interpreter

```bash
#!/bin/bash
#!/bin/python
#!/bin/perl
#!/bin/ruby
```
