/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_black.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:22:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:24:51 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints a string to standard out in black.
 *
 * @param str The string to be printed.
 */
void	ft_black(char *str)
{
	ft_putstr(BK);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in black followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_black_endl(char *str)
{
	ft_putstr(BK);
	ft_putstr(str);
	ft_putendl(RC);
}

/**
 * @brief Prints a string to standard out in bold black.
 *
 * @param str The string to be printed.
 */
void	ft_blackb(char *str)
{
	ft_putstr(BKB);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in bold black followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_blackb_endl(char *str)
{
	ft_putstr(BKB);
	ft_putstr(str);
	ft_putendl(RC);
}
