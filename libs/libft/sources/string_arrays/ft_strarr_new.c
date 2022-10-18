/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 00:06:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Allocates a string array of size = (length + 1)
 * full of NULL pointers.
 *
 * @param length The number of strings in the array.
 * @return char** The allocated string array.
 */
char	**ft_strarr_new(size_t length)
{
	char	**strarr;

	strarr = ft_scalloc(sizeof(char **), (length + 1));
	return (strarr);
}
