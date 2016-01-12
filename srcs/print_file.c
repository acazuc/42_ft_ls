/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:16:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 18:39:16 by acazuc           ###   ########.fr       */
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
	if (env->l)
	{
		ft_putstr(file->perms);
		putspaces(2 + dir->links_len - ft_strlen(file->links));
		ft_putstr(file->links);
		if (!env->g)
		{
			putspaces(1 + dir->user_len - ft_strlen(file->user));
			ft_putstr(file->user);
		}
		if (!env->g_caps)
		{
			putspaces(2 + dir->group_len - ft_strlen(file->group));
			ft_putstr(file->group);
		}
		putspaces(2 + dir->size_len - ft_strlen(file->size));
		ft_putstr(file->size);
		putspaces(1 + dir->date_len - ft_strlen(file->date));
		ft_putstr(file->date);
		ft_putchar(' ');
		ft_putstr(file->name);
	}
	else
	{
		ft_putstr(file->name);
	}
	ft_putchar('\n');
}
