/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sources.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:55:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 11:31:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_dir(t_env *env, t_directory *dir)
{
	t_file_list		*lst;
	t_file_list		*prv;

	lst = dir->files;
	while (lst)
	{
		print_file(env, lst->file, dir);
		free_file(env, lst->file);
		prv = lst;
		lst = lst->next;
		free(prv);
	}
}

static void		print_sources(t_env *env, int recur)
{
	t_source		*lst;

	lst = env->sources;
	while (lst)
	{
		print_directory(env, lst->path, recur);
		lst = lst->next;
	}
}

static void		push_source(t_env *env, char *path)
{
	t_source		*lst;
	t_source		*new;

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

static int		add_source(t_env *env, char *path, t_directory *dir)
{
	struct stat		info;

	if (stat(path, &info) == -1)
	{
		ft_putstr("ls: ");
		perror(path);
		return (0);;
	}
	if (S_ISDIR(info.st_mode))
	{
		push_source(env, path);
		return (0);
	}
	directory_add_file(env, dir, path);
	return (1);
}

void			parse_sources(t_env *env, int ac, char **av, int c)
{
	t_directory		dir;
	char			*dir_path;
	int				printed_file;
	int				printed;
	int				i;

	if (!(dir_path = ft_memalloc(2)))
		error_quit("Failed to malloc dir path");
	dir_path[0] = '.';
	directory_init(&dir, dir_path);
	printed = 0;
	printed_file = 0;
	i = c;
	while (i < ac)
	{
		if (av[i][0] != '\0')
		{
			if (av[i][ft_strlen(av[i]) - 1] == '/' && ft_strlen(av[i]) > 1)
				av[i][ft_strlen(av[i]) - 1] = '\0';
			printed_file += add_source(env, av[i], &dir);
			printed = 1;
		}
		i++;
	}
	print_dir(env, &dir);
	if (!printed)
		print_directory(env, ".", 0);
	else
		print_sources(env, printed_file || ac - c >= 2);
}
