/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_invalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:43:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/24 16:00:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_identifier_err(char *declaration)
{
	char	*message;

	message = ft_strnew();
	message = ft_strjoin_free(message, "`");
	message = ft_strjoin_free(message, declaration);
	message = ft_strjoin_free(message, "': not a valid identifier");
	print_location_error(EXPORT, message);
	free(message);
}

bool	exp_handled_invalid_variable(char **tokens, t_export *_ctl)
{
	if (is_valid_variable(_ctl->key))
		return (false);
	_ctl->status = EXPORT_BAD_VARIABLE;
	print_identifier_err(*tokens);
	exp_cleanup(_ctl);
	return (true);
}
