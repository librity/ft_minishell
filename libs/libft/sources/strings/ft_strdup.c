/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates an allocated string with the same chars of s.
 *
 * @param s The C-string to be duplicated.
 * @return char* The cloned C-string.
 */
char	*ft_strdup(const char *s)
{
	size_t	original_size;
	char	*new_string;

	original_size = ft_strsize(s);
	new_string = ft_salloc((original_size) * sizeof(char));
	ft_memcpy(new_string, s, original_size);
	return (new_string);
}
