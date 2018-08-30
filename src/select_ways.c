#include "../inc/lem_in.h"

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

static void save_way(t_map *pmap, struct s_stack **root, int *nodes, int i)
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

t_boolean check_ways(t_map *pmap, struct s_stack **st)
{
    struct s_stack *stack = NULL;
    int *nodes;
    t_edge edge;
    int i;

    *st = NULL;
    i = pmap->index_end;
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