/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:41:10 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/29 16:08:43 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**tokens(void)
{
	return (c()->tokens);
}

char	*token_index(int index)
{
	return(c()->tokens[index]);
}

void	token_edit(int index, char *str)
{
	c()->tokens[index] = str;
}
