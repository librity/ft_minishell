/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:27:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 15:52:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_GENERIC "Error"

/******************************************************************************\
 * CONTROL
\******************************************************************************/

# define ENVP_TO_ENVHT_ERR "Can't initialize envht from envp variables."

/******************************************************************************\
 * SYNTAX
\******************************************************************************/

# define SYNTAX_ERR "minishell: syntax error near unexpected token `%s'\n"
# define QUOTES_ERR "Line doesn't have closing quotes."

/******************************************************************************\
 * EXECUTOR
\******************************************************************************/

# define FORK_ERR "Can't fork required process."
# define FORK_LOC "fork"

# define PATHS_ERR "Can't get paths from environment variable."

# define EXECUTE_NULL_ERR "Can't execute NULL tokens."
# define NO_CMD_ERR "command not found"

# define HEREDOC_DELIMITER_ERR "Can't read a heredoc with NULL delimiter."
# define HEREDOC_LOC "heredoc"

# define EXEC_BAD_TOKENS_ERR "Can't execute command with NULL or empty tokens."

# define PERMISSION_ERR "Permission denied"

# define IS_DIR_ERR "Is a directory"

# define WAIT_LOC "wait"
# define WAITPID_LOC "waitpid"

/******************************************************************************\
 * FILES
\******************************************************************************/

# define DUP_ERR "Can't duplicate required file descriptor."
# define DUP_LOC "dup"

# define DUP2_ERR "Can't redirect required file descriptor."
# define DUP2_LOC "dup2"

# define CLOSE_ERR "Can't close required file descriptor."
# define CLOSE_LOC "close"

# define STAT_LOC "stat"

/******************************************************************************\
 * PIPES
\******************************************************************************/

# define PIPE_ERR "Can't create required pipe."
# define PIPE_LOC "pipe"

/******************************************************************************\
 * BUILTINS
\******************************************************************************/

# define BAD_BUILTIN_ERR "Can't execute unsupported builtin."

# define NO_FILE_DIR_ERR "No such file or directory"
# define TOO_MANY_ARGS_ERR "too many arguments"

# define CD_NULL_TOKENS 1
# define CD_TOO_MANY_ARGS 1
# define CD_NO_FILE_OR_DIR 1
# define CD_PWD_UPDATE 2
# define CD_OLD_PWD_UPDATE 3

# define CD_NULL_PATH_ERR "CD_NULL_PATH"

# define ENV_NO_ARGS 1
# define ENV_TOO_MANY_ARGS 127

# define ECHO_BAD_TOKENS 1

# define UNSET_BAD_TOKENS 1

# define PWD_BAD_TOKENS 1
# define PWD_TOO_MANY_ARGS 1
# define PWD_MISSING_PWD_ENV_VAR 1

# define EXPORT_BAD_TOKENS 1
# define EXPORT_BAD_VARIABLE 1

# define EXIT_BAD_TOKENS 1
# define EXIT_BAD_STATUS 2
# define EXIT_TOO_MANY_ARGS 1

# define HELP_BAD_TOKENS 1

/******************************************************************************\
 * TERMIOS
\******************************************************************************/

# define TTY_EMPTY_ATTR_ERR "Original tty attributes are empty."
# define TTY_GET_ATTR_ERR "Can't get original tty attributes."
# define TTY_SET_ATTR_ERR "Can't set raw mode tty attributes."
# define TTY_RESTORE_ATTR_ERR "Can't restore original tty attributes."

# define READ_KEY_ERR "Can't read next input key from STDIN_FILENO."

#endif
