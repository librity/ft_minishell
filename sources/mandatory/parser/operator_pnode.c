/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_pnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 16:10:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_pnode	*new_pipe_pnode(void)
{
	t_pnode	*new;

	new = new_pnode();
	new->type = PT_PIPE;
	return (new);
}

t_pnode	*new_truncate_pnode(void)
{
	t_pnode	*new;

	new = new_pnode();
	new->type = PT_TRUNCATE;
	return (new);
}

t_pnode	*new_append_pnode(void)
{
	t_pnode	*new;

	new = new_pnode();
	new->type = PT_APPEND;
	return (new);
}

t_pnode	*new_read_file_pnode(void)
{
	t_pnode	*new;

	new = new_pnode();
	new->type = PT_READ_FILE;
	return (new);
}

t_pnode	*new_heredoc_pnode(void)
{
	t_pnode	*new;

	new = new_pnode();
	new->type = PT_HEREDOC;
	return (new);
}
