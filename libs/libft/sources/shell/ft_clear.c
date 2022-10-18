/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:59:05 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/25 21:41:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Scrolls the cursor of the terminal
 * to the top so the screen gets cleared.
 *
 */
void	ft_clear(void)
{
	ft_putstr(CLEAR_ESCAPE_SEQUENCE);
}
