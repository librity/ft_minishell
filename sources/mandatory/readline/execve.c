/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:46:57 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/02 16:54:47 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exec_cmd(void)
{
	char	*cmd_path;

	cmd_path = get_cmd_path("teste");
	//
	// execve
	return (NULL);
}
