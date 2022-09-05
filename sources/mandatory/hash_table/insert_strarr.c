/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_strarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 14:16:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	valid_tokens(char **tokens)
{
	if (tokens == NULL)
		return (false);
	if (ft_strarr_len(tokens) != 2)
	{
		ft_free_strarr(tokens);
		return (false);
	}
	return (true);
}

static bool	valid_params(t_hash_table *table, char **strings)
{
	if (table == NULL)
		return (false);
	if (strings == NULL)
		return (false);
	return (true);
}

bool	ht_insert_strarr(t_hash_table *table, char **strings)
{
	char	**tokens;

	if (!valid_params(table, strings))
		return (false);
	while (*strings != NULL)
	{
		tokens = tokenize_variable(*strings);
		if (!valid_tokens(tokens))
			return (false);
		ht_insert(table, tokens[0], tokens[1]);
		ft_free_strarr(tokens);
		strings++;
	}
	return (true);
}
