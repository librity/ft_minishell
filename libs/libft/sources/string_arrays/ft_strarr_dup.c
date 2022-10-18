/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/09 00:59:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Clones a NULL-terminated C-string array.
 *
 * @param clone_me The string array to be cloned.
 * @return char** The cloned array or NULL.
 */
char	**ft_strarr_dup(char **clone_me)
{
	char	**clone;
	char	**copier;

	if (clone_me == NULL)
		return (NULL);
	clone = ft_strarr_new(ft_strarr_len(clone_me));
	copier = clone;
	while (*clone_me != NULL)
	{
		*copier = ft_strdup(*clone_me);
		copier++;
		clone_me++;
	}
	*copier = NULL;
	return (clone);
}
