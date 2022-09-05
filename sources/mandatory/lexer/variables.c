/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 16:27:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	extract_key_and_value(char *declaration, char **tokens)
{
	char	*equalsp;
	char	*nullp;

	equalsp = ft_strchr(declaration, EQUALS);
	nullp = ft_strchr(declaration, NULL_CHAR);
	tokens[KEY] = ft_substr(declaration, 0, equalsp - declaration);
	tokens[VALUE] = ft_substr(equalsp + 1, 0, nullp - equalsp - 1);
}

static bool	is_valid_declaration(char *declaration)
{
	if (declaration == NULL)
		return (false);
	if (ft_strchr(declaration, EQUALS) == NULL)
		return (false);
	if (ft_strchr(declaration, DELIMITER) != NULL)
		return (false);
	return (true);
}

char	**tokenize_variable(char *declaration)
{
	char	**tokens;

	if (!is_valid_declaration(declaration))
		return (NULL);
	tokens = ft_strarr_new(2);
	extract_key_and_value(declaration, tokens);
	return (tokens);
}
