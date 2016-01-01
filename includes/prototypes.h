/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 11:48:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/01 17:21:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "directory.h"
# include "env.h"

void			parse_params(t_env *env, int ac, char **av);
void			parse_sources(t_env *env, int ac, char **av);
void			print_directory(t_env *env, char *dir, int is_recur);
void			error_quit(char *error);
void			directory_add_file(t_env *env, t_directory *dir
		, struct dirent *ep);
t_directory		*load_directory(t_env *env, char *path);
void			sort_alpha_asc(t_directory *dir);
void			sort_date_asc(t_directory *dir);
void			sort_reverse(t_directory *dir);

#endif
