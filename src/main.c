#include "../inc/lem_in.h"
#include <stdio.h>

void check_way(t_map *pmap)
{
    t_queue queue;
    struct s_stack *root = NULL;
    t_edge e;
    //int *nodes;
    //int i;
   
    int j;
        int req = pmap->index_end;
        printf("!!!!!!!!!!!! req = %d\n", req);
    q_initialize(&queue);
    /*nodes = (int *)malloc(sizeof(int) * pmap->number_of_rooms);
    if (!nodes)
    {
        ft_putendl("Unable to allocate memory!");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < pmap->number_of_rooms)
        nodes[i++] = 0;
        */
    int nodes[7]; // вершины графа
  for (int i = 0; i < 7; i++)
    nodes[i] = 0; // и
    q_push(pmap->index_start, &queue);
    while (!q_is_empty(&queue))
    {
        int node;
        q_pop(&node, &queue);
        nodes[node] = 2;
        j = 0;
        while (j < pmap->number_of_rooms)
        {
            if (pmap->matrix[node][j] == 1 && nodes[j] == 0)
            {
                printf("push\n");
                q_push(j, &queue);
                nodes[j] = 1;
                e.start = node;
                e.end = j;
                s_push(&root, e);
                if (node == req)
                    break;
            }
            j++;
        }
        printf("NODE   %d\n", node + 1);
    }
    printf("WAY to %s ", pmap->the_rooms[req]);
    while (!s_is_empty(root))
    {
        e = s_peek(root);
        s_pop(&root);
        if (e.end == req) 
        {
            req = e.start;
            printf(" <- %s",  pmap->the_rooms[req]);
        }
    }
    printf("\n");
}

int main(void)
{
    t_map map;

    map.the_rooms = NULL;
    map.matrix = NULL;
    map.number_of_ants = 0;
    map.number_of_rooms = 0;
    map.index_start = 0;
    map.index_end = 0;
    read_map(&map);
    
    int i, j;
    i = 0;
    while (i < map.number_of_rooms)
    {
        j = 0;
        while(j < map.number_of_rooms)
        {
            ft_putnbr(map.matrix[i][j]);
            j++;
        }
        i++;
        ft_putchar('\n');
    }
    ft_putstr("\n\n");
    check_way(&map);
    return 0;
}