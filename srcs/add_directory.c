/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_directory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 08:31:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 09:01:56 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_directory(t_directory *directory, struct dirent *ep)
{
	t_directory_list	*list;
	t_directory_list	*lst;

	if (!ft_strcmp(ep->d_name, ".") || !ft_strcmp(ep->d_name, ".."))
		return ;
	if (!(list = malloc(sizeof(*list))))
		error_quit("Failed to malloc list");
	list->path = ft_strjoin(ft_strjoin(directory->path, "/"), ep->d_name);
	list->next = NULL;
	if (!(directory->directories))
		directory->directories = list;
	else
	{
		lst = directory->directories;
		while (lst->next)
			lst = lst->next;
		lst->next = list;
	}
}
