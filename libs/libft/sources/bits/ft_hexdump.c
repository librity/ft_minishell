/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:43:44 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/04 23:38:42 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	print_tag(char *tag)
{
	if (tag != NULL)
		ft_printf("%s:\n", tag);
}

static void	pad_last_line(size_t remaining_bytes)
{
	while ((remaining_bytes % 16) != 0)
	{
		ft_printf("   ");
		remaining_bytes++;
	}
}

static void	print_endline(unsigned char buffer[], size_t bytes)
{
	if (bytes != 0)
		ft_printf("  %s\n", buffer);
	ft_printf("  %04x ", bytes);
}

static void	save_to_buffer(unsigned char *_address, unsigned char buffer[],
		size_t bytes)
{
	if (ft_isprint(_address[bytes]))
		buffer[bytes % 16] = _address[bytes];
	else
		buffer[bytes % 16] = '.';
}

/**
 * @brief Prints the contents of the address up to size in hexadecimal.
 *
 * @param tag An optional tag printed before the hexdump.
 * Can be a string or NULL.
 * @param address The memory address of the object.
 * @param size The amount of bytes to print.
 */
void	ft_hexdump(char *tag, void *address, size_t size)
{
	unsigned char	buffer[17];
	unsigned char	*_address;
	size_t			bytes;

	print_tag(tag);
	ft_bzero(buffer, 17);
	_address = address;
	bytes = 0;
	while (bytes < size)
	{
		if ((bytes % 16) == 0)
			print_endline(buffer, bytes);
		ft_printf(" %02x", _address[bytes]);
		save_to_buffer(_address, buffer, bytes);
		bytes++;
	}
	pad_last_line(bytes);
	ft_printf("  %s\n", buffer);
}
