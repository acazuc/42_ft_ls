/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sources.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:55:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 10:15:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_sources(t_env *env, int ac, char **av, int c)
{
	int		printed;
	int		i;

	printed = 0;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-' && av[i][0] != '\0')
		{
			if (av[i][ft_strlen(av[i]) - 1] == '/')
				av[i][ft_strlen(av[i]) - 1] = '\0';
			print_directory(env, av[i], printed || ac - c > 2);
			printed = 1;
		}
		i++;
	}
	if (!printed)
		print_directory(env, ".", 0);
}
