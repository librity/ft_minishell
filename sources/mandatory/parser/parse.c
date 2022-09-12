/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/12 13:03:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	parse_redirections(t_parse_list **list, char **tokens)
{
	char	*next_token;

	while (tokens != NULL && *tokens != NULL)
	{
		if (!is_operator(*tokens))
		{
			tokens++;
			continue ;
		}
		if (ft_streq(*tokens, PIPE))
			break ;
		next_token = *(tokens + 1);
		if (ft_streq(*tokens, TRUNCATE))
			add_truncate(list, next_token);
		if (ft_streq(*tokens, APPEND))
			add_append(list, next_token);
		if (ft_streq(*tokens, READ_FILE))
			add_read_file(list, next_token);
		if (ft_streq(*tokens, HEREDOC))
			add_heredoc(list, next_token);
		ft_strarr_cutn(tokens, 2);
	}
}

static void	parse_exec(t_parse_list **list, char **tokens)
{
	parse_redirections(list, tokens);
	add_exec(list, tokens);
}

static void	parse_tokens(t_parse_list **list, char **tokens)
{
	int	pipe_count;

	pipe_count = count_pipes(tokens);
	while (pipe_count > 0)
	{
		parse_exec(list, tokens);
		add_pipe(list);
		tokens = find_next_pipe(tokens) + 1;
		pipe_count--;
	}
	parse_exec(list, tokens);
}

t_parse_list	*parse(char **tokens)
{
	t_parse_list	*list;
	char			**free_me;

	if (tokens == NULL)
		return (NULL);
	list = NULL;
	free_me = ft_strarr_dup_shallow(tokens);
	parse_tokens(&list, free_me);
	free(free_me);
	return (list);
}
