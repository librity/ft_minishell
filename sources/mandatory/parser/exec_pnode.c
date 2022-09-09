/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 17:48:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_pnode	*new_exec_pnode(char **tokens)
{
	t_pnode	*new;

	new = new_pnode();
	new->type = PT_EXEC;
	new->exec.cmd = ft_strdup(tokens[0]);
	new->exec.tokens = ft_strarr_dup(tokens);
	return (new);
}

t_pnode	*new_exec_length_pnode(char **tokens, int length)
{
	t_pnode	*new;

	new = new_pnode();
	new->type = PT_EXEC;
	new->exec.cmd = ft_strdup(tokens[0]);
	new->exec.tokens = ft_strarr_new(length);
	new->exec.tokens[length] = NULL;
	length--;
	while (length >= 0)
	{
		new->exec.tokens[length] = ft_strdup(tokens[length]);
		length--;
	}
	return (new);
}
