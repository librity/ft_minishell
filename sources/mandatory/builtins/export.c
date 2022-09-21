/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/21 13:43:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	dump_env(void)
{
	// TODO DUMP ENV with declare -x and ""
}

bool	is_empty_variable(char *declaration)
{
	char	*equals;

	equals = ft_strchr(declaration, '=');
	if (equals != NULL)
		return (false);
	if (*(equals + 1) != '\0')
		return (false);
	return (true);
}

char	*extract_key(char *declaration)
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

char	*extract_value(char *declaration)
{
	char	*equalsp;
	char	*nullp;
	char	*value;

	equalsp = ft_strchr(declaration, EQUALS);
	nullp = ft_strchr(declaration, NULL_CHAR);
	value = ft_substr(equalsp + 1, 0, nullp - equalsp - 1);
	return (value);
}

bool	export(char **tokens)
{
	char	*key;
	char	*value;
	bool	status;


	if (tokens == NULL || *tokens == NULL)
		return (false);
	if (ft_strarr_len(tokens) == 1)
	{
		dump_env();
		return (true);
	}
	tokens++;
	status = true;
	while (*tokens != NULL)
	{
		key = extract_key(*tokens);
		if (!is_valid_variable(key))
		{
			free(key);
			status = false;
			tokens++;
			continue ;
		}
		if (is_empty_variable(*tokens))
		{
			free(key);
			tokens++;
			continue ;
		}
		value = extract_value(*tokens);
		if (ft_streq(value, ""))
		{
			free(key);
			free(value);
			tokens++;
			continue ;
		}
		envht_insert(key, value);
		free(key);
		free(value);
		tokens++;
	}
	return (status);
}
