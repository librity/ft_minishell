/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 16:57:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_plist	*parse(char **tokens)
{
	t_pnode		*node;
	t_plist		*plist;

	plist = NULL;
	node = new_exec_pnode(tokens);
	ft_dlst_add(&plist, node);
	return (plist);
}

static void	_destroy_pnode(void *pnode)
{
	destroy_pnode((t_pnode **)&pnode);
}

void	destroy_plist(t_plist **plist)
{
	ft_dlstclear(plist, &_destroy_pnode);
}
