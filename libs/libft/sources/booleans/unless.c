/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unless.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:23:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Flips a boolean.
 *
 * @param condition The boolean to be flipped.
 * @return true If condition is false.
 * @return false If condition is true.
 */
bool	unless(bool condition)
{
	return (condition == false);
}
