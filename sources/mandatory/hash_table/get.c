/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 23:55:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_ht_item	*linear_search_item(t_dlist *node, char *key)
{
	t_ht_item	*item;

	while (node != NULL)
	{
		item = node->content;
		if (ft_streq(item->key, key))
			return (item);
		node = node->next;
	}
	return (NULL);
}

static bool	valid_params(t_hash_table *table, char *key)
{
	if (table == NULL)
		return (false);
	if (key == NULL)
		return (false);
	return (true);
}

char	*ht_get(t_hash_table *table, char *key)
{
	t_dlist		**index_list;
	t_ht_item	*item;
	int			index;

	if (!valid_params(table, key))
		return (NULL);
	index = ht_get_index(key);
	index_list = ht_get_index_list(table, index);
	item = linear_search_item(*index_list, key);
	if (item == NULL)
		return (NULL);
	return (item->value);
}
