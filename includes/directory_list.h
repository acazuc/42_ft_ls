/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 08:20:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 08:55:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORY_LIST_H
# define DIRECTORY_LIST_H

typedef struct					s_directory_list
{
	char						*path;
	struct s_directory_list		*next;
}								t_directory_list;

#endif
