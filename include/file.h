/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 08:30:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 16:27:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <time.h>
# include "file_list.h"

struct					s_file
{
	char				*name;
	char				*lnk_name;
	char				*perms;
	char				*links;
	char				*user;
	char				*group;
	char				*size;
	char				*date;
	int					is_dir;
	int					is_exe;
	int					is_lnk;
	int					is_sock;
	int					is_whout;
	int					is_fifo;
	ino_t				inode;
	time_t				sort_date;
	off_t				sort_size;
};

typedef struct s_file	t_file;

#endif
