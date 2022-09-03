/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:41:33 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/02 17:05:24 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	vf_clone_quote(char	*line)
{
	int	single;
	int	doub;

	single = 0;
	doub = 0;
	while(*line)
	{
		if (*line == SINGLE_QUOTE && doub % 2 == 0)
			single++;
		if (*line == DOUBLE_QUOTE && single % 2 == 0)
			doub++;
		line++;
	}
	if (single % 2 == 1 || doub % 2 == 1)
		return (false); //função pra lipar e sair;
	return (true);
}
