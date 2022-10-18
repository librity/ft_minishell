/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:54:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Creates an allocated string joining delete_me with dont_delete_me,
 * then deletes delete_me.
 *
 * @param delete_me The first C-string to be joined and deleted.
 * @param dont_delete_me The second C-string to be joined.
 * @return char* The joined C-string.
 */
char	*ft_strjoin_del(char **delete_me, const char *dont_delete_me)
{
	char	*new_string;

	new_string = ft_strjoin(*delete_me, dont_delete_me);
	ft_strdel(delete_me);
	return (new_string);
}
