/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:52:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 00:13:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_ht_item	*ht_new_item(char *key, char *value)
{
	t_ht_item	*new;

	if (key == NULL || value == NULL)
		return (NULL);
	new = ft_salloc(sizeof(t_ht_item));
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	return (new);
}

void	ht_destroy_item(t_ht_item **item)
{
	if (item == NULL || *item == NULL)
		return (print_warning(HT_DESTROY_ITEM_NULL_WRN));
	free((*item)->key);
	free((*item)->value);
	free(*item);
	(*item) = NULL;
}

char	*ht_item_to_string(t_ht_item *item)
{
	char	*string;

	if (item == NULL)
		return (NULL);
	string = ft_strdup(item->key);
	string = ft_strjoin_free(string, "=");
	string = ft_strjoin_free(string, item->value);
	return (string);
}
