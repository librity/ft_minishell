/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envht_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:33:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 17:21:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	envht_insert(char *key, char *value)
{
	return (ht_insert(envht(), key, value));
}

char	*envht_get(char *key)
{
	return (ht_get(envht(), key));
}

bool	envht_delete(char *key)
{
	return (ht_delete(envht(), key));
}
