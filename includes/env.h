/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 09:38:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 15:32:53 by acazuc           ###   ########.fr       */
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
	int					c;
	int					f;
	int					f_caps;
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
	int					t_caps;
	int					u;
	int					u_caps;
	int					printed_file;
	t_file_list			*files;
	t_source			*sources;
}						t_env;

#endif
