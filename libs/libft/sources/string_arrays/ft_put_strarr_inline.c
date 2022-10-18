/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_strarr_inline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/10 16:37:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints an array of strings to standard out in the same line.
 *
 * @param strings The C-string array to be printed.
 */
void	ft_put_strarr_inline(char **strings)
{
	while (*strings)
	{
		ft_putchar('\"');
		ft_putstr(*strings++);
		ft_putchar('\"');
		if (*strings != NULL)
			ft_putstr(", ");
	}
}
