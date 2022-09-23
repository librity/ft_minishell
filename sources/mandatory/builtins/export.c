/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/23 14:03:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	bi_export(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (false);
	if (exp_dump(tokens))
		return (true);
	return (exp_insert(tokens));
}
