/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_white.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints a string to standard out in white.
 *
 * @param str The string to be printed.
 */
void	ft_white(char *str)
{
	ft_putstr(W);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in white followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_white_endl(char *str)
{
	ft_putstr(W);
	ft_putstr(str);
	ft_putendl(RC);
}

/**
 * @brief Prints a string to standard out in bold white.
 *
 * @param str The string to be printed.
 */
void	ft_whiteb(char *str)
{
	ft_putstr(WB);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in bold white followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_whiteb_endl(char *str)
{
	ft_putstr(WB);
	ft_putstr(str);
	ft_putendl(RC);
}
