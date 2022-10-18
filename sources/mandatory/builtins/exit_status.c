/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:31:09 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/14 13:09:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	str_is_number(char *status)
{
	if (*status == '+' || *status == '-')
		status++;
	while (*status)
	{
		if (*status < '0' || *status > '9')
			return (false);
		status++;
	}
	return (true);
}

static bool	check_negative_limit(char *status)
{
	int	len;

	status++;
	len = ft_strlen(status);
	if (len < 19)
		return (true);
	if (len == 19 && status[len - 1] <= '8')
		return (true);
	return (false);
}

static bool	check_positive_limit(char *status)
{
	int	len;

	if (*status == '+')
		status++;
	len = ft_strlen(status);
	if (len < 19)
		return (true);
	if (len == 19 && status[len - 1] <= '7')
		return (true);
	return (false);
}

int	exit_status_is_too_long(char *status)
{
	if (!str_is_number(status))
		return (false);
	if (*status == '-')
		return (check_negative_limit(status));
	return (check_positive_limit(status));
}
