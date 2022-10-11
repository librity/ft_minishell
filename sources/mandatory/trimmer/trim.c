/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:31:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/11 15:20:17 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	debug_tokens(char **tokens)
{
	if (!debug())
		return ;
	ft_yellowb("DEBUG:\t");
	ft_putstr("trimmed tokens = { ");
	ft_put_strarr_inline(tokens);
	ft_putstr(", NULL };\n");
}

void	trim(char **tokens)
{
	trim_tokens(tokens);
	debug_tokens(tokens);
}
