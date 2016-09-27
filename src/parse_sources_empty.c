/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sources_empty.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:06:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 12:08:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_sources_empty(char **av, int c)
{
	int		i;

	i = c;
	while (av[i])
	{
		if (!av[i][0])
		{
			ft_putendl_fd("ls: fts_open: No such file or directory", 2);
			exit(-1);
		}
		i++;
	}
}
