/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 11:48:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 18:22:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <unistd.h>
# include "directory.h"
# include "file.h"
# include "env.h"

int				parse_params(t_env *env, int ac, char **av);
void			parse_sources(t_env *env, int ac, char **av, int c);
void			print_directory(t_env *env, char *dir, int is_recur);
void			print_file(t_env *env, t_file *file, t_directory *dir);
void			error_quit(char *error);
void			directory_add_file(t_env *env, t_directory *dir
		, struct dirent *ep);
t_directory		*load_directory(t_env *env, char *path);
void			add_file(t_env *env, t_directory *dir, t_file_list *list);
void			free_file(t_env *env, struct s_file *file);
void			load_file(t_env *env, t_file *file, struct dirent *ep, t_directory *dir);
char			*load_file_perms(struct stat *info, int is_link);
char			*load_file_date(t_env *env, struct stat *info);
time_t			file_time(t_env *env, struct stat *info);

#endif
