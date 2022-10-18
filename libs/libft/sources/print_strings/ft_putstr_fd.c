/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:22:45 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Writes string s to file descriptor fd without null terminator.
 *
 * @param str The C-string to be printed.
 * @param fd The file descriptor to write to.
 */
void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str)
		ft_putchar_fd(*str++, fd);
}
