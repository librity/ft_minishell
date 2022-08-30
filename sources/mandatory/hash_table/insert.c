/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 17:42:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ht_insert(t_hash_table *table, char *key, char *value)
{
	int			index;
	t_ht_item	*new_item;
	t_dlist		**index_list;

	index = ht_get_index(key);
	index_list = &table->index_lists[index];
	new_item = ht_new_item(key, value);
	ft_dlst_add(index_list, new_item);
}
