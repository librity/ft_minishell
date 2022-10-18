/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 22:44:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	write_digits(char *string,
							unsigned int digit_count,
							unsigned int number)
{
	string[digit_count] = '\0';
	while (digit_count--)
	{
		string[digit_count] = '0' + (number % 10);
		number /= 10;
	}
}

/**
 * @brief Parses an unsigned int n into an allocated string.
 *
 * @param number The unsigned int to be parsed.
 * @return char* Its string representation.
 */
char	*ft_uitoa(unsigned int number)
{
	unsigned int	digit_count;
	char			*string;

	digit_count = ft_count_chars_ui(number);
	string = ft_salloc(sizeof(char) * (digit_count + 1));
	write_digits(string, digit_count, number);
	return (string);
}
