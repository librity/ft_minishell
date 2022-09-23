/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:14:58 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 17:22:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static unsigned char	resolve_exit_status(char *str_status)
{
	if (str_status == NULL)
		return (EXIT_SUCCESS);
	return (ft_atoi(str_status));
}

static bool check_arguments_is_int(char **tokens)
{
	if (*tokens == NULL)
		return (false);
	if (!ft_str_is_int(*tokens))
		return (false);
	print_location_error(EXIT, CD_TOO_MANY_ARGS_ERR);
	return (true);
}

static bool check_argument_is_str(char **tokens)
{
	char	*message;

	if (ft_str_is_int(*tokens))
		return (false);
	message = ft_strdup("");
	message = ft_strjoin_free(message, *tokens);
	message = ft_strjoin_free(message, ": ");
	message = ft_strjoin_free(message, "numeric argument required");
	print_location_error(EXIT, message);
	free(message);
	return (true);
}

int		check_many_arguments(char	**tokens)
{
	int		exit_status;

	if (*tokens == NULL)
		return (0);
	else if (check_argument_is_str(tokens))
		exit_status = 2;
	else if (check_arguments_is_int(tokens + 1))
		exit_status = 1;
	else
		exit_status = resolve_exit_status(*tokens);
	return (exit_status);
}

int	bi_exit(char **tokens)
{
	unsigned char	exit_status;

	if (tokens == NULL || *tokens == NULL)
		return (0);
	tokens++;
	cleanup_shell();
	printf(EXIT "\n");
	exit_status = check_many_arguments(tokens);
	exit(exit_status);
	return (exit_status);
}
