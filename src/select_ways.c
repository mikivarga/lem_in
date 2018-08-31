#include "../inc/lem_in.h"
#include <stdio.h>

static int *create_arr(t_map *pmap, int data)
{
    int *nodes;
    int i;

    i = 0;
    nodes = (int *)malloc(sizeof(int) * pmap->number_of_rooms);
    if (!nodes)
    {
        ft_putendl("Unable to allocate memory!");
        exit(EXIT_FAILURE);
    }
    while (i < pmap->number_of_rooms)
        nodes[i++] = data;
    return nodes;
}

static void save_way(t_map *pmap, t_stack *root, int *nodes, int i)
{
    t_queue queue;
    t_edge edge;
    int node;

    q_initialize(&queue);
    q_push(pmap->index_start, &queue);
    while (!q_is_empty(&queue))
    {
        i = 0;
        q_pop(&node, &queue);     
        nodes[node] = GRAY;
        while (i < pmap->number_of_rooms)
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
            i++; 
        }
    }
}

static t_boolean check_ways(t_map *pmap, t_stack *st)
{
    t_node *stack;
    int *nodes;
    t_edge edge;
    int i;
   
    i = pmap->index_end;
    s_initialize(&stack);
    nodes = create_arr(pmap, ORANGE);
    save_way(pmap, &stack, nodes, i);
    free(nodes);
    edge.start = i;
    s_push(st, edge);
    while (!s_is_empty(stack))
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

static void print_ant(int ant, char *room)
{
    ft_putchar('L');
    ft_putnbr(ant + 1);
    ft_putchar('-');
    ft_putstr(room);
    ft_putchar(' ');
}

void move_ants(t_map *pmap, t_stack *ways, int ants)
{
    t_edge e;

    while(!s_is_empty(*ways))
    {
        e = s_peek(*ways);
        s_pop(ways);
        if (e.start == pmap->index_end)
            continue ;
        print_ant(ants, pmap->the_rooms[e.start]);
    }
    print_ant(ants, pmap->the_rooms[e.start]);
    ft_putchar('\n');
}

void save_ways(t_map *pmap, t_stack *stack)
{
    int ants;
    int i;

    i = 0;
    ants = 0;
    while (i <= pmap->number_of_ants && check_ways(pmap, &stack[i++]))
    {
        pmap->number_of_ways++;
        i++;
    }
    i = 0;
    while (i < pmap->number_of_ways)
    {
        move_ants(pmap, &stack[i], ants++);
        i++;
    }
}