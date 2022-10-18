/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_strarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:50:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/05 20:15:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Joins all strings of a C-string array.
 * If the array is NULL or empty returns NULL.
 *
 * @param strarr The string array to be joined.
 * @return char* The joined string or NULL.
 */
char	*ft_join_strarr(char **strarr)
{
	char	*joined;

	if (strarr == NULL)
		return (NULL);
	if (*strarr == NULL)
		return (NULL);
	joined = ft_strdup(*strarr);
	strarr++;
	while (*strarr != NULL)
	{
		joined = ft_strjoin_free(joined, *strarr);
		strarr++;
	}
	return (joined);
}
