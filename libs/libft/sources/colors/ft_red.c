/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints a string to standard out in red.
 *
 * @param str The string to be printed.
 */
void	ft_red(char *str)
{
	ft_putstr(R);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in red followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_red_endl(char *str)
{
	ft_putstr(R);
	ft_putstr(str);
	ft_putendl(RC);
}

/**
 * @brief Prints a string to standard out in bold red.
 *
 * @param str The string to be printed.
 */
void	ft_redb(char *str)
{
	ft_putstr(RB);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in bold red followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_redb_endl(char *str)
{
	ft_putstr(RB);
	ft_putstr(str);
	ft_putendl(RC);
}
