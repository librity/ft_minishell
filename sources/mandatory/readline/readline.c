/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:00:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/07 11:15:18 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/******************************************************************************\
 * INIT
\******************************************************************************/

int	init_shell(void)
{
	printf("\e[1;1H\e[2J");
	while (1)
	{
		get_line();
		// Expansor
		//Syntax_Validator();
		// Trimmer
		// Parser
		//exec_cmd();
		//destroy_line_cmd();
		break ;
	}
	return (0);
}
