/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_minus_sign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:31:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/26 00:39:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief If a long is negative, prints the minus sign and flips it.
 *
 * @param number_pointer Address of the number.
 */
void	pf_handle_minus_sign_l(long *number_pointer)
{
	if (*number_pointer < 0)
	{
		ft_putchar('-');
		*number_pointer *= -1;
	}
}

/**
 * @brief If a long long is negative, prints the minus sign and flips it.
 *
 * @param number_pointer Address of the number.
 */
void	pf_handle_minus_sign_ll(long long *number_pointer)
{
	if (*number_pointer < 0)
	{
		ft_putchar('-');
		*number_pointer *= -1;
	}
}

/**
 * @brief If a float is negative, prints the minus sign and flips it.
 *
 * @param number_pointer Address of the number.
 */
void	pf_handle_minus_sign_f(float *number_pointer)
{
	if (*number_pointer < 0)
	{
		ft_putchar('-');
		*number_pointer *= -1;
	}
}

/**
 * @brief If a double is negative, prints the minus sign and flips it.
 *
 * @param number_pointer Address of the number.
 */
void	pf_handle_minus_sign_d(double *number_pointer)
{
	if (*number_pointer < 0)
	{
		ft_putchar('-');
		*number_pointer *= -1;
	}
}

/**
 * @brief If a long double is negative, prints the minus sign and flips it.
 *
 * @param number_pointer Address of the number.
 */
void	pf_handle_minus_sign_ld(long double *number_pointer)
{
	if (*number_pointer < 0)
	{
		ft_putchar('-');
		*number_pointer *= -1;
	}
}
