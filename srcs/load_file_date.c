/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:50:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 10:50:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*load_file_date(t_env *env, struct stat *info)
{
	char		*brut_time;
	char		*result;
	time_t		current_time;
	time_t		ftime;
	long		delta_time;

	ftime = file_time(env, info);
	brut_time = ctime(&ftime);
	current_time = time(NULL);
	delta_time = current_time - info->st_mtime;
	if (delta_time > 60 * 60 * 24 * 30 * 6 || delta_time < -60 * 60 * 24 * 30 * 6)
	{
		if (!(result = ft_strsub(brut_time, 4, 7)))
			error_quit("Failed to malloc time");
		if (!(result = ft_strjoin_free1(result, " ")))
			error_quit("Failed to malloc time");
		if (brut_time[ft_strlen(brut_time) - 6] != ' ')
		{
			if (!(result = ft_strjoin_free3(result, ft_strsub(brut_time, ft_strlen(brut_time) - 6, 5))))
				error_quit("Failed to malloc time");
		}
		else
		{
			if (!(result = ft_strjoin_free3(result, ft_strsub(brut_time, 16, 4))))
				error_quit("Failed to malloc time");
		}
	}
	else
		result = ft_strsub(brut_time, 4, 12);
	return (result);
}
