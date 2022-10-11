/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoutes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:12:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 12:56:38 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*skip_single_quotes(char *line)
{
	return (ft_strchr(++line, SINGLE_QUOTE));
}

char	*skip_double_quotes(char *line)
{
	return (ft_strchr(line, DOUBLE_QUOTE));
}

char	*skip_quotes(char *token)
{
	if (at_single_quote(token))
		return (skip_single_quotes(token));
	if (at_double_quote(token))
		return (skip_double_quotes(token));
	return (token);
}
