/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/21 14:30:27 by lpaulo-m         ###   ########.fr       */
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

void	print_identifier_err(char *declaration)
{
	char	*message;

	message = ft_strnew();
	message = ft_strjoin_free(message, "`");
	message = ft_strjoin_free(message, declaration);
	message = ft_strjoin_free(message, "': not a valid identifier");
	print_location_error(EXPORT, message);
	free(message);
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
	status = true;
	while (++tokens && *tokens != NULL)
	{
		key = extract_key(*tokens);
		if (!is_valid_variable(key))
		{
			free(key);
			status = false;
			print_identifier_err(*tokens);
			continue ;
		}
		if (is_empty_variable(*tokens))
		{
			free(key);
			continue ;
		}
		value = extract_value(*tokens);
		if (ft_streq(value, ""))
		{
			free(key);
			free(value);
			continue ;
		}
		envht_insert(key, value);
		free(key);
		free(value);
	}
	return (status);
}
