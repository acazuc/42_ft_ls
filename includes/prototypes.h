/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 11:48:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 10:11:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "directory.h"
# include "env.h"

int				parse_params(t_env *env, int ac, char **av);
void			parse_sources(t_env *env, int ac, char **av, int c);
void			print_directory(t_env *env, char *dir, int is_recur);
void			error_quit(char *error);
int				directory_add_file(t_env *env, t_directory *dir
		, struct dirent *ep);
t_directory		*load_directory(t_env *env, char *path);
void			add_directory(t_directory *directory, struct dirent *ep);
void			add_file(t_env *env, t_directory *dir, t_file_list *list);
void			free_dir_files();
void			free_dir(t_directory *dir);
void			free_file(t_env *env, struct s_file *file);

#endif
