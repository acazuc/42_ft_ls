/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:50:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 17:10:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*load_file_date(struct stat *info)
{
	char		*brut_time;
	char		*result;
	time_t		current_time;
	long		delta_time;

	brut_time = ctime(&(info->st_mtime));
	current_time = time(NULL);
	delta_time = current_time - info->st_mtime;
	if (delta_time > 60 * 60 * 24 * 30 * 6 || delta_time < -60 * 60 * 24 * 30 * 6)
	{
		if (!(result = ft_strsub(brut_time, 4, 7))
				|| !(result = ft_strjoin_free1(result, " "))
			|| !(result = ft_strjoin_free1(result, ft_strsub(brut_time, 20, 4))))
			error_quit("Failed to malloc time");
	}
	else
		result = ft_strsub(brut_time, 4, 12);
	return (result);
}
