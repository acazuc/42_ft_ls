/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_add_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 14:39:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 13:39:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_file_perms(struct stat *info, int is_link)
{
	char	*perms;

	if (!(perms = malloc(sizeof(*perms) * 11)))
		error_quit("Failed to malloc file perms");
	if (is_link)
		perms[0] = 'l';
	else if (S_ISDIR(info->st_mode))
		perms[0] = 'd';
	else if (S_ISBLK(info->st_mode))
		perms[0] = 'b';
	else if (S_ISCHR(info->st_mode))
		perms[0] = 'c';
	else
		perms[0] = '-';
	perms[1] = info->st_mode & S_IRUSR ? 'r' : '-';
	perms[2] = info->st_mode & S_IWUSR ? 'w' : '-';
	perms[3] = info->st_mode & S_IXUSR ? 'x' : '-';
	perms[4] = info->st_mode & S_IRGRP ? 'r' : '-';
	perms[5] = info->st_mode & S_IWGRP ? 'w' : '-';
	perms[6] = info->st_mode & S_IXGRP ? 'x' : '-';
	perms[7] = info->st_mode & S_IROTH ? 'r' : '-';
	perms[8] = info->st_mode & S_IWOTH ? 'w' : '-';
	perms[9] = info->st_mode & S_IXOTH ? 'x' : '-';
	perms[10] = '\0';
	return (perms);
}

static void		load_file_symb(t_file *file, struct stat info, t_directory *dir
		, char *rpath)
{
	struct passwd	*pw;
	struct group	*gr;
	ssize_t			r;
	char			*linkname;

	if (!(linkname = malloc(info.st_size + 1)))
		error_quit("Failed to malloc linkname");
	r = readlink(rpath, linkname, info.st_size + 1);
	if (r < 0)
		error_quit("Bad link id, did it changed ?");
	linkname[info.st_size] = '\0';
	file->name = ft_strjoin_free1(file->name, " -> ");
	file->name = ft_strjoin_free3(file->name, linkname);
	file->is_dir = S_ISDIR(info.st_mode);
	pw = getpwuid(info.st_uid);
	gr = getgrgid(info.st_gid);
	file->perms = get_file_perms(&info, 1);
	file->links = ft_itoa(info.st_nlink);
	file->user = ft_strdup(pw->pw_name ? pw->pw_name : "");
	file->group = ft_strdup(gr->gr_name ? gr->gr_name : "");
	file->size = ft_itoa(info.st_size);
	file->date = ft_strsub(ctime(&info.st_mtime), 4, 12);
	file->timestamp = info.st_mtime;
	dir->total_links += info.st_blocks;
}

static int		load_file(t_env *env, t_file *file, struct dirent *ep
		, t_directory *dir)
{
	struct stat		linfo;
	struct stat		info;
	struct passwd	*pw;
	struct group	*gr;
	char			*loul;

	file->name = ft_strdup(ep->d_name);
	loul = ft_strjoin_free1(ft_strjoin(dir->path, "/"), ep->d_name);
	stat(loul, &info);
	file->is_dir = S_ISDIR(info.st_mode);
	if (env->l)
	{
		lstat(loul, &linfo);
		if (info.st_ino != linfo.st_ino)
		{
			load_file_symb(file, linfo, dir, loul);
			free(loul);
			return (0);
		}
		pw = getpwuid(info.st_uid);
		gr = getgrgid(info.st_gid);
		file->perms = get_file_perms(&info, 0);
		file->links = ft_itoa(info.st_nlink);
		file->user = ft_strdup(pw->pw_name ? pw->pw_name : "");
		file->group = ft_strdup(gr->gr_name ? gr->gr_name : "");
		file->size = ft_itoa(info.st_size);
		file->date = ft_strsub(ctime(&info.st_mtime), 4, 12);
		file->timestamp = info.st_mtime;
		dir->total_links += info.st_blocks;
	}
	file->timestamp = info.st_mtime;
	free(loul);
	return (S_ISDIR(info.st_mode));
}

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
	}
}

int				directory_add_file(t_env *env, t_directory *dir
		, struct dirent *ep)
{
	t_file_list		*list;
	t_file			*file;
	int				is_dir;

	is_dir = 0;
	if (!(file = malloc(sizeof(*file))))
		error_quit("Failed to malloc file");
	if (!(list = malloc(sizeof(*list))))
		error_quit("Failed to malloc list");
	list->file = file;
	list->next = NULL;
	is_dir = load_file(env, file, ep, dir);
	check_lengths(env, dir, file);
	add_file(env, dir, list);
	return (is_dir);
}
