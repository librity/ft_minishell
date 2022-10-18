/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:40:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Calculates the power of an arbitrary int.
 *
 * @param base The number to be exponentiated.
 * @param exponent The number of times the base will be multiplied with itself.
 * @return int The power.
 */
int	ft_pow_i(int base, int exponent)
{
	int	result;

	if (exponent < 0)
		return (0);
	if (exponent == 0)
		return (1);
	result = 1;
	result = result * base * ft_pow_i(base, exponent - 1);
	return (result);
}
