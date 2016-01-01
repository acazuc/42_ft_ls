/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 11:06:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/01 17:36:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		putspaces(int number)
{
	while (--number >= 0)
		ft_putchar(' ');
}

static void		print_file(t_file *file, t_directory *dir)
{
	ft_putstr(file->perms);
	putspaces(1 + dir->links_len - ft_strlen(file->links));
	ft_putstr(file->links);
	putspaces(1 + dir->user_len - ft_strlen(file->user));
	ft_putstr(file->user);
	putspaces(1 + dir->group_len - ft_strlen(file->group));
	ft_putstr(file->group);
	putspaces(1 + dir->size_len - ft_strlen(file->size));
	ft_putstr(file->size);
	ft_putchar(' ');
	ft_putstr(file->date);
	ft_putchar(' ');
	ft_putstr(file->name);
	ft_putchar('\n');
}

void			print_directory(t_env *env, char *path, int is_recur)
{
	t_directory		*dir;
	t_file_list		*lst;

	if ((dir = load_directory(env, path)))
	{
		if (env->l)
		{
			ft_putstr("total ");
			ft_putnbr(dir->total_links);
			ft_putchar('\n');
		}
		lst = dir->files;
		while (lst)
		{
			if (env->l)
				print_file(lst->file, dir);
			else
			{
				ft_putstr(lst->file->name);
				ft_putchar(' ');
			}
			lst = lst->next;
		}
	}
	(void)is_recur;
}
