/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 17:22:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	has_unescaped_specialchars(char *filename)
{
	while (filename != NULL && *filename != '\0')
	{
		if (is_specialchar(*filename))
			return (true);
		filename = skip_quotes(filename);
		if (filename != NULL)
			filename++;
	}
	return (false);
}

bool	is_valid_filename(char *filename)
{
	if (ft_has_char(filename, '/'))
		return (false);
	if (has_unescaped_specialchars(filename))
		return (false);
	return (true);
}
