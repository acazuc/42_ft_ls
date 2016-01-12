/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:16:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 19:39:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		putspaces(int number)
{
	while (--number >= 0)
		ft_putchar(' ');
}

void	print_file(t_env *env, t_file *file, t_directory *dir)
{
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
		if (!env->g)
		{
			putspaces(1 + dir->user_len - ft_strlen(file->user));
			ft_putstr(file->user);
		}
		if (!env->o)
		{
			putspaces(1 + dir->group_len - ft_strlen(file->group));
			ft_putstr(file->group);
		}
		putspaces(1 + dir->size_len - ft_strlen(file->size));
		ft_putstr(file->size);
		putspaces(1 + dir->date_len - ft_strlen(file->date));
		ft_putstr(file->date);
		ft_putchar(' ');
	}
	ft_putstr(file->name);
	if (env->p && file->is_dir)
		ft_putchar('/');
	ft_putchar('\n');
}
