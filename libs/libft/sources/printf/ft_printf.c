/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 03:16:34 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 20:32:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints ints, floats and strings according to a format string.
 *
 * @param format The printf format with conversions and flags.
 * @param ... The variables to be inserted in the format string.
 * @return int If negative, an error occurred.
 * If positive, the number of chars printed.
 */
int	ft_printf(const char *format, ...)
{
	static t_printf	print_control;

	pf_initialize_print_control(&print_control, format);
	va_start(print_control.elements, format);
	pf_vprintf(&print_control);
	va_end(print_control.elements);
	return (print_control.chars_printed);
}
