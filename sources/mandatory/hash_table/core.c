/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 23:52:05 by lpaulo-m         ###   ########.fr       */
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
	int		index;

	index = 0;
	while (index < table->size)
	{
		index_list = ht_get_index_list(table, index);
		ft_dlstclear(index_list, destroy_item);
		index++;
	}
}

void	ht_destroy(t_hash_table **table)
{
	if (table == NULL || *table == NULL)
		return (print_warning(DESTROY_NULL_HT_WRN));
	free_lists(*table);
	free((*table)->index_lists);
	free(*table);
	*table = NULL;
}

t_hash_table	*ht_new(void)
{
	t_hash_table	*new;

	new = ft_salloc(sizeof(t_hash_table));
	new->size = HASH_TABLE_SIZE;
	new->count = 0;
	new->index_lists = ft_scalloc(sizeof(t_dlist *), new->size);
	return (new);
}
