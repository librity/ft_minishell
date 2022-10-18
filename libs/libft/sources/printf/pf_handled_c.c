/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handled_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:00:32 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 20:21:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	set_print_me(t_printf *print_control, t_handle_c *control)
{
	control->print_me = (unsigned char)va_arg(print_control->elements, int);
}

static void	initialize_control(t_printf *print_control, t_handle_c *control)
{
	control->print_me = '\0';
	control->char_count = 1;
	pf_initialize_flag_control(print_control, &(control->flag_control));
}

/**
 * @brief Handles printf's %c conversion.
 *
 * @param print_control The main control struct.
 * @return true If it printed the conversion.
 * @return false If it didn't print the conversion.
 */
bool	pf_handled_c(t_printf *print_control)
{
	static t_handle_c		control;
	static t_parse_flags	*flag_control;

	if (print_control->conversion != 'c')
		return (false);
	initialize_control(print_control, &control);
	flag_control = &(control.flag_control);
	pf_parse_flags(print_control, flag_control);
	set_print_me(print_control, &control);
	pf_print_c(print_control, &control, flag_control);
	return (true);
}
