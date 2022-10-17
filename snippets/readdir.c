/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:52:32 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/10/17 19:16:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc readdir.c && ./a.out

#include <dirent.h>
#include <stdio.h>

int	main(void)
{
	DIR				*folder;
	struct dirent	*entry;
	int				files;

	files = 0;
	folder = opendir(".");
	if (folder == NULL)
	{
		perror("Unable to read directory");
		return (1);
	}
	while ((entry = readdir(folder)))
	{
		files++;
		printf("File %3d: %s, type %d\n",
				files,
				entry->d_name, entry->d_type);
	}
	closedir(folder);
	return (0);
}
