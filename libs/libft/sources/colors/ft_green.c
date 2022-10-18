/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:23:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints a string to standard out in green.
 *
 * @param str The string to be printed.
 */
void	ft_green(char *str)
{
	ft_putstr(G);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in green followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_green_endl(char *str)
{
	ft_putstr(G);
	ft_putstr(str);
	ft_putendl(RC);
}

/**
 * @brief Prints a string to standard out in bold green.
 *
 * @param str The string to be printed.
 */
void	ft_greenb(char *str)
{
	ft_putstr(GB);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in bold green followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_greenb_endl(char *str)
{
	ft_putstr(GB);
	ft_putstr(str);
	ft_putendl(RC);
}
