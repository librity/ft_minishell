/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 20:11:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	add_pipe(t_parse_list **list)
{
	t_parse	*_parse;

	_parse = new_pipe();
	ft_dlst_add(list, _parse);
}

void	add_truncate(t_parse_list **list, char *file_path)
{
	t_parse	*_parse;

	_parse = new_truncate(file_path);
	ft_dlst_add(list, _parse);
}

void	add_append(t_parse_list **list, char *file_path)
{
	t_parse	*_parse;

	_parse = new_append(file_path);
	ft_dlst_add(list, _parse);
}

void	add_read_file(t_parse_list **list, char *file_path)
{
	t_parse	*_parse;

	_parse = new_read_file(file_path);
	ft_dlst_add(list, _parse);
}

void	add_heredoc(t_parse_list **list, char *delimiter)
{
	t_parse	*_parse;

	_parse = new_heredoc(delimiter);
	ft_dlst_add(list, _parse);
}
