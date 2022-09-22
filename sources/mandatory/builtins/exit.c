/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:14:58 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 11:34:07 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	exit_built_in(char	 **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (false);
	if (!ft_streq(*tokens, "exit"))
		return (false);
	cleanup_shell();
	return (true);
}
