/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_date_asc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:49:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/01 17:23:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		file_switch(t_file_list *lst1, t_file_list *lst2)
{
	t_file			*file;

	file = lst1->file;
	lst1->file = lst2->file;
	lst2->file = file;
}

static int		check_file_switch(t_file_list *list, t_file_list *prev)
{
	int				moved;

	moved = 0;
	if (prev && prev->file->timestamp - list->file->timestamp < 0)
	{
		file_switch(list, prev);
		moved = 1;
	}
	if (list->next
			&& list->next->file->timestamp - list->file->timestamp > 0)
	{
		file_switch(list, list->next);
		moved = 1;
	}
	return (moved);
}

void			sort_date_asc(t_directory *dir)
{
	t_file_list		*list;
	t_file_list		*prev;
	int				moved;

	moved = 1;
	while (moved)
	{
		moved = 0;
		list = dir->files;
		prev = NULL;
		while (list)
		{
			moved = moved || check_file_switch(list, prev);
			prev = list;
			list = list->next;
		}
	}
}
