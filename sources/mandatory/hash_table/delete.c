/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/31 18:00:54 by lpaulo-m         ###   ########.fr       */
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

void	ht_delete_in_index(t_hash_table *table, char *key, int index)
{
	t_dlist	**index_list;
	t_dlist	*node;

	index_list = ht_get_index_list(table, index);
	node = linear_search_node_index(*index_list, key);
	if (node == NULL)
		return ;
	destroy_node(index_list, node);
	table->count--;
}

void	ht_delete(t_hash_table *table, char *key)
{
	int	index;

	index = ht_get_index(key);
	ht_delete_in_index(table, key, index);
}
