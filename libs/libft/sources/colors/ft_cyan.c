/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints a string to standard out in cyan.
 *
 * @param str The string to be printed.
 */
void	ft_cyan(char *str)
{
	ft_putstr(C);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in cyan followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_cyan_endl(char *str)
{
	ft_putstr(C);
	ft_putstr(str);
	ft_putendl(RC);
}

/**
 * @brief Prints a string to standard out in bold cyan.
 *
 * @param str The string to be printed.
 */
void	ft_cyanb(char *str)
{
	ft_putstr(CB);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in bold cyan followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_cyanb_endl(char *str)
{
	ft_putstr(CB);
	ft_putstr(str);
	ft_putendl(RC);
}
