/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:52:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/01 13:46:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ht_destroy_item(t_ht_item **item)
{
	if (item == NULL || *item == NULL)
		return (print_warning(HT_DESTROY_ITEM_NULL_WRN));
	free((*item)->key);
	free((*item)->value);
	free(*item);
	(*item) = NULL;
}
