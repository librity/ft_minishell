/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_extract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/21 15:53:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*exp_extract_key(char *declaration)
{
	char	*equalsp;
	size_t	length;

	equalsp = ft_strchr(declaration, '=');
	if (equalsp == NULL)
		return (ft_strdup(declaration));
	if (equalsp == declaration)
		return (ft_strdup(""));
	length = equalsp - declaration;
	return (ft_substr(declaration, 0, length));
}

char	*exp_extract_value(char *declaration)
{
	char	*equalsp;
	char	*nullp;
	char	*value;

	equalsp = ft_strchr(declaration, EQUALS);
	nullp = ft_strchr(declaration, NULL_CHAR);
	value = ft_substr(equalsp + 1, 0, nullp - equalsp - 1);
	return (value);
}
