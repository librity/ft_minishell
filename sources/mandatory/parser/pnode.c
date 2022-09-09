/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnode.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 14:52:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_pnode	*new_pnode(void)
{
	t_pnode	*new_node;

	new_node = ft_scalloc(sizeof(t_pnode), 1);
	return (new_node);
}

t_pnode	*new_exec_pnode(char **tokens)
{
	t_pnode	*new;

	new = new_pnode();
	new->type = PT_EXEC;
	new->exec.cmd = ft_strdup(tokens[0]);
	new->exec.tokens = ft_strarr_dup(tokens);
	return (new);
}
