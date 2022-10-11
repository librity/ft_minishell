/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 18:11:59 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*find_key_end(char *var)
{
	//printf("value = %c\n", *var);
	while (*var != NULL_CHAR)
	{
		if (*var == '?')
			return (var + 1);
		if (*var == ' ')
			return (var);
		if (*var == SINGLE_QUOTE)
			return (var);
		if (*var == DOUBLE_QUOTE)
			return (var);
		var++;
	}
	return (var);
}

static char	*resolve_value(char *key)
{
	char	*value;

	if (ft_streq(key, LAST_EXIT_KEY))
		return (last_exit());
	value = envht_get(key);
	if (value == NULL)
		value = EMPTY_STR;
	return (value);
}

static char	*insert_value(char *variable)
{
	char	*key;
	char	*value;
	char	*expanded;
	char	*key_end;

	key_end = find_key_end(variable);
	//printf("key_end = %s\n", key_end);
	key = ft_substr(variable, 0, key_end - variable);
	//printf("key = %s\n", key);
	//exit(0);
	value = resolve_value(key);
	expanded = ft_strjoin(value, key_end);
	free(key);
	free(variable);
	return (expanded);
}

static void	insert_values(char *token, char **vars)
{
	char	**first;
	bool	first_is_var;

	// printf("\n varns \n");
	// while (*vars)
	// {
	// 	printf("varns = %s\n", *vars);
	// 	vars++;
	// }
	// printf("\n");
	// exit(0);

	first_is_var = *token == DOLLAR;
	first = vars;
	while (*vars != NULL)
	{
		if (vars == first && !first_is_var)
		{
			vars++;
			continue ;
		}
		//printf("token = %s\n", *vars);
		*vars = insert_value(*vars);
		vars++;
	}
}

char	*expand_line(char *line)
{
	char	**vars;
	char	*result;

	if (ft_strchr(line, '$') == NULL)
		return (ft_strdup(line));
	vars = isolate_variables(line);
	insert_values(line, vars);
	result = ft_join_strarr(vars);
	ft_free_strarr(vars);
	return (result);
}
