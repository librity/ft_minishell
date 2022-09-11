/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 14:56:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	add_last_exec(char **tokens, t_parse_list **plist)
{
	t_parse	*pnode;

	if (tokens == NULL || *tokens == NULL)
		return ;
	pnode = new_exec_pnode(tokens);
	ft_dlst_add(plist, pnode);
}

static bool	parsed_operator(char ***tokens, t_dlist **plist)
{
	char	*next_token;
	t_parse	*pnode;

	if (ft_streq(**tokens, PIPE))
	{
		pnode = new_pipe_pnode();
		ft_dlst_add(plist, pnode);
		*tokens += 1;
		return (true);
	}
	next_token = *(*tokens + 1);
	if (ft_streq(**tokens, TRUNCATE))
	{
		pnode = new_truncate_pnode(next_token);
		ft_dlst_add(plist, pnode);
		*tokens += 2;
		return (true);
	}
	if (ft_streq(**tokens, APPEND))
	{
		pnode = new_append_pnode(next_token);
		ft_dlst_add(plist, pnode);
		*tokens += 2;
		return (true);
	}
	if (ft_streq(**tokens, READ_FILE))
	{
		pnode = new_read_file_pnode(next_token);
		ft_dlst_add(plist, pnode);
		*tokens += 2;
		return (true);
	}
	if (ft_streq(**tokens, HEREDOC))
	{
		pnode = new_heredoc_pnode(next_token);
		ft_dlst_add(plist, pnode);
		*tokens += 2;
		return (true);
	}
	return (false);
}

t_parse_list	*parse(char **tokens)
{
	t_parse	*pnode;
	t_parse_list	*plist;
	char	**next_operator;
	int		exec_length;

	plist = NULL;
	while (tokens != NULL && *tokens != NULL)
	{
		if (parsed_operator(&tokens, &plist))
			continue ;
		next_operator = find_next_operator(tokens);
		if (next_operator == NULL)
			break ;
		exec_length = next_operator - tokens;
		pnode = new_exec_length_pnode(tokens, exec_length);
		ft_dlst_add(&plist, pnode);
		tokens = next_operator;
	}
	add_last_exec(tokens, &plist);
	return (plist);
}
