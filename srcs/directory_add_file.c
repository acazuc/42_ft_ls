/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_add_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 14:39:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 16:39:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		check_lengths(t_env *env, t_directory *dir, t_file *file)
{
	int			len;

	if (env->l)
	{
		if ((len = ft_strlen(file->links)) > dir->links_len)
			dir->links_len = len;
		if ((len = ft_strlen(file->user)) > dir->user_len)
			dir->user_len = len;
		if ((len = ft_strlen(file->group)) > dir->group_len)
			dir->group_len = len;
		if ((len = ft_strlen(file->size)) > dir->size_len)
			dir->size_len = len;
		if ((len = ft_strlen(file->date)) > dir->date_len)
			dir->date_len = len;
	}
}

void			directory_add_file(t_env *env, t_directory *dir
		, struct dirent *ep)
{
	t_file_list		*list;
	t_file			*file;

	if (!(file = malloc(sizeof(*file))))
		error_quit("Failed to malloc file");
	if (!(list = malloc(sizeof(*list))))
		error_quit("Failed to malloc list");
	list->file = file;
	list->next = NULL;
	load_file(env, file, ep, dir);
	check_lengths(env, dir, file);
	add_file(env, dir, list);
}
