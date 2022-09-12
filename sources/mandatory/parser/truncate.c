/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:28:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 21:13:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_parse	*new_truncate(char *file_path)
{
	t_parse	*new;

	new = new_parse();
	new->type = PT_TRUNCATE;
	new->file.path = ft_strdup_null(file_path);
	return (new);
}

void	add_truncate(t_parse_list **list, char *file_path)
{
	t_parse	*_parse;

	_parse = new_truncate(file_path);
	ft_dlst_add(list, _parse);
}