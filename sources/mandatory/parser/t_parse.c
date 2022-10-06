/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 18:27:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse	*new_parse(void)
{
	t_parse	*new_node;

	new_node = ft_clalloc(lalloc(), sizeof(t_parse), 1);
	return (new_node);
}

void	destroy_parse(t_parse **pnode)
{
	t_parse	*_pnode;

	if (pnode == NULL || *pnode == NULL)
		return (print_warning(DESTROY_PNODE_NULL_WRN));
	_pnode = *pnode;
	ft_free_strarr(_pnode->tokens);
	ft_strdel(&_pnode->file_path);
	ft_strdel(&_pnode->delimiter);
	free(_pnode);
	(*pnode) = NULL;
}
