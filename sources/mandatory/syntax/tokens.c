/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 18:08:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	tokens_are_valid(char **tokens)
{
	if (tokens_have_semicolon(tokens))
		return (false);
	if (tokens_have_backslash(tokens))
		return (false);
	if (!has_valid_truncate(tokens))
		return (false);
	if (!has_valid_append(tokens))
		return (false);
	if (!has_valid_read_file(tokens))
		return (false);
	return (true);
}
