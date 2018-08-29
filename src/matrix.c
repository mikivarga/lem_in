#include "../inc/lem_in.h"
#include <stdio.h>

void clear_room_in_matrix(t_map *pmap, int index)
{
    int i;

    i = 0;
    if (index != pmap->index_start)
    {
        while (i < pmap->number_of_rooms)
            pmap->matrix[index][i++] = ORANGE;
    }
    else
    {
        pmap->matrix[index][pmap->index_end] = ORANGE;
    }
}

t_boolean add_room_to_matrix(t_map *pmap, char *r1, char *r2)
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
    pmap->matrix[i][j] = GREEN;
    pmap->matrix[j][i] = GREEN;
    return TRUE;
}

void create_matrix(t_map *pmap)
{
    int i;
    int j;

    i = pmap->number_of_rooms;
    pmap->matrix = (char **)malloc(sizeof(char *) * (i));
    if (!pmap->matrix)
    {
        ft_putstr("malloc\n");//ERR
        exit(EXIT_FAILURE);
    }
    while (i-- > 0)
    {
        j = pmap->number_of_rooms;
        pmap->matrix[i] = (char *)malloc(sizeof(char) * (j));
        while(j-- > 0)
            pmap->matrix[i][j] = ORANGE;
    }
}