/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdr_la_recursive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:28:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/01 16:34:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		strlen_recursive(char *str)
{
	return (*str ? 1 + strlen_recursive(str + 1) : 0);
}

int		strlen_iterative(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


salut\0

s    1 + (ligne_dessous) = 1 + 4 = 5
a    1 + (ligne_dessous) = 1 + 3 = 4
l    1 + (ligne_dessous) = 1 + 2 = 3
u    1 + (ligne_dessous) = 1 + 1 = 2
t    1 + (ligne_dessous) = 1 + 0 = 1
\0   0
