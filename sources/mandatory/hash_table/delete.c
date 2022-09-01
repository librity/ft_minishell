/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/01 14:39:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	destroy_node(t_dlist **index_list, t_dlist *destroy_me)
{
	t_ht_item	*destroy_me_too;

	ft_dlst_pluck_node(index_list, destroy_me);
	destroy_me_too = destroy_me->content;
	ht_destroy_item(&destroy_me_too);
	free(destroy_me);
}

static t_dlist	*linear_search_node_index(t_dlist *node, char *key)
{
	t_ht_item	*item;

	while (node != NULL)
	{
		item = node->content;
		if (ft_streq(item->key, key))
			return (node);
		node = node->next;
	}
	return (NULL);
}

bool	ht_delete_in_index(t_hash_table *table, char *key, int index)
{
	t_dlist	**index_list;
	t_dlist	*node;

	index_list = ht_get_index_list(table, index);
	node = linear_search_node_index(*index_list, key);
	if (node == NULL)
		return (false);
	destroy_node(index_list, node);
	table->count--;
	return (true);
}

bool	ht_delete(t_hash_table *table, char *key)
{
	int	index;

	if (table == NULL)
		return (false);
	if (key == NULL)
		return (false);
	index = ht_get_index(key);
	return (ht_delete_in_index(table, key, index));
}
