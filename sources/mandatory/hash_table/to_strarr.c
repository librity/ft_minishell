/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_strarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 00:20:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**skip_strings(char **strings)
{
	while (*strings != NULL)
		strings++;
	return (strings);
}

static void	add_items(char **strings, t_dlist *node)
{
	t_ht_item	*item;
	char		*string;

	while (node != NULL)
	{
		item = node->content;
		string = ht_item_to_string(item);
		strings = skip_strings(strings);
		*strings = string;
		node = node->next;
	}
}

char	**ht_to_strarr(t_hash_table *table)
{
	char	**strings;
	int		index;
	t_dlist	**list;

	if (table == NULL)
		return (NULL);
	strings = ft_strarr_new(table->count);
	index = 0;
	while (index < table->size)
	{
		list = ht_get_index_list(table, index);
		if (list != NULL)
			add_items(strings, *list);
		index++;
	}
	return (strings);
}
