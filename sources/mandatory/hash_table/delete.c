/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 23:17:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	destroy_node(t_dlist **index_list, int node_index)
{
	t_dlist		*node;
	t_ht_item	*item;

	node = ft_dlst_pluck(index_list, node_index);
	item = node->content;
	ht_destroy_item(&item);
	free(node);
}

static int	linear_search_node_index(t_dlist *node, char *key)
{
	t_ht_item	*item;
	int			index;

	index = 0;
	while (node != NULL)
	{
		item = node->content;
		if (ft_streq(item->key, key))
			return (index);
		node = node->next;
	}
	return (DLIST_BAD_INDEX_CODE);
}

void	ht_delete(t_hash_table *table, char *key)
{
	t_dlist	**index_list;
	int		list_index;
	int		node_index;

	list_index = ht_get_index(key);
	index_list = ht_get_index_list(table, list_index);
	node_index = linear_search_node_index(*index_list, key);
	if (node_index == DLIST_BAD_INDEX_CODE)
		return ;
	destroy_node(index_list, node_index);
	table->count--;
}
