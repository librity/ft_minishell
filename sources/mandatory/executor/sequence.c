/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 20:31:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_pipe_sequence(t_parse_list *node)
{
	t_parse_type	type;

	while (node != NULL && get_parse_type(node) != PT_PIPE)
	{
		type = get_parse_type(node);
		if (type == PT_READ_FILE)
			handle_read_file(node);
		if (type == PT_HEREDOC)
			handle_heredoc(node);
		if (type == PT_TRUNCATE)
			handle_truncate(node);
		if (type == PT_APPEND)
			handle_append(node);
		if (type == PT_EXEC)
			handle_exec(node);
		node = node->next;
	}
}
