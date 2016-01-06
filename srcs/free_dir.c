/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:32:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 10:46:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_dir_files(t_directory *dir)
{
	t_file_list			*list;
	t_file_list			*next;

	list = dir->files;
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

void	free_dir(t_directory *dir)
{
	t_directory_list	*d_list;
	t_directory_list	*d_prev;

	d_list = dir->directories;
	while (d_list)
	{
		d_prev = d_list->next;
		free(d_list);
		d_list = d_prev;
	}
	free(dir);
}
