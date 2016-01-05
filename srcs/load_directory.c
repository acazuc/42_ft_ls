/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 14:32:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/05 15:59:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	directory_init(t_directory *dir, char *path)
{
	dir->files = NULL;
	dir->path = path;
	dir->total_links = 0;
	dir->links_len = 0;
	dir->user_len = 0;
	dir->group_len = 0;
	dir->size_len = 0;
	dir->directories = NULL;
}

/*static void	do_sorts(t_env *env, t_directory *directory)
{
	if (env->t)
		sort_date_asc(directory);
	else
		sort_alpha_asc(directory);
	if (env->r)
		sort_reverse(directory);
}*/

t_directory	*load_directory(t_env *env, char *path)
{
	t_directory		*directory;
	DIR				*dir;
	struct dirent	*ep;

	if ((dir = opendir(path)))
	{
		if (!(directory = malloc(sizeof(*directory))))
			error_quit("Failed to malloc dir");
		directory_init(directory, path);
		while ((ep = readdir(dir)))
		{
			if (env->a || ep->d_name[0] != '.')
				if (directory_add_file(env, directory, ep) && env->R)
					add_directory(directory, ep);
		}
		closedir(dir);
		//do_sorts(env, directory);
	}
	else
	{
		perror(ft_strjoin("ft_ls: ", path));
		return (NULL);
	}
	return (directory);
}
