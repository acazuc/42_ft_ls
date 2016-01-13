/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_perms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:27:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 12:04:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	load_first_letter(struct stat *info)
{
	if (S_ISLNK(info->st_mode))
		return ('l');
	else if (S_IFDIR & info->st_mode)
		return ('d');
	else if (S_IFBLK & info->st_mode)
		return ('b');
	else if (S_IFCHR & info->st_mode)
		return ('c');
	else if (S_IFIFO & info->st_mode)
		return ('p');
	else
		return ('-');
}

char		*load_file_perms(struct stat *info)
{
	char	*perms;

	if (!(perms = malloc(sizeof(*perms) * 12)))
		error_quit("Failed to malloc file perms");
	perms[0] = load_first_letter(info);
	perms[1] = info->st_mode & S_IRUSR ? 'r' : '-';
	perms[2] = info->st_mode & S_IWUSR ? 'w' : '-';
	if (info->st_mode & S_ISUID)
		perms[3] = 's';
	else
		perms[3] = info->st_mode & S_IXUSR ? 'x' : '-';
	perms[4] = info->st_mode & S_IRGRP ? 'r' : '-';
	perms[5] = info->st_mode & S_IWGRP ? 'w' : '-';
	if (info->st_mode & S_ISGID)
		perms[6] = 's';
	else
		perms[6] = info->st_mode & S_IXGRP ? 'x' : '-';
	perms[7] = info->st_mode & S_IROTH ? 'r' : '-';
	perms[8] = info->st_mode & S_IWOTH ? 'w' : '-';
	perms[9] = info->st_mode & S_IXOTH ? 'x' : '-';
	perms[10] = ' ';
	perms[11] = '\0';
	return (perms);
}
