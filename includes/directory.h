/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 14:30:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/01 17:02:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORY_H
# define DIRECTORY_H

# include "file_list.h"

typedef struct	s_directory
{
	char		*path;
	int			links_len;
	int			user_len;
	int			group_len;
	int			size_len;
	int			total_links;
	t_file_list	*files;
}				t_directory;

#endif
