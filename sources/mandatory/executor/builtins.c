/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:39:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 18:31:34 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	first_exec_is_builtin(t_parse_list *pipeline)
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

static void	handle_single_builtin(t_parse_list *pipeline)
{
	int			status;

	status = handle_builtin_sequence(pipeline);
	set_last_exit(status);
}

bool	handled_single_builtin(t_parse_list *pipeline)
{
	if (count_parse_pipes(pipeline) > 0)
		return (false);
	if (!first_exec_is_builtin(pipeline))
		return (false);
	handle_single_builtin(pipeline);
	return (true);
}
