/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:27:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 17:06:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		set_infos_l(t_file *file, struct stat *info)
{
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(info->st_uid);
	gr = getgrgid(info->st_gid);
	file->links = ft_itoa(info->st_nlink);
	file->user = ft_strdup(pw->pw_name ? pw->pw_name : "");
	file->group = ft_strdup(gr->gr_name ? gr->gr_name : "");
	file->size = ft_itoa(info->st_size);
	file->timestamp = info->st_atime;
	file->date = load_file_date(info);
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
		set_infos_l(file, info);
	}
	file->timestamp = info->st_atime;
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
		set_infos_l(file, &info);
		file->perms = load_file_perms(&info, 0);
		dir->total_links += info.st_blocks;
	}
	file->timestamp = info.st_mtime;
	free(loul);
}
