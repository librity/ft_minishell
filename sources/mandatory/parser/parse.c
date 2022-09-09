/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 17:50:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// {"ls", "-la", NULL}
t_plist	*parse(char **tokens)
{
	t_pnode		*pnode;
	t_plist		*plist;
	char		**next_operator;
	int		exec_length;

	plist = NULL;


	next_operator = find_next_operator(tokens);
	if (next_operator == NULL)
	{
		pnode = new_exec_pnode(tokens);
		ft_dlst_add(&plist, pnode);
		return (plist);
	}

	exec_length = next_operator - tokens;
	// ft_debug("exec_length= %d", exec_length);
	pnode = new_exec_length_pnode(tokens, exec_length);
	// {"ls", "-la", "|", "grep", "Makefile", NULL};
	ft_dlst_add(&plist, pnode);

	tokens = next_operator;
	if (ft_streq(*tokens, PIPE))
	{
		pnode = new_pipe_pnode();
		ft_dlst_add(&plist, pnode);
		tokens++;
	}
	// else if (ft_streq(*tokens, APPEND))
	// {

	// }
	next_operator = find_next_operator(tokens);
	if (next_operator == NULL)
	{
		pnode = new_exec_pnode(tokens);
		ft_dlst_add(&plist, pnode);
		return (plist);
	}

	return (plist);
}

static void	_destroy_pnode(void *pnode)
{
	destroy_pnode((t_pnode **)&pnode);
}

void	destroy_plist(t_plist **plist)
{
	ft_dlstclear(plist, &_destroy_pnode);
}
