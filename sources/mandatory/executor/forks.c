/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:33:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 16:22:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse_list	*find_next_parse_pipe(t_parse_list *node)
{
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (get_parse_type(node) == PT_PIPE)
			return (node);
		node = node->next;
	}
	return (node);
}

int	count_parse_pipes(t_parse_list *node)
{
	int	pipe_count;

	if (node == NULL)
		return (0);
	pipe_count = 0;
	while (node != NULL)
	{
		if (get_parse_type(node) == PT_PIPE)
			pipe_count++;
		node = node->next;
	}
	return (pipe_count);
}

void	execute_forks(t_parse_list *list)
{
	int	pipe_count;

	pipe_count = count_parse_pipes(list);
	while (pipe_count > 0)
	{
		execute_fork(list);
		list = find_next_parse_pipe(list)->next;
		pipe_count--;
	}
	execute_last_fork(list);
}
