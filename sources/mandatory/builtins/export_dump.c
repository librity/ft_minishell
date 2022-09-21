/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/21 15:12:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	dump_item(t_ht_item *item)
{
	if (item == NULL)
		return ;
	if (item->key == NULL)
		return ;
	if (item->value == NULL)
		return ;
	printf("declare -x %s=\"%s\"\n", item->key, item->value);
}

void	export_dump(void)
{
	ht_for_each(envht(), &dump_item);
}
