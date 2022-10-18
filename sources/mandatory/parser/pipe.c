/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/06 16:47:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse	*new_pipe(void)
{
	t_parse	*new;

	new = new_parse();
	new->type = PT_PIPE;
	return (new);
}

void	add_pipe(t_parse_list **list)
{
	t_parse	*_parse;

	_parse = new_pipe();
	ft_dlst_addb_lalloc(lalloc(), list, _parse);
}

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
