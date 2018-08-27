#include "../inc/lem_in.h"
#include <stdio.h>

void check_way(t_map *pmap)
{
    if (TRUE)
    {
        int i, j;
    i = 0;
    while (i < pmap->number_of_rooms)
    {
        j = 0;
        while(j < pmap->number_of_rooms)
        {
            ft_putnbr(pmap->matrix[i][j]);
            j++;
        }
        i++;
        ft_putchar('\n');
    }
    }


    t_queue queue;
    //struct s_stack *root = NULL;
    //t_edge e;
    //int *nodes;
    //int i;
   
    int j;

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
    q_push(0, &queue);
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
                q_push(j, &queue);
                nodes[j] = 1;
                //e.start = node;
                //e.start = j;
                //s_push(&root, e);
                /*if (node == pmap->index_end)
                    break;*/
            }
            j++;
        }
        printf("NODE   %d\n", node + 1);
    }
}

int main(void)
{
    t_map map;

    map.number_of_ants = 0;
    map.number_of_rooms = 0;
    map.index_start = 0;
    map.index_end = 0;
    parse_map(&map);
    
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

/* 
int main()
{
    struct StackNode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
 
    return 0;
}*/