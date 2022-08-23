/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:44:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/23 19:45:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	insert_delimiter_before(char *buffer)
{
	strbuff_insert_before(buffer, DELIMITER);
}

void	insert_delimiter_after(char *buffer)
{
	strbuff_insert_after(buffer, DELIMITER);
}

void	insert_delimiter_around(char *buffer)
{
	strbuff_insert_around(buffer, DELIMITER);
}

void	insert_delimiter_around_2(char *buffer)
{
	strbuff_insert_around_2(buffer, DELIMITER);
}
