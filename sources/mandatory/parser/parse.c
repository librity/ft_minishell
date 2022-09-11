/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 19:53:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	parse_redirections(t_parse_list **list, char **_tokens)
{
	char	*next_token;

	while (_tokens != NULL && *_tokens != NULL && !ft_streq(*_tokens, PIPE))
	{
		if (!is_operator(*_tokens))
		{
			_tokens++;
			continue ;
		}
		next_token = *(_tokens + 1);
		if (ft_streq(*_tokens, TRUNCATE))
			add_truncate(list, next_token);
		if (ft_streq(*_tokens, APPEND))
			add_append(list, next_token);
		if (ft_streq(*_tokens, READ_FILE))
			add_read_file(list, next_token);
		if (ft_streq(*_tokens, HEREDOC))
			add_heredoc(list, next_token);
		ft_strarr_cutn(_tokens, 2);
	}
}

t_parse_list	*parse(char **tokens)
{
	t_parse_list	*list;
	char			**next_pipe;
	char			**free_me;
	char			**_tokens;

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
		parse_redirections(&list, _tokens);
		add_exec(&list, _tokens);
		add_pipe(&list);
		_tokens = find_next_pipe(_tokens) + 1;
	}
	parse_redirections(&list, _tokens);
	add_exec(&list, _tokens);
	free(free_me);
	return (list);
}
