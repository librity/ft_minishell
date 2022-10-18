/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:30:07 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/24 16:03:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bi_unset(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (UNSET_BAD_TOKENS);
	tokens++;
	while (*tokens != NULL)
	{
		ht_delete(envht(), *tokens);
		tokens++;
	}
	return (EXIT_SUCCESS);
}
