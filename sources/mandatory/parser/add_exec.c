/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 19:39:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	_parse = new_exec_length_parse(tokens, length);
	if (_parse == NULL)
		return ;
	ft_dlst_add(list, _parse);
}
