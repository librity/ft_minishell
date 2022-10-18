/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_assignment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 17:26:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	has_assignment(char *declaration)
{
	char	*equals;

	equals = ft_strchr(declaration, '=');
	if (equals == NULL)
		return (false);
	return (true);
}

bool	exp_handled_no_assignment(char **tokens, t_export *_ctl)
{
	if (has_assignment(*tokens))
		return (false);
	exp_cleanup(_ctl);
	return (true);
}
