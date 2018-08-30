#include "../inc/lem_in.h"
#include <stdio.h>
/*
static void save_ways(t_map *pmap, int *arr_way)//needed check if the romm is new
{
    int **pp;
    int **old_ways;

    pp = (int **)malloc(sizeof(int *) *(pmap->number_of_ways + 2));
    if (!pp)
    {
        ft_putstr("malloc\n");//ERR
        exit(EXIT_FAILURE);
    }
    old_ways = pmap->ways;
    while (pmap->number_of_ways && *old_ways)
    {
        *pp++ = *old_ways++;
    }
    *pp++ = arr_way;
    *pp = 0;
    if (pmap->number_of_ways)
        free(old_ways - (pmap->number_of_ways));
    pmap->ways = pp - (pmap->number_of_ways + 1);
}*/

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

t_boolean check_ways(t_map *pmap)
{
    struct s_stack *stack = NULL;
    int *nodes;
    //int *ways;
    t_edge edge;
    int i;

    struct s_stack *st = NULL;
    //int j;
    i = pmap->index_end;
    nodes = create_arr(pmap, ORANGE);
//ways = create_arr(pmap, (i = pmap->index_end));
    save_way(pmap, &stack, nodes, i);
    free(nodes);
    //j = pmap->number_of_rooms;
    //ways[0] = i;
    edge.start = i;
    s_push(&st, edge);
    printf("!%s ", pmap->the_rooms[i]);//
    while (!s_is_empty(stack))
    {
        edge = s_peek(stack);
        s_pop(&stack);
        if (edge.end == i)
        {
            i = edge.start;
            s_push(&st, edge);
            //ways[--j] = i;
            printf(" <- %s", pmap->the_rooms[i]); //
            //save_arr_vays;
            clear_room_in_matrix(pmap, i);
        }
    }
    printf("\n");

    t_edge e;
    while(!s_is_empty(st))
    {
        e = s_peek(st);
        s_pop(&st);
        printf("%s > ", pmap->the_rooms[e.start]);
    }
    /*int z = 0;
    while (z < pmap->number_of_rooms)
    {
        printf("%s > ", pmap->the_rooms[ways[z++]]);
     }*/
    printf("\n"); //
    //save_ways
    return (i == pmap->index_end ? FALSE : TRUE);
}