/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uc_to_buffer_lchex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 15:28:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Parses an unsigned char
 * and writes it to a previously-allocated buffer
 * in lowercase hexadecimal.
 *
 * @param number The unsigned char to be parsed.
 * @param buffer The buffer's address.
 * @return unsigned int The number of characters written.
 */
unsigned int	ft_uc_to_buffer_lchex(unsigned char number, char *buffer)
{
	int	i;

	i = UC_LOWERCASE_HEX_SIZE;
	while (i--)
	{
		buffer[i] = LOWERCASE_HEX_BASE[number % 16];
		number /= 16;
	}
	return (UC_LOWERCASE_HEX_SIZE);
}
