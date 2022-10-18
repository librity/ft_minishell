/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uc_to_buffer_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/29 15:21:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static unsigned int	count_chars(unsigned char number, unsigned int base_length)
{
	unsigned int	digit_count;

	digit_count = 1;
	number /= base_length;
	while (number != 0)
	{
		digit_count++;
		number /= base_length;
	}
	return (digit_count);
}

static unsigned int	write_digits(char *buffer,
							unsigned char number,
							char *base,
							unsigned int base_length)
{
	unsigned int	char_count;
	unsigned int	i;

	char_count = count_chars(number, base_length);
	i = char_count;
	while (i--)
	{
		buffer[i] = base[number % base_length];
		number /= base_length;
	}
	return (char_count);
}

/**
 * @brief Parses an unsigned char
 * and writes it to a previously-allocated buffer.
 *
 * @param number The unsigned char to be parsed.
 * @param base A string with the characters that represent a number
 * in a counting system.
 * @param buffer The buffer's address.
 * @return unsigned int The number of characters written.
 */
unsigned int	ft_uc_to_buffer_base(unsigned char number, char *base,
						char *buffer)
{
	unsigned int	base_length;
	unsigned int	char_count;

	base_length = ft_strlen(base);
	if (!ft_is_valid_base(base, base_length))
		ft_die(BASE_ERR);
	char_count = write_digits(buffer, number, base, base_length);
	return (char_count);
}
