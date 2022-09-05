/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 23:53:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	handled_reinsert(t_dlist *node, char *key, char *value)
{
	t_ht_item	*item;

	while (node != NULL)
	{
		item = node->content;
		if (ft_streq(item->key, key))
		{
			free(item->value);
			item->value = ft_strdup(value);
			return (true);
		}
		node = node->next;
	}
	return (false);
}

void	ht_insert_in_index(t_hash_table *table,
			char *key,
			char *value,
			int index)
{
	t_ht_item	*new_item;
	t_dlist		**index_list;

	index_list = ht_get_index_list(table, index);
	if (handled_reinsert(*index_list, key, value))
		return ;
	new_item = ht_new_item(key, value);
	ft_dlst_addb(index_list, new_item);
	table->count++;
}

static bool	valid_params(t_hash_table *table, char *key, char *value)
{
	if (table == NULL)
		return (false);
	if (key == NULL)
		return (false);
	if (value == NULL)
		return (false);
	return (true);
}

bool	ht_insert(t_hash_table *table, char *key, char *value)
{
	int	index;

	if (!valid_params(table, key, value))
		return (false);
	index = ht_get_index(key);
	ht_insert_in_index(table, key, value, index);
	return (true);
}
