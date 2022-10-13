/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_is_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:31:09 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/13 17:16:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_digit(char *nptr)
{
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr)
	{
		if (*nptr < '0' || *nptr > '9')
			return (false);
		nptr++;
	}
	return (true);
}

bool	check_storo_negative(char *nptr)
{
	int	len;

	nptr++;
	len = ft_strlen(nptr);
	if (len < 19)
		return (true);
	if (len == 19 && nptr[len - 1] <= '8')
		return (true);
	return (false);
}

bool	check_storo_positivo(char *nptr)
{
	int	len;

	if (*nptr == '+')
		nptr++;
	len = ft_strlen(nptr);
	if (len < 19)
		return (true);
	if (len == 19 && nptr[len - 1] <= '7')
		return (true);
	return (false);
}

int	tokens_is_long(char *nptr)
{
	if (!is_digit(nptr))
		return (false);
	if (*nptr == '-')
		return (check_storo_negative(nptr));
	return (check_storo_positivo(nptr));
}
