/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 08:23:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 18:31:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_env			env;
	int				mdr;

	env.sources = NULL;
	env.files = NULL;
	env.l = 0;
	env.r_caps = 0;
	env.a = 0;
	env.r = 0;
	env.t = 0;
	env.u = 0;
	env.u_caps = 0;
	mdr = parse_params(&env, ac, av);
	parse_sources(&env, ac, av, mdr);
	return (0);
}
