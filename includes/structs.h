/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:20:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 11:49:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <signal.h>
# include <stdint.h>
# include <termios.h>

# include <libft.h>

/******************************************************************************\
 * TERMIOS
\******************************************************************************/

typedef struct termios		t_termios;

/******************************************************************************\
 * SIGNALS
\******************************************************************************/

typedef struct sigaction	t_sigaction;
typedef void				(*t_signal)(int);

/******************************************************************************\
 * HASH TABLE
\******************************************************************************/

typedef struct s_hash_table
{
	t_dlist					**index_lists;
	int						size;
	int						count;
}							t_hash_table;

typedef struct s_ht_item
{
	char					*key;
	char					*value;
}							t_ht_item;

typedef void				(*t_ht_for_each_cb)(t_ht_item *);

/******************************************************************************\
 * FILES
\******************************************************************************/

typedef struct stat			t_stat;

typedef struct s_proc_fds
{
	int						input;
	int						output;
	int						error;
}							t_proc_fds;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

typedef struct s_minishell
{
	bool					debug;

	t_termios				original_tty_attr;
	t_sigaction				signal_action;

	int						argc;
	char					**argv;
	char					**envp;

	t_hash_table			*envht;
	char					*last_exit;
	int						line_count;

	t_proc_fds				ioe;

	t_list					*lalloc;
}							t_minishell;

/******************************************************************************\
 * LEXER
\******************************************************************************/

typedef enum e_lexed_variable
{
	KEY = 0,
	VALUE = 1,
}							t_lexed_variable;

/******************************************************************************\
 * PARSER
\******************************************************************************/

typedef enum e_parse_type
{
	PT_NULL = 0,
	PT_EXEC,
	PT_PIPE,
	PT_TRUNCATE,
	PT_APPEND,
	PT_READ_FILE,
	PT_HEREDOC,
}							t_parse_type;

typedef struct s_parse
{
	char					**tokens;
	char					*file_path;
	char					*delimiter;
	t_parse_type			type;
}							t_parse;

typedef t_dlist				t_parse_list;
typedef t_dlist				t_parse_node;

/******************************************************************************\
 * BUILTINS
\******************************************************************************/

typedef int					(*t_builtin)(char **);

/******************************************************************************\
 * EXECUTOR
\******************************************************************************/

typedef struct s_execute_pl
{
	int						**pipes;
	int						pipe_count;

	pid_t					*pids;
	int						pid_count;
}							t_execute_pl;

typedef struct s_execve
{
	char					*path;
	char					**argv;
	char					**envp;

	char					*cmd;
	char					**paths;

	int						code;
}							t_execve;

/******************************************************************************\
 * CRYPTO
\******************************************************************************/

typedef struct s_md5
{
	void					*message;
	size_t					msg_length;

	uint32_t				chunks;
	uint8_t					*padded_message;

	uint32_t				*digest;
}							t_md5;

typedef enum e_chuck_digest_ints
{
	_A = 0,
	_B = 1,
	_C = 2,
	_D = 3,
}							t_chuck_digest_ints;

#endif
