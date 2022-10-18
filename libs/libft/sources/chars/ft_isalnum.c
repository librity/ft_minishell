/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:23:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Checks if character is an ASCII letter or a number.
 *
 * @param character The char to be checked.
 * @return true Character is an ASCII letter or a number.
 * @return false Character is not an ASCII letter or a number.
 */
bool	ft_isalnum(char character)
{
	return (ft_isalpha(character) || ft_isdigit(character));
}
