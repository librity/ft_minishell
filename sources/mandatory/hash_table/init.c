/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:54:55 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 16:10:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_hash_table	*ht_init(void)
{
	t_hash_table	*new;

	new = ft_salloc(sizeof(t_hash_table));
	new->size = HASH_TABLE_SIZE;
	new->count = 0;
	new->index_lists = ft_scalloc(sizeof(t_dlist *), new->size);
	return (new);
}