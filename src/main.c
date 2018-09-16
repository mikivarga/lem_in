/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 13:27:28 by mvarga            #+#    #+#             */
/*   Updated: 2018/09/16 18:18:56 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static t_boolean	find_way(t_map *pmap, t_lst *ways, int nmb_ant, int cnt)
{
	t_node	*w;
	t_node	*tmp;
	int		i;

	while (++cnt < pmap->number_of_ways)
		if (!(w = ways[cnt]->next)->info.room.ant)
		{
			print_ant(pmap, nmb_ant, pmap->the_rooms[w->info.room.index]);
			return (w->next && (w->info.room.ant = nmb_ant) ? FALSE : TRUE);
		}
		else
		{
			i = cnt;
			while (i < pmap->number_of_ways && (tmp = ways[i]))
				if (++i && !tmp->next->info.room.ant)
				{
					tmp->next->info.room.ant = nmb_ant;
					print_ant
(pmap, nmb_ant, pmap->the_rooms[tmp->next->info.room.index]);
					return (FALSE);
				}
			return (FALSE);
		}
	return (FALSE);
}

static t_boolean	ants_go_go_go(t_map *pmap, t_lst *ways, int nmb_ant)
{
	t_node	*w;
	int		cnt;

	cnt = 0;
	while (cnt < pmap->number_of_ways)
	{
		w = ways[cnt++];
		while (w)
		{
			if (w->info.room.ant == nmb_ant && !w->next->info.room.ant)
			{
				w->info.room.ant = 0;
				print_ant
(pmap, nmb_ant, pmap->the_rooms[w->next->info.room.index]);
				if (w->next->next)
				{
					w->next->info.room.ant = nmb_ant;
					return (FALSE);
				}
				return (TRUE);
			}
			w = w->next;
		}
	}
	return (find_way(pmap, ways, nmb_ant, -1));
}

void				move_ants(t_map *pmap, t_lst *ways)
{
	char	*ant_waiting;
	int		i;
	int		j;

	if (!(ant_waiting = ft_strnew(pmap->number_of_ants)))
	{
		free_ways(pmap, ways);
		exit_func(pmap, "Unable to allocate memory!");
	}
	ft_memset(ant_waiting, 'a', pmap->number_of_ants);
	i = -1;
	while (++i < pmap->number_of_ants)
	{
		if (ant_waiting[i])
		{
			j = -1;
			while (++j < pmap->number_of_ants)
				if (ant_waiting[j] && ants_go_go_go(pmap, ways, j + 1))
					ant_waiting[j] = 0;
			i = -1;
			ft_putchar('\n');
		}
	}
	free(ant_waiting);
}

void				move(t_map *pmap, t_boolean flag)
{
	t_node	*ways[MAX_WAYS];

	save_ways(pmap, ways);
	show_map(pmap);
	if (!pmap->number_of_ways)
		exit_func(pmap, ERR_MSG);
	ft_putchar('\n');
	if (pmap->cmd_path)
		show_ways(pmap, ways);
	move_ants(pmap, ways);
	free_ways(pmap, ways);
	exit_func(pmap, NULL);
	if (flag)
		exit(EXIT_SUCCESS);
}

int					main(void)
{
	t_map	map;

	map.map = NULL;
	map.the_rooms = NULL;
	map.matrix = NULL;
	map.number_of_ants = 0;
	map.number_of_rooms = 0;
	map.number_of_ways = 0;
	map.cnt_lines = 0;
	map.index_start = -1;
	map.index_end = -1;
	map.cmd_colour = FALSE;
	map.cmd_path = FALSE;
	read_map(&map);
	move(&map, FALSE);
	return (0);
}
