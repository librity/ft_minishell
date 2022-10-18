/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 15:13:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*expand(char *line)
{
	char	*result;

	if (line == NULL)
		return (NULL);
	result = expand_line(line);
	ft_add_lalloc(lalloc(), result);
	ft_bdebug(debug(), "expand = \"%s\"", result);
	return (result);
}
