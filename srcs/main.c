/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 08:23:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 10:10:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_env			env;
	int				mdr;

	mdr = parse_params(&env, ac, av);
	parse_sources(&env, ac, av, mdr);
	return (0);
}
