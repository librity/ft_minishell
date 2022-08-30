/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_Validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:45:45 by wwallas-          #+#    #+#             */
/*   Updated: 2022/08/30 11:46:19 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	Syntax_Validator(void)
{
	int		index;

	index = 0;
	while(token_index(index))
	{
		if (token_index(index)[0] == SINGLE_QUOTE)
			token_edit(index, ft_strtrim(token_index(index), "\'"));
		else if (token_index(index)[0] == DOUBLE_QUOTE)
			token_edit(index, ft_strtrim(token_index(index), "\""));
		index++;
	}
}
