/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 13:42:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse	*new_exec_pnode(char **tokens)
{
	t_parse	*new;

	new = new_pnode();
	new->type = PT_EXEC;
	new->exec.cmd = ft_strdup(tokens[0]);
	new->exec.argv = ft_strarr_dup(tokens);
	return (new);
}

t_parse	*new_exec_length_pnode(char **tokens, int length)
{
	t_parse	*new;

	new = new_pnode();
	new->type = PT_EXEC;
	new->exec.cmd = ft_strdup(tokens[0]);
	new->exec.argv = ft_strarr_new(length);
	new->exec.argv[length] = NULL;
	length--;
	while (length >= 0)
	{
		new->exec.argv[length] = ft_strdup(tokens[length]);
		length--;
	}
	return (new);
}
