#include "../inc/lem_in.h"
#include <stdio.h>

t_boolean add_room_to_matrix(t_map *pmap, char *r1, char *r2, t_vertex st)
{
    char **room;
    int i;
    int j;

    i = 0;
    j = 0;
    room = pmap->the_rooms;
    while (*room)
    {
        if (!ft_strcmp(*room++, r1))
            break ;
        i++;
    }
    room = pmap->the_rooms;
    while (*room)
    {
        if (!ft_strcmp(*room++, r2))
            break ;
        j++;
    }
    if (i == pmap->number_of_rooms || j == pmap->number_of_rooms)
        return FALSE;
    pmap->matrix[i][j] = st;
    pmap->matrix[j][i] = st;
    return TRUE;
}

void create_matrix(t_map *pmap)
{
    int i;
    int j;

    i = pmap->number_of_rooms;
    pmap->matrix = (int **)malloc(sizeof(int *) * (i));
    if (!pmap->matrix)
    {
        ft_putstr("malloc\n");//ERR
        exit(EXIT_FAILURE);
    }
    while (i-- > 0)
    {
        j = pmap->number_of_rooms;
        pmap->matrix[i] = (int *)malloc(sizeof(int) * (j));
        while(j-- > 0)
            pmap->matrix[i][j] = ORANGE;
    }
}