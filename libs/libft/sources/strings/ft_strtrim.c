/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:26:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Removes set from beginning and end of s1.
 *
 * @param s1 The C-string to be trimmed.
 * @param set The C-string to trim.
 * @return char* The allocated string without set.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	trimmed_end = ft_strlen(s1);
	while (trimmed_end && ft_strchr(set, s1[trimmed_end]))
		trimmed_end--;
	return (ft_substr(s1, 0, trimmed_end + 1));
}
