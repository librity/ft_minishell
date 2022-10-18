/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:36:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Divides two ints with remainder.
 *
 * @param dividend The number to be divided.
 * @param divisor The divider.
 * @param result Pointer to the result.
 * @param remainder Pointer to the reamainder.
 */
void	ft_div_mod_i(int dividend, int divisor, int *result, int *remainder)
{
	if (divisor == 0)
		return ;
	*result = dividend / divisor;
	*remainder = dividend % divisor;
}
