/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:33:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/14 16:46:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	cleanup(void)
{
	cleanup_shell();
}

void	die(char *message)
{
	print_error(message);
	cleanup();
	exit(EXIT_FAILURE);
}

void	die_perror(char *location, int exit_status)
{
	int	_errno;

	_errno = errno;
	ft_putstr_fd(MINISHELL_PREFIX, STDERR_FILENO);
	perror(location);
	cleanup();
	if (exit_status == USE_ERRNO)
		exit(_errno);
	exit(exit_status);
}

void	die_full(char *location, char *message, int exit_status)
{
	int	_errno;

	_errno = errno;
	print_location_error(location, message);
	cleanup();
	if (exit_status == USE_ERRNO)
		exit(_errno);
	exit(exit_status);
}
