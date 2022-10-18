/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clamped_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:16:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Maps a double that varies between a range into a target range.
 * If the result lies outside the target
 * it returns the closest limit, min or max.
 *
 * @param args.x The number to be mapped to the second range.
 * @param args.from_1 The minimum of the first range.
 * @param args.to_1 The maximum of the first range.
 * @param args.from_2 The minimum of the second range.
 * @param args.to_2 The maximum of the second range.
 * @return double The mapped value from range 1 to range 2.
 */
double	ft_map_clamped_d(t_map_d args)
{
	double	mapped;

	mapped = ft_map_d(args);
	if (args.from_2 < args.to_2)
		return (ft_clamp_d(mapped, args.from_2, args.to_2));
	return (ft_clamp_d(mapped, args.to_2, args.from_2));
}
