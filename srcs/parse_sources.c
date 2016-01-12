/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sources.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:55:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 16:26:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_sources(t_env *env, int recur)
{
	t_source	*lst;

	lst = env->sources;
	while (lst)
	{
		print_directory(env, lst->path, recur);
		lst = lst->next;
	}
}

static void		push_source(t_env *env, char *path)
{
	t_source	*lst;
	t_source	*new;

	if (!(new = malloc(sizeof(*new))))
		error_quit("Failed");
	new->path = path;
	new->next = NULL;
	lst = env->sources;
	if (!lst)
		env->sources = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

static void		add_source(t_env *env, char *path)
{
	struct stat		info;
	t_file			*file;

	if (stat(path, &info) == -1)
	{
		ft_putstr("ft_ls: ");
		perror(path);
		return ;
	}
	if (S_ISDIR(info.st_mode))
		push_source(env, path);
	else
	{
		file = load_file(path);
		print_file(env, file, );
	}
}

void	parse_sources(t_env *env, int ac, char **av, int c)
{
	int		printed;
	int		i;

	printed = 0;
	i = c;
	while (i < ac)
	{
		if (av[i][0] != '\0')
		{
			if (av[i][ft_strlen(av[i]) - 1] == '/' && ft_strlen(av[i]) > 1)
				av[i][ft_strlen(av[i]) - 1] = '\0';
			add_source(env, av[i]);
			printed = 1;
		}
		i++;
	}
	if (!printed)
		print_directory(env, ".", 0);
	else
		print_sources(env, ac - c > 2);
}
