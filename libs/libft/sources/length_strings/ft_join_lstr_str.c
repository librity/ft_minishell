/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_lstr_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:46:55 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Apends a C-string to a length string.
 *
 * @param lstr The length string to be appended to.
 * @param str The C-string to be appended.
 * @param str_size The size of the C-string.
 */
void	ft_join_lstr_str(t_lstr *lstr, char *str, size_t str_size)
{
	size_t	new_length;

	new_length = lstr->len + str_size;
	lstr->ptr = ft_srealloc(lstr->ptr, lstr->len + 1, new_length + 1);
	ft_memcpy(lstr->ptr + lstr->len, str, str_size);
	lstr->ptr[new_length] = '\0';
	lstr->len = new_length;
}
