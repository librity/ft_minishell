/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 18:23:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_ht_item	*find_by_key(t_dlist *lst, char *key)
{
	t_ht_item	*item;

	while (lst)
	{
		item = lst->content;
		if (ft_streq(item->key, key))
			return (item);
		lst = lst->next;
	}
	return (NULL);
}

void	ht_insert(t_hash_table *table, char *key, char *value)
{
	int			index;
	t_ht_item	*new_item;
	t_dlist		**index_list;
	t_ht_item	*item;

	index = ht_get_index(key);
	index_list = &table->index_lists[index];
	item = find_by_key(*index_list, key);
	if (item)
	{
		free(item->value);
		item->value = ft_strdup(value);
		return ;
	}
	new_item = ht_new_item(key, value);
	ft_dlst_addb(index_list, new_item);
	table->count++;
}
