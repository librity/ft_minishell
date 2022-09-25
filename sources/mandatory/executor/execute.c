/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:39:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/25 11:21:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse_node	*find_first_exec(t_parse_list *node)
{
	while (node != NULL && get_parse_type(node) != PT_PIPE)
	{
		if (get_parse_type(node) == PT_EXEC)
			return (node);
		node = node->next;
	}
	return (NULL);
}

bool	firs_exec_is_builtin(t_parse_list *pipeline)
{
	t_parse_node	*node;
	char			**tokens;

	node = find_first_exec(pipeline);
	if (node == NULL)
		return (false);
	tokens = get_parse_tokens(pipeline);
	if (tokens == NULL)
		return (false);
	if (*tokens == NULL)
		return (false);
	return (is_builtin(*tokens));
}

bool	handled_one_builtin(t_parse_list *pipeline)
{
	if (count_parse_pipes(pipeline) > 0)
		return (false);
	if (!firs_exec_is_builtin(pipeline))
		return (false);
	handle_pipe_sequence(pipeline);
	return (true);
}


void	execute(t_parse_list *pipeline)
{
	if (handled_one_builtin(pipeline))
		return ;
	execute_pipeline(pipeline);
}
