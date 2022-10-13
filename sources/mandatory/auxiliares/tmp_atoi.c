/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:15:33 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/12 17:17:56 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int converte_number_int(const char *nptr)
{
	int result;

	result = 0;
	while ((*nptr >= '0' && *nptr <= '9') || *nptr >= '-')
	{
		result = (*nptr - 48) + (result * 10);
		nptr++;
	}
	return (result);
}

int	tmp_atoi(const char *nptr)
{
	int	result;
	int	sig;

	sig = 1;
	if (*nptr == '-')
		sig = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	result = converte_number_int(nptr) * sig;
	return (result);
}
