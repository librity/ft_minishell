/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/25 11:02:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**get_parse_tokens(t_parse_node *node)
{
	t_parse	*parse;

	if (node == NULL)
		return (NULL);
	parse = node->content;
	if (parse == NULL)
		return (NULL);
	return (parse->tokens);
}

char	*get_parse_file_path(t_parse_node *node)
{
	t_parse	*parse;

	if (node == NULL)
		return (NULL);
	parse = node->content;
	if (parse == NULL)
		return (NULL);
	return (parse->file_path);
}

char	*get_parse_delimiter(t_parse_node *node)
{
	t_parse	*parse;

	if (node == NULL)
		return (NULL);
	parse = node->content;
	if (parse == NULL)
		return (NULL);
	return (parse->delimiter);
}

t_parse_type	get_parse_type(t_parse_node *node)
{
	t_parse	*parse;

	if (node == NULL)
		return (PT_NULL);
	parse = node->content;
	if (parse == NULL)
		return (PT_NULL);
	return (parse->type);
}
