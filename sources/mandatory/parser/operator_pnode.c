/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_pnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 13:40:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse	*new_pipe_pnode(void)
{
	t_parse	*new;

	new = new_pnode();
	new->type = PT_PIPE;
	return (new);
}

t_parse	*new_truncate_pnode(char *file_path)
{
	t_parse	*new;

	new = new_pnode();
	new->type = PT_TRUNCATE;
	new->file.path = ft_strdup(file_path);
	return (new);
}

t_parse	*new_append_pnode(char *file_path)
{
	t_parse	*new;

	new = new_pnode();
	new->type = PT_APPEND;
	new->file.path = ft_strdup(file_path);
	return (new);
}

t_parse	*new_read_file_pnode(char *file_path)
{
	t_parse	*new;

	new = new_pnode();
	new->type = PT_READ_FILE;
	new->file.path = ft_strdup(file_path);
	return (new);
}

t_parse	*new_heredoc_pnode(char *delimiter)
{
	t_parse	*new;

	new = new_pnode();
	new->type = PT_HEREDOC;
	new->delimiter = ft_strdup(delimiter);
	return (new);
}
