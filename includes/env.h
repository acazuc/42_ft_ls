/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 09:38:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 19:40:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "file_list.h"
# include "source.h"

typedef struct			s_env
{
	int					a;
	int					a_caps;
	int					f;
	int					g;
	int					i;
	int					l;
	int					n;
	int					o;
	int					p;
	int					p_caps;
	int					r;
	int					r_caps;
	int					s_caps;
	int					t;
	int					u;
	int					u_caps;
	t_file_list			*files;
	t_source			*sources;
}						t_env;

#endif
