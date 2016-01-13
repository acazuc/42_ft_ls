/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:54:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 12:49:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

typedef struct			s_source
{
	char				*path;
	char				*display_path;
	int					sort_date;
	struct s_source		*next;
}						t_source;

#endif
