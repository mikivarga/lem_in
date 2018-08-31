#include "../inc/lem_in.h"
#include <stdio.h>




int main(void)
{
    t_map map;
    t_node *stack[MAX_WAYS];

    map.the_rooms = NULL;
    map.matrix = NULL;
    map.number_of_ants = 0;
    map.number_of_rooms = 0;
    map.number_of_ways = 0;
    map.index_start = 0;
    map.index_end = 0;
    read_map(&map);
    save_ways(&map, stack);
    //free(all)
    return 0;
}