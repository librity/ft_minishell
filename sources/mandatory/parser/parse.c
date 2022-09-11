/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 18:20:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	add_last_exec(char **tokens, t_parse_list **list)
{
	t_parse	*pnode;

	if (tokens == NULL || *tokens == NULL)
		return ;
	pnode = new_exec_parse(tokens);
	ft_dlst_add(list, pnode);
}

static void	parse_redirections(char **_tokens, t_parse_list **list)
{
	char	*next_token;
	t_parse	*pnode;

	while (_tokens != NULL && *_tokens != NULL && !ft_streq(*_tokens, PIPE))
	{
		if (!is_operator(*_tokens))
		{
			_tokens++;
			continue ;
		}
		next_token = *(_tokens + 1);
		if (ft_streq(*_tokens, TRUNCATE))
		{
			pnode = new_truncate_parse(next_token);
			ft_dlst_add(list, pnode);
		}
		if (ft_streq(*_tokens, APPEND))
		{
			pnode = new_append_parse(next_token);
			ft_dlst_add(list, pnode);
		}
		if (ft_streq(*_tokens, READ_FILE))
		{
			pnode = new_read_file_parse(next_token);
			ft_dlst_add(list, pnode);
		}
		if (ft_streq(*_tokens, HEREDOC))
		{
			pnode = new_heredoc_parse(next_token);
			ft_dlst_add(list, pnode);
		}
		ft_strarr_cut(_tokens);
		ft_strarr_cut(_tokens);
	}
}

t_parse_list	*parse(char **tokens)
{
	t_parse			*pnode;
	t_parse_list	*list;
	char			**next_pipe;
	char			**free_me;
	char			**_tokens;
	int				exec_length;

	if (tokens == NULL)
		return (NULL);
	list = NULL;
	free_me = ft_strarr_dup_shallow(tokens);
	_tokens = free_me;
	while (true)
	{
		next_pipe = find_next_pipe(_tokens);
		if (next_pipe == NULL || *next_pipe == NULL)
			break ;

		parse_redirections(_tokens, &list);
		next_pipe = find_next_pipe(_tokens);

		exec_length = next_pipe - _tokens;
		if (exec_length > 0)
		{
			pnode = new_exec_length_parse(_tokens, exec_length);
			ft_dlst_add(&list, pnode);
		}

		pnode = new_pipe_parse();
		ft_dlst_add(&list, pnode);

		_tokens = next_pipe + 1;
	}

	parse_redirections(_tokens, &list);
	add_last_exec(_tokens, &list);

	free(free_me);
	return (list);
}
