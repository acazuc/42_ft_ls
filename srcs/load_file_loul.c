/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_loul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:25:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 12:29:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*load_file_loul(char *name, t_directory *dir)
{
	char	*tmp;

	if (name[0] == '/')
		return (ft_strdup(name));
	if (!(tmp = ft_strjoin(dir->path, "/")))
		error_quit("Failed to malloc string");
	if (!(tmp = ft_strjoin_free1(tmp, name)))
		error_quit("Failed to malloc string");
	return (tmp);
}
