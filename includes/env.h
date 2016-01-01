/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 09:38:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/01 13:44:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "file_list.h"

typedef struct	s_env
{
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
	t_file_list	*files;
}				t_env;

#endif
