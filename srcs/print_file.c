/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:16:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 16:07:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		putspaces(int number)
{
	while (--number >= 0)
		ft_putchar(' ');
}

static void		put_user(t_env *env, t_file *file, t_directory *dir)
{
	if (!env->g)
	{
		ft_putchar(' ');
		ft_putstr(file->user);
		putspaces(1 + dir->user_len - ft_strlen(file->user));
	}
}

static void		put_group(t_env *env, t_file *file, t_directory *dir)
{
	if (!env->o)
	{
		ft_putchar(' ');
		ft_putstr(file->group);
		putspaces(1 + dir->group_len - ft_strlen(file->group));
	}
}

void			print_file(t_env *env, t_file *file, t_directory *dir)
{
	env->printed_file = 1;
	if (env->i)
	{
		ft_putnbr(file->inode);
		ft_putchar(' ');
	}
	if (env->l)
	{
		ft_putstr(file->perms);
		putspaces(1 + dir->links_len - ft_strlen(file->links));
		ft_putstr(file->links);
		put_user(env, file, dir);
		put_group(env, file, dir);
		if (env->o && env->g)
			putspaces(2);
		putspaces(1 + dir->size_len - ft_strlen(file->size));
		ft_putstr(file->size);
		putspaces(1 + dir->date_len - ft_strlen(file->date));
		ft_putstr(file->date);
		ft_putchar(' ');
	}
	ft_putstr(file->name);
	if (env->f_caps)
	{
		if (file->is_lnk)
			ft_putchar('@');
		else if (file->is_dir)
			ft_putchar('/');
		else if (file->is_sock)
			ft_putchar('=');
		else if (file->is_exe)
			ft_putchar('*');
		else if (file->is_whout)
			ft_putchar('%');
		else if (file->is_fifo)
			ft_putchar('|');
	}
	else if (env->p && file->is_dir)
		ft_putchar('/');
	ft_putchar('\n');
}
