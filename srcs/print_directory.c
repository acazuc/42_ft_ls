/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 11:06:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 16:49:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

static void			print_directory_part(int is_recur, char *path, t_env *env
		, int total_links, t_directory *dir)
{
	if (is_recur)
	{
		ft_putchar('\n');
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (env->l && dir->files != NULL)
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
		print_directory_part(is_recur, path, env, dir->total_links, dir);
		lst = dir->files;
		while (lst)
		{
			print_file(env, lst->file, dir);
			lst = lst->next;
		}
		if (env->recur)
			print_subdirs(env, dir);
		free(dir);
	}
}
