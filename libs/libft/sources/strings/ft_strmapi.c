/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 23:09:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Returns an allocated string with each char modified by f.
 *
 * @param s The C-string to be mapped.
 * @param f The callback that runs on char of the list.
 * @return char* The new mapped string.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map_start;
	char	*map;

	map_start = ft_strdup(s);
	if (map_start == NULL)
		return (NULL);
	map = map_start;
	while (*map)
	{
		*map = f(map - map_start, *map);
		map++;
	}
	return (map_start);
}
