/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 08:30:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 13:25:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "file_list.h"

struct					s_file
{
	char				*name;
	char				*perms;
	char				*links;
	char				*user;
	char				*group;
	char				*size;
	char				*date;
	int					is_dir;
	long				timestamp;
};

typedef struct s_file	t_file;

#endif
