/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_dup_shallow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/11 17:02:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates a shallow copy of a NULL-terminated C-string array.
 *
 * @param copy_me The string array to be copied.
 * @return char** The cloned array or NULL.
 */
char	**ft_strarr_dup_shallow(char **copy_me)
{
	char	**clone;
	char	**copier;

	if (copy_me == NULL)
		return (NULL);
	clone = ft_strarr_new(ft_strarr_len(copy_me));
	copier = clone;
	while (*copy_me != NULL)
	{
		*copier = *copy_me;
		copier++;
		copy_me++;
	}
	*copier = NULL;
	return (clone);
}
