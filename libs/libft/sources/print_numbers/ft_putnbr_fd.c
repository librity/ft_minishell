/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:35:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Writes ascii representation of an int to a file descriptor fd.
 *
 * @param number The number to be printed.
 * @param fd The file descriptor to write to.
 */
void	ft_putnbr_fd(int number, int fd)
{
	long	_number;

	_number = number;
	if (_number < 0)
	{
		ft_putchar_fd('-', fd);
		_number *= -1;
	}
	if (_number >= 10)
		ft_putnbr_fd(_number / 10, fd);
	ft_putchar_fd('0' + (_number % 10), fd);
}
