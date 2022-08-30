/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:52:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/30 16:55:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ht_destroy_item(t_ht_item **item)
{
	free((*item)->key);
	free((*item)->value);
	free(*item);
	(*item) = NULL;
}
