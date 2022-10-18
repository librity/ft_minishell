/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 13:55:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	debug_node(t_parse_node *node)
{
	t_parse	*parse;

	parse = node->content;
	ft_printf("\t{ TYPE: %d, ", parse->type);
	if (parse->type == PT_EXEC)
	{
		ft_printf("TOKENS: { ");
		ft_put_strarr_inline(parse->tokens);
		ft_printf(" }");
	}
	if (parse->type == PT_TRUNCATE
		|| parse->type == PT_APPEND
		|| parse->type == PT_READ_FILE)
		ft_printf("FILE_PATH: %s", parse->file_path);
	if (parse->type == PT_HEREDOC)
		ft_printf("DELIMITER: %s", parse->delimiter);
	ft_printf(" }\n");
}

static void	debug_list(t_parse_node *node)
{
	if (!debug())
		return ;
	if (node == NULL)
	{
		ft_debug("parse = NULL");
		return ;
	}
	ft_yellowb("DEBUG:\t");
	ft_putstr("parse = [\n");
	while (node != NULL)
	{
		debug_node(node);
		node = node->next;
	}
	ft_putstr("]\n");
}

t_parse_list	*parse(char **tokens)
{
	t_parse_list	*list;

	list = parse_tokens(tokens);
	debug_list(list);
	return (list);
}
