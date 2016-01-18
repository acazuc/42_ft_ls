/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 08:23:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 11:54:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		init_env(t_env *env)
{
	env->a = 0;
	env->a_caps = 0;
	env->c = 0;
	env->f = 0;
	env->f_caps = 0;
	env->g = 0;
	env->i = 0;
	env->l = 0;
	env->n = 0;
	env->o = 0;
	env->p = 0;
	env->p_caps = 0;
	env->r = 0;
	env->r_caps = 0;
	env->s_caps = 0;
	env->t = 0;
	env->t_caps = 0;
	env->u = 0;
	env->u_caps = 0;
	env->printed_file = 0;
	env->files = NULL;
	env->sources = NULL;
}

int				main(int ac, char **av)
{
	t_env			env;
	int				mdr;

	init_env(&env);
	mdr = parse_params(&env, ac, av);
	parse_sources(&env, ac, av, mdr);
	return (0);
}
