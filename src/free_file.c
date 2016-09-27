/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:38:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 16:27:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_file(t_env *env, struct s_file *file)
{
	if (file)
	{
		if (env->l)
		{
			free(file->perms);
			free(file->links);
			free(file->user);
			free(file->group);
			free(file->size);
			free(file->date);
		}
		free(file->lnk_name);
		free(file->name);
		free(file);
	}
}
