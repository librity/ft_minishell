/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui_to_buffer_lchex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 15:27:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Parses an unsigned int
 * and writes it to a previously-allocated buffer
 * in lowercase hexadecimal.
 *
 * @param number The unsigned int to be parsed.
 * @param buffer The buffer's address.
 * @return unsigned int The number of characters written.
 */
unsigned int	ft_ui_to_buffer_lchex(unsigned int number, char *buffer)
{
	int	i;

	i = UI_LOWERCASE_HEX_SIZE;
	while (i--)
	{
		buffer[i] = LOWERCASE_HEX_BASE[number % 16];
		number /= 16;
	}
	return (UI_LOWERCASE_HEX_SIZE);
}
