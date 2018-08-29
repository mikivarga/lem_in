#include "../inc/lem_in.h"
#include <stdio.h>


static char *create_veretx(t_map *pmap)
{
    char *nodes;
    int i;

    i = 0;
    nodes = (char *)malloc(sizeof(char) * pmap->number_of_rooms);
    if (!nodes)
    {
        ft_putendl("Unable to allocate memory!");
        exit(EXIT_FAILURE);
    }
    while (i < pmap->number_of_rooms)
        nodes[i++] = ORANGE;
    return nodes;
}

static void save_way(t_map *pmap, struct s_stack **root, char *nodes, int i)
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

t_boolean check_ways(t_map *pmap)
{
    struct s_stack *stack = NULL;
    char *nodes;
    t_edge edge;
    int i;

    i = pmap->index_end;
    nodes = create_veretx(pmap);
    save_way(pmap, &stack, nodes, i);
    free(nodes);
    printf("!%s ", pmap->the_rooms[i]);
    while (!s_is_empty(stack))
    {
        edge = s_peek(stack);
        s_pop(&stack);
        if (edge.end == i)
        {
            i = edge.start;
            printf(" <- %s", pmap->the_rooms[i]);
            clear_room_in_matrix(pmap, i);
        }
    }
    printf("\n");
    return (i == pmap->index_end ? FALSE : TRUE);
}