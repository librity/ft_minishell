/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 17:25:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	initialize_export(t_export *_ctl)
{
	_ctl->key = NULL;
	_ctl->value = NULL;
	_ctl->status = EXIT_SUCCESS;
}

static void	insert_variable(t_export *_ctl)
{
	envht_insert(_ctl->key, _ctl->value);
	exp_cleanup(_ctl);
}

void	exp_cleanup(t_export *_ctl)
{
	ft_strdel(&(_ctl->key));
	ft_strdel(&(_ctl->value));
}

int	exp_insert(char **tokens)
{
	t_export	_ctl;

	initialize_export(&_ctl);
	while (++tokens && *tokens != NULL)
	{
		_ctl.key = exp_extract_key(*tokens);
		if (exp_handled_bad_key(tokens, &_ctl))
			continue ;
		if (exp_handled_no_assignment(tokens, &_ctl))
			continue ;
		_ctl.value = exp_extract_value(*tokens);
		insert_variable(&_ctl);
	}
	return (_ctl.status);
}
