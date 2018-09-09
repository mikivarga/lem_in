/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:06:20 by mvarga            #+#    #+#             */
/*   Updated: 2018/09/09 15:16:58 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static int			*create_arr(t_map *pmap, int data)
{
	int	*nodes;
	int	i;

	i = 0;
	nodes = (int *)malloc(sizeof(int) * pmap->number_of_rooms);
	if (!nodes)
		exit_func(pmap, "Unable to allocate memory!");
	while (i < pmap->number_of_rooms)
		nodes[i++] = data;
	return (nodes);
}

static void			save_way(t_map *pmap, t_stack *root, int *nodes, int i)
{
	t_queue	queue;
	t_edge	edge;
	int		node;

	q_initialize(&queue);
	q_push(pmap->index_start, &queue);
	while (!q_is_empty(&queue))
	{
		i = -1;
		q_pop(&node, &queue);
		nodes[node] = GRAY;
		while (++i < pmap->number_of_rooms)
		{
			if (pmap->matrix[node][i] == GREEN && nodes[i] == ORANGE)
			{
				q_push(i, &queue);
				nodes[i] = GREEN;
				edge.start = node;
				edge.end = i;
				s_push(root, edge);
				if (node == pmap->index_end)
					break ;
			}
		}
	}
}

static t_boolean	check_ways(t_map *pmap, t_stack *st)
{
	t_node	*stack;
	int		*nodes;
	t_edge	edge;
	int		i;

	i = pmap->index_end;
	s_initialize(&stack);
	nodes = create_arr(pmap, ORANGE);
	save_way(pmap, &stack, nodes, i);
	free(nodes);
	edge.start = i;
	s_push(st, edge);
	while (!is_empty(stack))
	{
		edge = s_peek(stack);
		s_pop(&stack);
		if (edge.end == i)
		{
			i = edge.start;
			s_push(st, edge);
			clear_room_in_matrix(pmap, i);
		}
	}
	return (i == pmap->index_end ? FALSE : TRUE);
}

static t_ants_info	save_index_room(int index)
{
	t_ants_info room;

	room.ant = 0;
	room.index = index;
	return (room);
}

void				save_ways(t_map *pmap, t_lst *ways)
{
	t_node	*stack;
	t_edge	e;
	int		i;

	i = 0;
	s_initialize(&stack);
	while (i < pmap->number_of_ants && check_ways(pmap, &stack))
	{
		l_initialize(&ways[i]);
		while (!is_empty(stack))
		{
			e = s_peek(stack);
			s_pop(&stack);
			l_add(save_index_room(e.start), &ways[i]);
		}
		pmap->number_of_ways++;
		i++;
	}
}
