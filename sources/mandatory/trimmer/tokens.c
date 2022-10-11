/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:31:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 15:21:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	trim_tokens(char **tokens)
{
	while (*tokens != NULL)
	{
		trim_token(*tokens);
		tokens++;
	}
}
