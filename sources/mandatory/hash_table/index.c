/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:27:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/01 13:03:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ht_get_index(char *key)
{
	if (key == NULL)
		return (HT_BAD_INDEX);
	return ((int)(md5_sum(key) % HASH_TABLE_SIZE));
}

static bool	valid_params(t_hash_table *table, int index)
{
	if (table == NULL)
		return (false);
	if (index < 0)
		return (false);
	if (index >= table->size)
		return (false);
	return (true);
}

t_dlist	**ht_get_index_list(t_hash_table *table, int index)
{
	if (!valid_params(table, index))
		return (NULL);
	return (&table->index_lists[index]);
}
