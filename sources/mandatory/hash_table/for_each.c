/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:06:23 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/21 15:07:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	iterate_list(t_dlist *node, t_ht_for_each_cb callback)
{
	t_ht_item	*item;

	while (node != NULL)
	{
		item = node->content;
		callback(item);
		node = node->next;
	}
}

void	ht_for_each(t_hash_table *table, t_ht_for_each_cb callback)
{
	int		index;
	t_dlist	**list;

	if (table == NULL)
		return ;
	index = 0;
	while (index < table->size)
	{
		list = ht_get_index_list(table, index);
		if (list != NULL)
			iterate_list(*list, callback);
		index++;
	}
}
