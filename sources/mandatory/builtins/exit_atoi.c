/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:15:33 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/14 13:29:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	string_to_int(const char *str)
{
	int	result;

	result = 0;
	while (ft_isdigit(*str))
	{
		result = (*str - '0') + (result * 10);
		str++;
	}
	return (result);
}

int	exit_atoi(const char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	return (string_to_int(str) * sign);
}
