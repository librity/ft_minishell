/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 18:19:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse	*new_pipe_parse(void)
{
	t_parse	*new;

	new = new_parse();
	new->type = PT_PIPE;
	return (new);
}

t_parse	*new_truncate_parse(char *file_path)
{
	t_parse	*new;

	new = new_parse();
	new->type = PT_TRUNCATE;
	new->file.path = ft_strdup(file_path);
	return (new);
}

t_parse	*new_append_parse(char *file_path)
{
	t_parse	*new;

	new = new_parse();
	new->type = PT_APPEND;
	new->file.path = ft_strdup(file_path);
	return (new);
}

t_parse	*new_read_file_parse(char *file_path)
{
	t_parse	*new;

	new = new_parse();
	new->type = PT_READ_FILE;
	new->file.path = ft_strdup(file_path);
	return (new);
}

t_parse	*new_heredoc_parse(char *delimiter)
{
	t_parse	*new;

	new = new_parse();
	new->type = PT_HEREDOC;
	new->delimiter = ft_strdup(delimiter);
	return (new);
}
