/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnode.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 13:42:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse	*new_pnode(void)
{
	t_parse	*new_node;

	new_node = ft_scalloc(sizeof(t_parse), 1);
	return (new_node);
}

void	destroy_pnode(t_parse **pnode)
{
	t_parse	*_pnode;

	if (pnode == NULL || *pnode == NULL)
		return (print_warning(DESTROY_PNODE_NULL_WRN));
	_pnode = *pnode;
	ft_free_strarr(_pnode->exec.argv);
	ft_strdel(&_pnode->exec.cmd);
	ft_strdel(&_pnode->exec.path);
	ft_strdel(&_pnode->file.path);
	ft_strdel(&_pnode->delimiter);
	free(_pnode);
	(*pnode) = NULL;
}
