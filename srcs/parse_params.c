/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 11:39:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 09:12:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		check(t_env *env, char c)
{
	if (c == 'l')
		env->l = 1;
	else if (c == 'R')
		env->r_caps = 1;
	else if (c == 'a')
		env->a = 1;
	else if (c == 'r')
		env->r = 1;
	else if (c == 't')
	{
		env->t = 1;
		env->s_caps = 0;
	}
	else if (c == 'u')
		env->u = 1;
	else if (c == 'U')
		env->u_caps = 1;
	else if (c == 'g')
	{
		env->l = 1;
		env->g = 1;
	}
	else if (c == 'o')
	{
		env->l = 1;
		env->o = 1;
	}
	else if (c == 'f')
	{
		env->a = 1;
		env->f = 1;
	}
	else if (c == 'S')
	{
		env->t = 0;
		env->s_caps = 1;
	}
	else if (c == 'i')
		env->i = 1;
	else if (c == 'n')
	{
		env->l = 1;
		env->n = 1;
	}
	else if (c == 'A')
		env->a_caps = 1;
	else if (c == 'f')
	{
		env->a = 1;
		env->f = 1;
	}
	else if (c == 'p')
		env->p = 1;
	else if (c == 'P')
		env->p_caps = 1;
	else if (c == '1')
		(void)c;
	else if (c == '-')
		(void)c;
	else
	{
		ft_putstr("ft_ls: invalid option -- '");
		ft_putchar(c);
		ft_putendl("'");
		exit(-1);
	}
}

int				parse_params(t_env *env, int agrumes, char **les_agruments)
{
	int		plus_plus;
	int		sous_lbus;

	sous_lbus = 1;
	while (sous_lbus < agrumes && les_agruments[sous_lbus][0] == '-' && les_agruments[sous_lbus][1] != '\0')
	{
		plus_plus = 0;
		while (les_agruments[sous_lbus][++plus_plus])
			check(env, les_agruments[sous_lbus][plus_plus]);
		++sous_lbus;
	}
	return (sous_lbus);
}
