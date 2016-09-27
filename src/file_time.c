/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:10:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 15:20:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	file_time(t_env *env, struct stat *info)
{
	if (env->u)
		return (info->st_atimespec.tv_sec);
	else if (env->u_caps)
		return (info->st_birthtimespec.tv_sec);
	else if (env->c)
		return (info->st_ctimespec.tv_sec);
	return (info->st_mtimespec.tv_sec);
}
