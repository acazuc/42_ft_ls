/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:47:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 18:16:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	insert(t_env *env, t_file_list *list, t_file_list *curr)
{
	t_file			*lf;
	t_file			*cf;

	lf = list->file;
	cf = curr->file;
	if (env->t)
	{
		if (env->r)
			return (cf->timestamp == lf->timestamp ? ft_strcmp(cf->name, lf->name) > 0 : cf->timestamp < lf->timestamp);
		else
			return (cf->timestamp == lf->timestamp ? ft_strcmp(cf->name, lf->name) < 0 : cf->timestamp > lf->timestamp);
	}
	else
	{
		if (env->r)
			return (ft_strcmp(cf->name, lf->name) > 0);
		else
			return (ft_strcmp(cf->name, lf->name) < 0);
	}
}

static void	swap(t_file_list *list, t_file_list *lst, t_file_list *prv
		, t_directory *dir)
{
	list->next = lst;
	if (prv)
		prv->next = list;
	else
		dir->files = list;
}

void		add_file(t_env *env, t_directory *dir, t_file_list *list)
{
	t_file_list		*lst;
	t_file_list		*prv;

	if (!(dir->files))
	{
		dir->files = list;
		return ;
	}
	lst = dir->files;
	prv = NULL;
	while (lst)
	{
		if (insert(env, lst, list))
		{
			swap(list, lst, prv, dir);
			return ;
		}
		if (!lst->next)
		{
			lst->next = list;
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}
