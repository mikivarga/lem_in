/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:19:21 by mvarga            #+#    #+#             */
/*   Updated: 2018/09/09 14:21:47 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		exit_func(t_map *pmap, const char *err_msg)
{
	char	**tmp;
	int		i;

	if (pmap->the_rooms)
	{
		tmp = pmap->the_rooms;
		while (*tmp)
			free(*tmp++);
		free(pmap->the_rooms);
	}
	if (pmap->matrix)
	{
		i = 0;
		while (i < pmap->number_of_rooms)
			free(pmap->matrix[i++]);
		free(pmap->matrix);
	}
	if (err_msg)
	{
		ft_putstr_fd(err_msg, 2);
		exit(EXIT_FAILURE);
	}
}

void		free_ways(t_map *pmap, t_lst *ways)
{
	t_node	*way;
	int		i;

	i = 0;
	while (i < pmap->number_of_ways)
	{
		way = ways[i++];
		l_delete(&way);
	}
	ft_putchar('\n');
}
