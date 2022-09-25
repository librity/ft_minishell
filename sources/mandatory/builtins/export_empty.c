/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/21 15:53:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	is_empty_variable(char *declaration)
{
	char	*equals;

	equals = ft_strchr(declaration, '=');
	if (equals != NULL)
		return (false);
	if (*(equals + 1) != '\0')
		return (false);
	return (true);
}

bool	exp_handled_empty_variable(char **tokens, t_export *_ctl)
{
	if (!is_empty_variable(*tokens))
		return (false);
	exp_cleanup(_ctl);
	return (true);
}

bool	exp_handled_empty_value(t_export *_ctl)
{
	if (!ft_streq(_ctl->value, ""))
		return (false);
	exp_cleanup(_ctl);
	return (true);
}
