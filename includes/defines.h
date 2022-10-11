/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 16:46:04 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
 * CONTROL
\******************************************************************************/

# define DEFAULT_LAST_EXIT 0
# define LAST_EXIT_KEY "?"

/******************************************************************************\
 * ASCII
\******************************************************************************/

# define NULL_CHAR '\0'
# define EQUALS '='
# define SPACE ' '
# define DOLLAR '$'
# define QUESTION '?'
# define SEMICOLON ';'

# define SINGLE_QUOTE '\''
# define DOUBLE_QUOTE '\"'

# define VERTICAL_BAR '|'

# define GREATER_THAN '>'
# define LESS_THAN '<'

# define EMPTY_STR ""

/******************************************************************************\
 * OPERATORS
\******************************************************************************/

# define PIPE "|"

# define TRUNCATE ">"
# define APPEND ">>"

# define READ_FILE "<"
# define HEREDOC "<<"

/******************************************************************************\
 * LEXER
\******************************************************************************/

# define DELIMITER -42

# define TOKENS_DEBUG_MESSAGE "Lexed string \"%s\" into tokens:"

/******************************************************************************\
 * SYNTAX
\******************************************************************************/

# define METACHARS "?\'\"\\$`=*@~<>()!|&; \n"
# define SPECIALCHARS "|;`()!&"

/******************************************************************************\
 * EXECUTOR
\******************************************************************************/

# define CHILD_PROCESS_ID 0

# define PATH_KEY "PATH"

# define HDOC_FEED "> "

# define EKEYEXPIRED 127

/******************************************************************************\
 * BUILTINS
\******************************************************************************/

# define BI_ECHO "echo"
# define BI_ECHO_NO_LINEBREAK_FLAG "-n"

# define CD "cd"
# define HOME_KEY "HOME"

# define PWD "pwd"
# define PWD_KEY "PWD"
# define OLDPWD_KEY "OLDPWD"

# define EXPORT "export"

# define UNSET "unset"

# define ENV "env"

# define EXIT "exit"

# define HELP "help"
# define HELP_MSG "Welcome to lpaulo-m's and wwallas-'s minishell!\n\
\
\033[0;33m \n\
USAGE: \033[0m\n\
	[REDIRECTIONS] [COMMAND] [ARGS] | [REDIRECTIONS] [COMMAND] ...\n\
\033[0;33m \n\
\
BUILT-INS: \033[0m \n\
\
\033[1;32m	help \033[0m\n\
		Print this help message.\n\
\n\
\
\033[1;32m	echo [-n] [arg ...] \033[0m\n\
		Display the ARGs, separated by a single space character and followed \
by a newline, on the standard output.\n\
\n\
\
\033[1;32m	cd [dir] \033[0m\n\
		Change the current directory to DIR. \
		The default DIR is the value of the HOME shell variable.\n\
\n\
\
\033[1;32m	pwd \033[0m\n\
		Print the path of the current working directory.\n\
\n\
\
\033[1;32m	export [name[=value] ...] \033[0m\n\
		Marks each NAME for automatic export to the environment \
of subsequently executed commands. \n\
		If VALUE is supplied, assign VALUE before exporting.\n\
\n\
		If no arguments are supplied, prints all environment variables. \n\
\n\
\
\033[1;32m	unset [name ...] \033[0m\n\
		Unset values and attributes of shell variables.\n\
\n\
\
\033[1;32m	env \033[0m\n\
		Prints all environment variables.\n\
\n\
\
\033[1;32m	exit [n] \033[0m\n\
		Exits the shell with a status of N. \n\
		If N is omitted, uses the exit status of the last executed command.\n\
\n\
\
"

/******************************************************************************\
 * FILES
\******************************************************************************/

# define CREATE_PERMISSION 0000664

/******************************************************************************\
 * PIPES
\******************************************************************************/

# define PIPE_READ 0
# define PIPE_WRITE 1

/******************************************************************************\
 * HASH TABLE
\******************************************************************************/

# define HASH_TABLE_SIZE 10000
# define HT_BAD_INDEX -1

/******************************************************************************\
 * CRYPTO
\******************************************************************************/

# define ONE_BIT 0b10000000
# define NULL_BYTE 0b00000000

# define MD5_DIGEST_SIZE 16
# define MD5_HASH_SIZE 33

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

# define MINISHELL_PREFIX "minishell: "
# define PRINT_ERROR_PREFIX "minishell: ERROR: "
# define PRINT_WARNING_PREFIX "minishell: WRNNG: "

/******************************************************************************\
 * EXPAND
\******************************************************************************/

#define DOLLA_SEGUENCE_INVALID " \0\""

#endif
