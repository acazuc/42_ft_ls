/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_perms_ext.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:10:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 16:41:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	load_file_perms_ext(char *path)
{
	ssize_t		attr;
	char		*buf;

	if (!(buf = ft_memalloc(1)))
		error_quit("Failed to malloc");
	attr = listxattr(path, buf, 1, 0);
	free(buf);
	if (errno == ERANGE || attr > 0)
		return ('@');
	return (' ');
}
