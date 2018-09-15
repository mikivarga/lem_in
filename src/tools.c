/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 14:16:20 by mvarga            #+#    #+#             */
/*   Updated: 2018/09/09 14:19:02 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	s_initialize(t_stack *pst)
{
	*pst = NULL;
}

void	print_ant(t_map *pmap, int ant, char *room)
{
	if (pmap->cmd_colour)
		ft_putstr_fd("\033[1;32m", 2);
	ft_putchar('L');
	ft_putnbr(ant);
	if (pmap->cmd_colour)
		ft_putstr_fd("\033[0m", 2);
	ft_putchar('-');
	if (pmap->cmd_colour)
		ft_putstr_fd("\033[1;35m", 2);
	ft_putstr(room);
	if (pmap->cmd_colour)
		ft_putstr_fd("\033[0m", 2);
	ft_putchar(' ');
}

void	show_ways(t_map *pmap, t_lst *ways)
{
	t_node	*way;
	int		i;

	i = 0;
	while (i < pmap->number_of_ways)
	{
		way = ways[i];
		if (pmap->cmd_colour)
			ft_putstr_fd("\033[1;31m", 2);
		ft_putstr("WAY ");
		ft_putnbr(i + 1);
		ft_putchar('\n');
		if (pmap->cmd_colour)
			ft_putstr_fd("\033[0m", 2);
		while (way)
		{
			ft_putstr(pmap->the_rooms[way->info.room.index]);
			if (!is_empty(way->next))
				ft_putstr("->");
			way = way->next;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void	cmd(t_map *pmap, char *data, int *start, int *end)
{
	if (!ft_strcmp(CMD_START, data))
	{
		pmap->index_start = pmap->number_of_rooms;
		(*start)++;
	}
	else if (!ft_strcmp(CMD_END, data))
	{
		pmap->index_end = pmap->number_of_rooms;
		(*end)++;
	}
	else if (!ft_strcmp(CMD_COLOUR, data))
		pmap->cmd_colour = TRUE;
	else if (!ft_strcmp(CMD_PATH, data))
		pmap->cmd_path = TRUE;
}
