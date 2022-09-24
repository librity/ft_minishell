/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/24 17:09:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bi_help(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (HELP_BAD_TOKENS);
	printf(HELP_MSG);
	return (EXIT_SUCCESS);
}
