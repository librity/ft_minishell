/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_extract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 17:29:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*exp_extract_key(char *declaration)
{
	char	*equals;
	size_t	length;

	equals = ft_strchr(declaration, '=');
	if (equals == NULL)
		return (ft_strdup(declaration));
	if (equals == declaration)
		return (ft_strdup(""));
	length = equals - declaration;
	return (ft_substr(declaration, 0, length));
}

char	*exp_extract_value(char *declaration)
{
	char	*equals;
	char	*end;
	char	*value;
	size_t	length;

	equals = ft_strchr(declaration, EQUALS);
	if (equals == NULL)
		return (ft_strdup(EMPTY_STR));
	end = ft_strchr(declaration, NULL_CHAR);
	if (end == NULL)
		return (ft_strdup(EMPTY_STR));
	length = end - equals - 1;
	value = ft_substr(equals + 1, 0, length);
	return (value);
}
