/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:10:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 09:20:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	file_time(t_env *env, struct stat *info)
{
	if (env->u)
		return (info->st_atimespec.tv_sec);
	else if (env->u_caps)
		return (info->st_birthtimespec.tv_sec);
	return (info->st_mtimespec.tv_sec);
}
