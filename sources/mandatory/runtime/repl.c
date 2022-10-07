/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:00:56 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/07 15:45:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	repl(void)
{
	printf("\e[1;1H\e[2J");
	while (1)
	{
		prompt();
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
