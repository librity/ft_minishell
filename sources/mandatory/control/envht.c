/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envht.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:33:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 16:53:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_hash_table	*envht(void)
{
	return (c()->envht);
}

void	initilize_envht(void)
{
	if (envht() != NULL)
		return ;
	c()->envht = ht_new();
}

void	destroy_envht(void)
{
	if (envht() == NULL)
		return ;
	ht_destroy(&(c()->envht));
}
