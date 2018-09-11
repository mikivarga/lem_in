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

static void print_err(t_map *pmap, const char *err_msg)
{
	if (pmap->cmd_colour)
		ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(err_msg, 2);
	if (pmap->cmd_colour)
		ft_putstr_fd("\033[0m", 2);
}	

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
		print_err(pmap, err_msg);	
		exit(EXIT_FAILURE);
	}
}

void		free_ways(t_map *pmap, t_lst *ways)
{
	int		i;

	i = 0;
	while (i < pmap->number_of_ways)
		l_delete(&ways[i++]);
	ft_putchar('\n');
}
