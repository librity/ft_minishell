/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_up_to.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 03:17:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints a string s up to an arbitrary position.
 *
 * @param str The C-string to be printed.
 * @param up_to The number of bytes to print.
 */
void	ft_putstr_up_to(char *str, size_t up_to)
{
	size_t	control;

	control = 0;
	if (str == NULL)
		return ;
	while (str[control] != '\0' && control < up_to)
		ft_putchar(str[control++]);
}
