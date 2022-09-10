/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 22:45:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_plist	*parse(char **tokens)
{
	t_pnode	*pnode;
	t_plist	*plist;
	char	*next_token;
	char	**next_operator;
	int		exec_length;

	plist = NULL;
	while (tokens != NULL && *tokens != NULL)
	{
		if (ft_streq(*tokens, PIPE))
		{
			pnode = new_pipe_pnode();
			ft_dlst_add(&plist, pnode);
			tokens++;
			continue ;
		}
		if (ft_streq(*tokens, TRUNCATE))
		{
			next_token = *(tokens + 1);
			pnode = new_truncate_pnode(next_token);
			ft_dlst_add(&plist, pnode);
			tokens += 2;
			continue ;
		}
		if (ft_streq(*tokens, APPEND))
		{
			next_token = *(tokens + 1);
			pnode = new_append_pnode(next_token);
			ft_dlst_add(&plist, pnode);
			tokens += 2;
			continue ;
		}
		if (ft_streq(*tokens, READ_FILE))
		{
			next_token = *(tokens + 1);
			pnode = new_read_file_pnode(next_token);
			ft_dlst_add(&plist, pnode);
			tokens += 2;
			continue ;
		}
		if (ft_streq(*tokens, HEREDOC))
		{
			next_token = *(tokens + 1);
			pnode = new_heredoc_pnode(next_token);
			ft_dlst_add(&plist, pnode);
			tokens += 2;
			continue ;
		}
		next_operator = find_next_operator(tokens);
		if (next_operator == NULL)
			break ;
		exec_length = next_operator - tokens;
		pnode = new_exec_length_pnode(tokens, exec_length);
		ft_dlst_add(&plist, pnode);
		tokens = next_operator;
	}
	if (*tokens == NULL)
		return (plist);
	pnode = new_exec_pnode(tokens);
	ft_dlst_add(&plist, pnode);
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
