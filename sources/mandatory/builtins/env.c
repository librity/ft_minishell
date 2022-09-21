/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/21 15:17:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_item(t_ht_item *item)
{
	if (item == NULL)
		return ;
	if (item->key == NULL)
		return ;
	if (item->value == NULL)
		return ;
	printf("%s=%s\n", item->key, item->value);
}

bool	env(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (false);
	ht_for_each(envht(), &print_item);
	return (true);
}
