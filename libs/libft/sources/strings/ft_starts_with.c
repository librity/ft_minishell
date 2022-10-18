/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starts_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Returns true if string stats with prefix.
 *
 * @param str The C-string to be checked.
 * @param prefix The prefix to check.
 * @return true If str starts with prefix.
 * @return false If str does not start with prefix.
 */
bool	ft_starts_with(char *string, char *prefix)
{
	char	*test;

	test = ft_strnstr(string, prefix, ft_strlen(prefix));
	if (test != NULL)
		return (true);
	return (false);
}
