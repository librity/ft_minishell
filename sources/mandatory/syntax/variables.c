/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 14:17:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	has_metacharacter(char *variable)
{
	char	*metachar;

	metachar = METACHARACTERS;
	while (*metachar != '\0')
	{
		if (ft_strchr(variable, *metachar) != NULL)
			return (true);
		metachar++;
	}
	return (false);
}

bool	is_valid_variable(char *variable)
{
	if (ft_isdigit(*variable))
		return (false);
	if (has_metacharacter(variable))
		return (false);
	return (true);
}
