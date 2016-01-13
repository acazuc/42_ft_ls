/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_perms_ext.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:10:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 16:28:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	load_file_perms_ext(char *path)
{
	ssize_t		attr;
	char		*buf;

	buf = ft_memalloc(500);
	attr = listxattr(path, buf, 500, 0);
	//printf("listxattr: %zd, buff: %s\n", attr, buf);
	if (attr == 21)
		return ('@');
	return (' ');
}
