/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:48:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 15:52:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	line_is_valid(char *line)
{
	if (!has_valid_quotes(line))
	{
		print_error(QUOTES_ERR);
		return (false);
	}
	return (true);
}
