/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/25 11:28:20 by lpaulo-m         ###   ########.fr       */
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
}

void	handle_append(t_parse_list *node)
{
	char	*file_path;
	int		fd;

	file_path = get_parse_file_path(node);
	fd = open_append_or_die(file_path);
	stdout_to_file(fd);
}

void	execve_builtin(char **tokens)
{
	int	status;

	if (ft_streq(CD, *tokens))
		status = bi_cd(tokens);
	if (ft_streq(EXIT, *tokens))
		status = bi_exit(tokens);
	if (ft_streq(ECHO, *tokens))
		status = bi_echo(tokens);
	if (ft_streq(PWD, *tokens))
		status = bi_pwd(tokens);
	if (ft_streq(EXPORT, *tokens))
		status = bi_export(tokens);
	if (ft_streq(UNSET, *tokens))
		status = bi_unset(tokens);
	if (ft_streq(HELP, *tokens))
		status = bi_help(tokens);
	if (ft_streq(ENV, *tokens))
		status = bi_env(tokens);
	set_last_exit(status);
}

void	handle_exec(t_parse_list *node)
{
	char	**tokens;

	tokens = get_parse_tokens(node);
	if (is_builtin(*tokens))
	{
		execve_builtin(tokens);
		return ;
	}
	execve_or_die(tokens);
	exit(EXIT_FAILURE);
}
