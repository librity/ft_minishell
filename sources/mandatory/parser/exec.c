/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/06 16:46:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse	*new_exec(char **tokens)
{
	t_parse	*new;

	if (ft_strarr_len(tokens) == 0)
		return (NULL);
	new = new_parse();
	new->type = PT_EXEC;
	new->tokens = ft_strarr_dup(tokens);
	ft_add_lalloc_strarr(lalloc(), new->tokens);
	return (new);
}

t_parse	*new_exec_length(char **tokens, int length)
{
	t_parse	*new;

	if (length < 0)
		return (NULL);
	if (length > (int)ft_strarr_len(tokens))
		return (NULL);
	new = new_parse();
	new->type = PT_EXEC;
	new->tokens = ft_strarr_new(length);
	new->tokens[length] = NULL;
	length--;
	while (length >= 0)
	{
		new->tokens[length] = ft_strdup(tokens[length]);
		length--;
	}
	ft_add_lalloc_strarr(lalloc(), new->tokens);
	return (new);
}

void	add_exec(t_parse_list **list, char **tokens)
{
	t_parse	*_parse;
	char	**end;
	int		length;

	if (tokens == NULL || *tokens == NULL)
		return ;
	end = find_next_pipe(tokens);
	length = end - tokens;
	if (length <= 0)
		return ;
	_parse = new_exec_length(tokens, length);
	if (_parse == NULL)
		return ;
	ft_dlst_addb_lalloc(lalloc(), list, _parse);
}
