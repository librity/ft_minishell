/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 19:22:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*skip_or_delimit(char *line)
{
	if (at_dollar(line))
		return (insert_delimiter(line));
	if (at_single_quote(line))
		return (skip_single_quotes(line));
	return (line);
}

static void	insert_delimiters(char *line)
{
	while (line != NULL && *line != '\0')
	{
		line = skip_or_delimit(line);
		if (line != NULL)
			line++;
	}
}

static char	*find_var_end(char *var)
{
	while (*var != NULL_CHAR)
	{
		if (*var == SINGLE_QUOTE)
			return (var);
		if (*var == DOUBLE_QUOTE)
			return (var);
		var++;
	}
	return (var);
}

char	*expand_str(char *token)
{
	static char	buffer[FT_ARG_MAX];
	char		**vars;
	char		**vstemp;
	char		*var;
	char		*rest;
	char		*value;
	char		*expanded;
	char		*result;
	char		*var_end;
	bool		first_is_var;

	ft_strcpy(buffer, token);
	insert_delimiters(buffer);
	vars = ft_split(buffer, DELIMITER);
	first_is_var = *token == DOLLAR;
	vstemp = vars;
	while (*vstemp != NULL)
	{
		if (vstemp == vars && !first_is_var)
		{
			vstemp++;
			continue ;
		}
		var_end = find_var_end(*vstemp);
		var = ft_substr(*vstemp, 0, var_end - *vstemp);
		rest = ft_strdup(var_end);
		value = envht_get(var);
		expanded = ft_strjoin(value, rest);
		free(*vstemp);
		free(rest);
		free(var);
		*vstemp = expanded;
		vstemp++;
	}

	result = ft_strdup(*vars);
	vstemp = vars + 1;
	while (*vstemp != NULL)
	{
		result = ft_strjoin_free(result, *vstemp);
		vstemp++;
	}
	ft_free_strarr(vars);
	return (result);
}
