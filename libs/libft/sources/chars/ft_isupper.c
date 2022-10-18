/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 15:15:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Checks if character is an uppercase ASCII letter.
 *
 * @param character The char to be checked.
 * @return true Character is an uppercase ASCII letter.
 * @return false Character is not an uppercase ASCII letter.
 */
bool	ft_isupper(char character)
{
	if (character >= 'A' && character <= 'Z')
		return (true);
	return (false);
}
