/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:47:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/05 16:27:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	insert(t_env *env, t_file_list *list, t_file_list *curr)
{
	t_file_list		*ln;
	t_file			*lf;
	t_file			*cf;
	t_file			*nf;

	ln = list->next;
	lf = list->file;
	cf = curr->file;
	nf = list->next ? list->next->file : NULL;
	if (env->t)
	{
		if (env->r)
			return (cf->timestamp > lf->timestamp && (!ln || nf->timestamp <= cf->timestamp));
		else
			return (cf->timestamp < lf->timestamp && (!ln || nf->timestamp >= cf->timestamp));
	}
	else
	{
		if (env->r)
			return (ft_strcmp(cf->name, lf->name) <= 0 && (!ln || ft_strcmp(cf->name, nf->name) >= 0));
		else
			return (ft_strcmp(cf->name, lf->name) >= 0 && (!ln || ft_strcmp(cf->name, nf->name) <= 0));
	}
}

void	add_file(t_env *env, t_directory *dir, t_file_list *list)
{
	t_file_list		*lst;

	if (!(dir->files))
	{
		dir->files = list;
		return ;
	}
	lst = dir->files;
	while (lst)
	{
		if (insert(env, lst, list))
		{
			ft_putstr("Put ");
			ft_putstr(list->file->name);
			ft_putstr(" after ");
			ft_putendl(lst->file->name);
			list->next = lst->next;
			lst->next = list;
			return ;
		}
		if (!lst->next)
		{
			ft_putstr("Put ");
			ft_putstr(list->file->name);
			ft_putendl(" at the end of list");
			lst->next = list;
			return ;
		}
		lst = lst->next;
	}
}
