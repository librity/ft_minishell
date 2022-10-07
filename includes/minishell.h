/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:42:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/07 11:15:51 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

# include <libft.h>

# include <defines.h>
# include <errors.h>

typedef struct s_minishell
{
	bool	debug;

	int		argc;
	char	**argv;
	char	**envp;

	char	*line_cmd;
	char	**tokens;

	char	**paths;

	t_list	*lalloc;
}			t_minishell;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_minishell	*c(void);
void		initialize_control(int argc, char **argv, char **envp);

bool		debug(void);
void		set_debug(bool verbose);

int			argc(void);
char		**argv(void);
char		**envp(void);

void		initalize_paths(void);
char		*rtn_path_index(int index);
//criar uma função pra deleta os caminhos


char		*line_cmd(void);
void		set_line_cmd(char *input);
void		destroy_line_cmd(void);

char		**tokens(void);
char		*token_index(int index);
void		token_edit(int index, char *str);

t_list		**lalloc(void);
void		free_memory(void);

/******************************************************************************\
 * READLINE
\******************************************************************************/

int			init_shell(void);
void		get_line(void);

char		*get_cmd_line(char	*tmp);

bool		vf_clone_quote(char *line);

/******************************************************************************\
 * LEXER
\******************************************************************************/

char		**lex(void);
char		**tokenize(char *input);

char		*skip_single_quotes(char *line);
char		*skip_double_quotes(char *line);

char		*insert_around_two(char *line);
char		*insert_around_one(char *line);
char		*insert_delimiter(char *line);

void		insert_delimiter_before(char *buffer);
void		insert_delimiter_after(char *buffer);
void		insert_delimiter_around(char *buffer);
void		insert_delimiter_around_2(char *buffer);

void		strbuff_insert_before(char *buffer, char insert_me);
void		strbuff_insert_after(char *buffer, char insert_me);
void		strbuff_insert_around(char *buffer, char insert_me);
void		strbuff_insert_around_2(char *buffer, char insert_me);

bool		at_single_quote(char *line);
bool		at_double_quote(char *line);
bool		at_pipe(char *line);
bool		at_space(char *line);
bool		at_truncate(char *line);
bool		at_append(char *line);
bool		at_read_file(char *line);
bool		at_heredoc(char *line);

/******************************************************************************\
 * FILES
\******************************************************************************/

int			close_or_die(int close_me);

/******************************************************************************\
 * PIPES
\******************************************************************************/

void		pipe_or_die(int pipe_fds[2]);
void		close_pipe(int pipe_fds[2]);

void		stdin_to_pipe(int pipe_fds[2]);
void		pipe_to_stdin(int pipe_fds[2]);

void		stdout_to_pipe(int pipe_fds[2]);
void		pipe_to_stdout(int pipe_fds[2]);

void		file_to_stdin(int infile_fd);
void		stdout_to_file(int outfile_fd);

void		str_to_pipe(int pipe_fds[2], char *str);

/******************************************************************************\
 * FORKS
\******************************************************************************/

pid_t		fork_or_die(void);

/******************************************************************************\
 * RUNTIME
\******************************************************************************/

void		die(char *error_message);
void		free_and_die(void *free_me, char *error_message);
void		free_arr_and_die(char **free_me, char *error_message);

void		print_error(char *message);
void		print_warning(char *message);

#endif
