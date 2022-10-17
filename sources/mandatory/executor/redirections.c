/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/13 11:04:49 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_read_file(t_parse_list *node)
{
	char	*path;
	int		fd;

	path = get_parse_file_path(node);
	fd = open_infile_or_die(path);
	file_to_stdin(fd);
	close_or_die(fd);
}

void	handle_heredoc(t_parse_list *node)
{
	char	*delimiter;

	delimiter = get_parse_delimiter(node);
	hdoc_to_stdin(delimiter);
}

void	handle_truncate(t_parse_list *node)
{
	char	*file_path;
	int		fd;

	file_path = get_parse_file_path(node);
	fd = open_truncate_or_die(file_path);
	stdout_to_file(fd);
	close_or_die(fd);
}

void	handle_append(t_parse_list *node)
{
	char	*file_path;
	int		fd;

	file_path = get_parse_file_path(node);
	fd = open_append_or_die(file_path);
	stdout_to_file(fd);
	close_or_die(fd);
}
