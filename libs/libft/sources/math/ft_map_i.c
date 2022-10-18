/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:16:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Maps an int that varies between a range into target range.
 *
 * @param args.x The number to be mapped to the second range.
 * @param args.from_1 The minimum of the first range.
 * @param args.to_1 The maximum of the first range.
 * @param args.from_2 The minimum of the second range.
 * @param args.to_2 The maximum of the second range.
 * @return int The mapped value from range 1 to range 2.
 */
int	ft_map_i(t_map_i args)
{
	int	mapped;

	mapped = (args.x - args.from_1)
		* (args.to_2 - args.from_2)
		/ (args.to_1 - args.from_1)
		+ args.from_2;
	return (mapped);
}
