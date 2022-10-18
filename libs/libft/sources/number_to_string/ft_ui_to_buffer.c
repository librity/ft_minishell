/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui_to_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 22:44:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	write_digits(char *string,
							unsigned int char_count,
							unsigned int number)
{
	string[char_count] = '\0';
	while (char_count--)
	{
		string[char_count] = '0' + (number % 10);
		number /= 10;
	}
}

/**
 * @brief Parses an unsigned int
 * and writes it to a previously-allocated buffer.
 *
 * @param number The unsigned int to be parsed.
 * @param buffer The buffer's address.
 * @return unsigned int The number of characters written.
 */
unsigned int	ft_ui_to_buffer(unsigned int number, char *buffer)
{
	unsigned int	char_count;

	char_count = ft_count_chars_ui(number);
	write_digits(buffer, char_count, number);
	return (char_count);
}
