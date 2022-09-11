/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 14:56:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	_destroy_pnode(void *pnode)
{
	destroy_pnode((t_parse **)&pnode);
}

void	destroy_plist(t_parse_list **plist)
{
	ft_dlstclear(plist, &_destroy_pnode);
}
