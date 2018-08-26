#include "../inc/lem_in.h"

int room_index(t_map *pmap, char *room)
{
    int i;

    i = 0;
    while(pmap->the_rooms[i])
    {
        if (!ft_strcmp(pmap->the_rooms[i], room))
            return i;
    }
    return -1;
}