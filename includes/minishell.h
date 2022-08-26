/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:42:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/26 19:52:07 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <defines.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_minishell
{
	bool	debug;

	int		argc;
	char	**argv;
	char	**envp;

	t_list	*lalloc;
}			t_minishell;

# define MAX_PATH 256

/******************************************************************************\
 * Colors
\******************************************************************************/

#define NOC "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define BLACK "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define VIOLET "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

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

t_list		**lalloc(void);
void		free_memory(void);

/******************************************************************************\
 * LEXER
\******************************************************************************/

char		**lex(char *input);
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
 * ERRORS
\******************************************************************************/

void		die(void);

#endif
