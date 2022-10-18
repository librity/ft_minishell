/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:54:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates an allocated string joining free_me with dont_free_me,
 * then frees free_me.
 *
 * @param free_me  The first C-string to be joined and freed.
 * @param dont_free_me  The second C-string to be joined.
 * @return char* The joined C-string.
 */
char	*ft_strjoin_free(char *free_me, char const *dont_free_me)
{
	char	*new_string;

	new_string = ft_strjoin(free_me, dont_free_me);
	free(free_me);
	return (new_string);
}
