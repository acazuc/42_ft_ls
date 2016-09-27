/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 08:35:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/01 16:15:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_LIST_H
# define FILE_LIST_H

struct s_file;

struct					s_file_list
{
	struct s_file		*file;
	struct s_file_list	*next;
};

typedef struct s_file_list	t_file_list;

#endif
