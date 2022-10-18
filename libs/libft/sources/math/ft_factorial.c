/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:25:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Calculates the factorial of an int.
 *
 * @param number The number to be factorialized.
 * @return int Its factorial.
 */
int	ft_factorial(int number)
{
	int	factorial;

	if (number < 0)
		return (0);
	if (number == 0 || number == 1)
		return (1);
	factorial = number * ft_factorial(number - 1);
	return (factorial);
}
