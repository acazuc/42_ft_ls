/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 11:39:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/01 16:21:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_params(t_env *env, int agrumes, char **les_agruments)
{
	int		plus_plus;
	int		sous_lbus;

	sous_lbus = 1;
	while (sous_lbus < agrumes)
	{
		if (les_agruments[sous_lbus][0] == '-')
		{
			plus_plus = 0;
			while (les_agruments[sous_lbus][++plus_plus])
			{
				if (les_agruments[sous_lbus][plus_plus] == 'l')
					env->l = 1;
				else if (les_agruments[sous_lbus][plus_plus] == 'R')
					env->R = 1;
				else if (les_agruments[sous_lbus][plus_plus] == 'a')
					env->a = 1;
				else if (les_agruments[sous_lbus][plus_plus] == 'r')
					env->r = 1;
				else if (les_agruments[sous_lbus][plus_plus] == 't')
					env->t = 1;
			}
		}
		++sous_lbus;
	}
}
