/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yellow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints a string to standard out in yellow.
 *
 * @param str The string to be printed.
 */
void	ft_yellow(char *str)
{
	ft_putstr(Y);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in yellow followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_yellow_endl(char *str)
{
	ft_putstr(Y);
	ft_putstr(str);
	ft_putendl(RC);
}

/**
 * @brief Prints a string to standard out in bold yellow.
 *
 * @param str The string to be printed.
 */
void	ft_yellowb(char *str)
{
	ft_putstr(YB);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in bold yellow followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_yellowb_endl(char *str)
{
	ft_putstr(YB);
	ft_putstr(str);
	ft_putendl(RC);
}
