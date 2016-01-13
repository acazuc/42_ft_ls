/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 08:23:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 10:53:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_env			env;
	int				mdr;

	env.a = 0;
	env.a_caps = 0;
	env.f = 0;
	env.g = 0;
	env.i = 0;
	env.l = 0;
	env.n = 0;
	env.o = 0;
	env.p = 0;
	env.p_caps = 0;
	env.r = 0;
	env.r_caps = 0;
	env.s_caps = 0;
	env.t = 0;
	env.u = 0;
	env.u_caps = 0;
	env.printed_file = 0;
	env.files = NULL;
	env.sources = NULL;
	mdr = parse_params(&env, ac, av);
	parse_sources(&env, ac, av, mdr);
	return (0);
}
