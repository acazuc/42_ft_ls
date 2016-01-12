/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_perms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:27:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 16:28:28 by acazuc           ###   ########.fr       */
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

