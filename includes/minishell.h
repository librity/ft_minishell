/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:42:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 19:19:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>

# include <defines.h>

typedef struct s_minishell
{
	bool	debug;

	int		argc;
	char	**argv;
	char	**envp;

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

t_list		**lalloc(void);
void		free_memory(void);

/******************************************************************************\
 * LEXER
\******************************************************************************/

char		**lex(char *input);
char		**tokenize(char *input);

char		*skip_single_quotes(char *line);
char		*skip_double_quotes(char *line);

char		*insert_pipe_delimiters(char *line);
char		*insert_greater_than_delimiters(char *line);
char		*insert_less_than_delimiters(char *line);
char		*insert_delimiter(char *line);

void		insert_char_before(char *buffer, char c);
void		insert_char_after(char *buffer, char c);
void		insert_char_around(char *buffer, char c);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void		die(void);

#endif
