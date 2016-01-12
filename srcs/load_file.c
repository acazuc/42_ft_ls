/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:27:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 19:00:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		set_infos_l(t_env *env, t_file *file, struct stat *info)
{
	struct passwd	*pw;
	struct group	*gr;

	if (env->n)
	{
		file->user = ft_itoa(info->st_uid);
		file->group = ft_itoa(info->st_gid);
	}
	else
	{
		pw = getpwuid(info->st_uid);
		gr = getgrgid(info->st_gid);
		file->user = ft_strdup(pw->pw_name ? pw->pw_name : "");
		file->group = ft_strdup(gr->gr_name ? gr->gr_name : "");
	}
	file->links = ft_itoa(info->st_nlink);
	file->size = ft_itoa(info->st_size);
	file->sort_size = info->st_size;
	file->date = load_file_date(env, info);
}

static int		load_file_symb(t_env *env, t_file *file, struct stat *info
		, char *rpath)
{
	ssize_t			r;
	char			*linkname;

	if (!(linkname = malloc(info->st_size + 1)))
		error_quit("Failed to malloc linkname");
	r = readlink(rpath, linkname, info->st_size + 1);
	if (r < 0)
		error_quit("Bad link id, did it changed ?");
	linkname[info->st_size] = '\0';
	file->is_dir = S_ISDIR(info->st_mode);
	if (env->l)
	{
		file->perms = load_file_perms(info, 1);
		file->name = ft_strjoin_free1(file->name, " -> ");
		file->name = ft_strjoin_free3(file->name, linkname);
		set_infos_l(env, file, info);
	}
	file->inode = info->st_ino;
	file->sort_date = file_time(env, info);
	return (info->st_blocks);
}

void		load_file(t_env *env, t_file *file, struct dirent *ep
		, t_directory *dir)
{
	struct stat		linfo;
	struct stat		info;
	char			*loul;

	file->name = ft_strdup(ep->d_name);
	loul = ft_strjoin_free1(ft_strjoin(dir->path, "/"), ep->d_name);
	stat(loul, &info);
	file->is_dir = S_ISDIR(info.st_mode);
	lstat(loul, &linfo);
	if (info.st_ino != linfo.st_ino)
	{
		dir->total_links += load_file_symb(env, file, &linfo, loul);
		free(loul);
		return ;
	}
	if (env->l)
	{
		set_infos_l(env, file, &info);
		file->perms = load_file_perms(&info, 0);
		dir->total_links += info.st_blocks;
	}
	file->inode = info.st_ino;
	file->sort_date = file_time(env, &info);
	free(loul);
}
