/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:52:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Prints a string to standard out in purple.
 *
 * @param str The string to be printed.
 */
void	ft_purple(char *str)
{
	ft_putstr(P);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in purple followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_purple_endl(char *str)
{
	ft_putstr(P);
	ft_putstr(str);
	ft_putendl(RC);
}

/**
 * @brief  Prints a string to standard out in bold purple.
 *
 * @param str The string to be printed.
 */
void	ft_purpleb(char *str)
{
	ft_putstr(PB);
	ft_putstr(str);
	ft_putstr(RC);
}

/**
 * @brief Prints a string to standard out in bold purple followed by an endline.
 *
 * @param str The string to be printed.
 */
void	ft_purpleb_endl(char *str)
{
	ft_putstr(PB);
	ft_putstr(str);
	ft_putendl(RC);
}
