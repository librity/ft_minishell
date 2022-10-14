/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:14:58 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/14 13:03:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	handled_too_many_args(char **tokens)
{
	if (*tokens == NULL)
		return (false);
	if (!ft_str_is_int(*tokens))
		return (false);
	print_location_error(EXIT, TOO_MANY_ARGS_ERR);
	return (true);
}

static bool	handled_bad_status(char **tokens)
{
	char	*message;

	if (exit_status_is_too_long(*tokens))
		return (false);
	message = ft_strdup(*tokens);
	message = ft_strjoin_free(message, ": numeric argument required");
	print_location_error(EXIT, message);
	free(message);
	return (true);
}

static int	resolve_exit_status(char **tokens)
{
	if (*tokens == NULL)
		return (last_exit_int());
	if (handled_bad_status(tokens))
		return (EXIT_BAD_STATUS);
	if (handled_too_many_args(tokens + 1))
		return (EXIT_TOO_MANY_ARGS);
	return (exit_atoi(*tokens));
}

int	bi_exit(char **tokens)
{
	int	exit_status;

	if (tokens == NULL || *tokens == NULL)
		return (EXIT_BAD_TOKENS);
	if (ft_strarr_len(tokens) > 2)
		die_full(EXIT, TOO_MANY_ARGS_ERR, 1);
	tokens++;
	printf(EXIT "\n");
	exit_status = resolve_exit_status(tokens);
	cleanup_shell();
	exit(exit_status);
	return (exit_status);
}
