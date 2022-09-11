/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 19:43:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	add_pipe(t_parse_list **list)
{
	t_parse	*_parse;

	_parse = new_pipe_parse();
	ft_dlst_add(list, _parse);
}

void	add_truncate(t_parse_list **list, char *file_path)
{
	t_parse	*_parse;

	_parse = new_truncate_parse(file_path);
	ft_dlst_add(list, _parse);
}

void	add_append(t_parse_list **list, char *file_path)
{
	t_parse	*_parse;

	_parse = new_append_parse(file_path);
	ft_dlst_add(list, _parse);
}

void	add_read_file(t_parse_list **list, char *file_path)
{
	t_parse	*_parse;

	_parse = new_read_file_parse(file_path);
	ft_dlst_add(list, _parse);
}

void	add_heredoc(t_parse_list **list, char *delimiter)
{
	t_parse	*_parse;

	_parse = new_heredoc_parse(delimiter);
	ft_dlst_add(list, _parse);
}
