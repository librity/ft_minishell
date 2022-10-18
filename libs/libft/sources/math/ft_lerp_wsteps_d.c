/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp_wsteps_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Linearly interpolates a double x with discrete increments (steps).
 *
 * @param from Minimum know value of y.
 * @param to Maximum know value of y.
 * @param steps The number of discrete increments between from and to.
 * @param x The number to be linearly interpolated.
 * @return double y at x assuming a linear relation between from and to.
 */
double	ft_lerp_wsteps_d(double from, double to, double steps, double x)
{
	double	step;

	step = (to - from) / (steps - 1);
	return (from + (step * x));
}
