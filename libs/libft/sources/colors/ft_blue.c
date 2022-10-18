/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints a string to standard out in blue.
 *
 * @param str The string to be printed.
 */
void	ft_blue(char *str)
{
	ft_putstr(B);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in blue followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_blue_endl(char *str)
{
	ft_putstr(B);
	ft_putstr(str);
	ft_putendl(RC);
}

/**
 * @brief Prints a string to standard out in bold blue.
 *
 * @param str The string to be printed.
 */
void	ft_blueb(char *str)
{
	ft_putstr(BB);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in bold blue followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_blueb_endl(char *str)
{
	ft_putstr(BB);
	ft_putstr(str);
	ft_putendl(RC);
}
