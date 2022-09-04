/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/04 20:49:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	static char	buffer[FT_ARG_MAX];
	char		**tokens;
	char		*equals_position;

	if (!is_valid_declaration(declaration))
		return (NULL);
	ft_strcpy(buffer, declaration);
	equals_position = ft_strchr(buffer, EQUALS);
	*equals_position = DELIMITER;
	tokens = ft_split(buffer, DELIMITER);
	return (tokens);
}
