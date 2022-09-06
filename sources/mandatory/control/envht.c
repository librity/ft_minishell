/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envht.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:33:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 13:03:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_hash_table	*envht(void)
{
	return (c()->envht);
}

bool	initilize_envht(void)
{
	bool	result;

	if (c()->envht != NULL)
	{
		print_warning(ENVHT_REINIT_WRN);
		return (false);
	}
	c()->envht = ht_new();
	result = ht_insert_strarr(c()->envht, c()->envp);
	if (result == false)
		die(ENVP_TO_ENVHT_ERR);
	return (result);
}

void	destroy_envht(void)
{
	if (c()->envht == NULL)
	{
		print_warning(ENVHT_REDESTROY_WRN);
		return ;
	}
	ht_destroy(&(c()->envht));
}

char	**envht_to_envp(void)
{
	if (c()->envht == NULL)
		return (NULL);
	return (ht_to_strarr(c()->envht));
}
