/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 11:06:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 16:20:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*static void		putspaces(int number)
{
	while (--number >= 0)
		ft_putchar(' ');
}

static void		print_file(t_file *file, t_directory *dir)
{
	ft_putstr(file->perms);
	putspaces(2 + dir->links_len - ft_strlen(file->links));
	ft_putstr(file->links);
	putspaces(1 + dir->user_len - ft_strlen(file->user));
	ft_putstr(file->user);
	putspaces(2 + dir->group_len - ft_strlen(file->group));
	ft_putstr(file->group);
	putspaces(2 + dir->size_len - ft_strlen(file->size));
	ft_putstr(file->size);
	putspaces(1 + dir->date_len - ft_strlen(file->date));
	ft_putstr(file->date);
	ft_putchar(' ');
	ft_putstr(file->name);
}*/

void			print_subdirs(t_env *env, t_directory *dir)
{
	t_file_list		*lst;
	t_file_list		*prv;
	char			*tmp;

	lst = dir->files;
	while (lst)
	{
		if (lst->file->is_dir)
		{
			if (ft_strcmp(lst->file->name, ".") && ft_strcmp(lst->file->name, ".."))
			{
				tmp = ft_strjoin_free1(ft_strjoin(dir->path, "/"), lst->file->name);
				print_directory(env, tmp, 1);
				free(tmp);
			}
		}
		free_file(env, lst->file);
		prv = lst;
		lst = lst->next;
		free(prv);
	}
}

void			print_directory_part(int is_recur, char *path, t_env *env
		, int total_links)
{
	if (is_recur)
	{
		ft_putchar('\n');
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (env->l)
	{
		ft_putstr("total ");
		ft_putnbr(total_links);
		ft_putchar('\n');
	}
}

void			print_directory(t_env *env, char *path, int is_recur)
{
	t_directory			*dir;
	t_file_list			*lst;

	if ((dir = load_directory(env, path)))
	{
		print_directory_part(is_recur, path, env, dir->total_links);
		lst = dir->files;
		while (lst)
		{
			/*if (env->l)
				print_file(lst->file, dir);
			else
				ft_putstr(lst->file->name);
			ft_putchar('\n');*/
			print_file(env, lst->file, dir);
			lst = lst->next;
		}
		if (env->recur)
			print_subdirs(env, dir);
		free(dir);
	}
}
