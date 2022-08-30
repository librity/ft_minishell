/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 17:54:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	destroy_item(void *item)
{
	ht_destroy_item((t_ht_item **)&item);
}

static void	free_lists(t_hash_table *table)
{
	t_dlist	**index_list;
	size_t	index;

	index = 0;
	while (index < table->size)
	{
		index_list = &table->index_lists[index];
		ft_dlstclear(index_list, destroy_item);
		index++;
	}
}

void	ht_destroy(t_hash_table **table)
{
	free_lists(*table);
	free((*table)->index_lists);
	free(*table);
	*table = NULL;
}
