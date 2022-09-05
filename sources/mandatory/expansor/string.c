/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 17:53:35 by lpaulo-m         ###   ########.fr       */
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

/**
 * foo=bar
 * banan=chocolate
 * "testeando$foo$banana" => "testeandobarchocolate"
 * "testeando\"$foo\"\'$banana\'" => "testeando\"bar\"\'$banana\'"
 */

/*
*"testeando"
*\""foo"\",
*\"'banana'",
*NULL
*/

static char	*find_var_end(char *var)

char	*expand_str(char *token)
{
	static char	buffer[FT_ARG_MAX];
	char		**vars;
	char		**vstemp;
	char		*var;
	char		*var_end;
	bool		first_is_var;

	ft_strcpy(buffer, token);
	insert_delimiters(buffer);
	vars = ft_split(token, DELIMITER);
	vstemp = vars;
	first_is_var = *token == DOLLAR;
	while (vstemp != NULL)
	{
		if (vstemp == vars && !first_is_var)
		{
			vstemp++;
			continue ;
		}
		var_end =
		var =
		vstemp++;
	}
	ft_free_strarr(vars);
	return (NULL);
}
