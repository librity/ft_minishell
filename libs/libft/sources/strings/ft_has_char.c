/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 17:15:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Checks if the string contains the character.
 *
 * @param str The C-string to be checked.
 * @param c The character to be searched.
 * @return true The string contains the character.
 * @return false The string does not contain the character.
 */
bool	ft_has_char(char *str, char c)
{
	if (ft_strchr(str, c) == NULL)
		return (false);
	return (true);
}
