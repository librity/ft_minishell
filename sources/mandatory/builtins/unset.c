/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:30:07 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 13:18:46 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	unset(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (false);
	while(*tokens != NULL)
	{
		ht_delete(envht(), *tokens);
		tokens++;
	}
	return (true);
}
