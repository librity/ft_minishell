/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:30:07 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 15:26:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	unset(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (false);
	while (*tokens != NULL)
	{
		ht_delete(envht(), *tokens);
		tokens++;
	}
	return (true);
}
