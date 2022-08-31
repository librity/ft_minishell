/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:27:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 22:57:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ht_get_index(char *key)
{
	return ((int)(md5_sum(key) % HASH_TABLE_SIZE));
}

t_dlist	**ht_get_index_list(t_hash_table *table, int index)
{
	if (table == NULL)
		return (NULL);
	if (index < 0)
		return (NULL);
	if (index >= table->size)
		return (NULL);
	return (&table->index_lists[index]);
}
