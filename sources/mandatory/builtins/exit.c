/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:14:58 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 14:03:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	bi_exit(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (false);
	if (!ft_streq(*tokens, "exit"))
		return (false);
	quit();
	return (true);
}
