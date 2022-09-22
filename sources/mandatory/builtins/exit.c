/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:14:58 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 15:27:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	exit_built_in(char **tokens)
{
	if (tokens == NULL || *tokens == NULL)
		return (false);
	if (!ft_streq(*tokens, "exit"))
		return (false);
	cleanup_shell();
	exit(EXIT_SUCCESS);
	return (true);
}
