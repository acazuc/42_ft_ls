/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:10:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 18:24:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	file_time(t_env *env, struct stat *info)
{ 
	if (env->u)
		return (info->st_atime);
	return (info->st_mtime);
}
