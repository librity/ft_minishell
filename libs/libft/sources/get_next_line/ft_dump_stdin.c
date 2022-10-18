/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:36:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/13 20:21:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

/**
 * @brief Read from STDIN until GNL_FOUND_EOF or GNL_ERROR.
 */
void	ft_dump_stdin(void)
{
	ft_dump_fd(STDIN_FILENO);
}
