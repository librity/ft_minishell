/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envht.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:33:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 01:35:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_hash_table	*envht(void)
{
	return (c()->envht);
}

void	initilize_envht(void)
{
	if (c()->envht != NULL)
		return ;
	c()->envht = ht_new();
	ht_insert_strarr(c()->envht, c()->envp);
}

void	destroy_envht(void)
{
	if (envht() == NULL)
		return ;
	ht_destroy(&(c()->envht));
}
