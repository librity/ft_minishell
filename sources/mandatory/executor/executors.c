/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 13:20:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_fork_exec(t_parse_list *node)
{
	char	**tokens;
	int		status;

	tokens = get_parse_tokens(node);
	if (tokens == NULL || *tokens == NULL)
		die(EXEC_BAD_TOKENS_ERR);
	if (is_builtin(*tokens))
	{
		status = execute_builtin(tokens);
		quit_status(status);
	}
	execve_or_die(tokens);
}

int	handle_builtin_exec(t_parse_list *node)
{
	char	**tokens;

	tokens = get_parse_tokens(node);
	if (tokens == NULL || *tokens == NULL)
		die(EXEC_BAD_TOKENS_ERR);
	return (execute_builtin(tokens));
}
