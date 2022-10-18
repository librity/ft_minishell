/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Returns last occurence of char c in string or NULL.
 *
 * @param s The C-string to be searched.
 * @param c	The char to search.
 * @return char* The last location of the char or NULL.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*s_end;

	s_end = ft_strchr(s, '\0');
	while (*s_end != (char)c)
		if (s_end-- == s)
			return (NULL);
	return ((char *)s_end);
}
