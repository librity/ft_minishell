/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bdebug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 03:16:34 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 20:20:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Behaves exactly like printf but with a "DEBUG: " suffix and an endline.
 * Only executes if debug is true.
 *
 * @param debug The debug boolean.
 * @param format The printf format with conversions and flags.
 * @param ... The variables to be inserted in the format string.
 */
void	ft_bdebug(bool debug, const char *format, ...)
{
	static t_printf	print_control;

	if (!debug)
		return ;
	ft_yellowb(DEBUG_SUFFIX);
	pf_initialize_print_control(&print_control, format);
	va_start(print_control.elements, format);
	pf_vprintf(&print_control);
	va_end(print_control.elements);
	ft_endl();
}
