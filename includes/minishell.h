/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:01:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/18 23:02:05 by lpaulo-m         ###   ########.fr       */
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

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void		die(void);

#endif
