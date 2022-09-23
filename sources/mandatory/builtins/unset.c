/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:30:07 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 14:03:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	bi_unset(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (false);
	tokens++;
	while (*tokens != NULL)
	{
		ht_delete(envht(), *tokens);
		tokens++;
	}
	return (true);
}
