#include "../inc/lem_in.h"
#include <stdio.h>

int main(void)
{
    t_map map;

    map.the_rooms = NULL;
    map.matrix = NULL;
    map.ways = NULL;
    map.number_of_ants = 0;
    map.number_of_rooms = 0;
    map.number_of_ways = 0;
    map.index_start = 0;
    map.index_end = 0;
    read_map(&map);
    
    /*
    int i, j;
    i = 0;
    while (i < map.number_of_rooms)
    {
        j = 0;
        while(j < map.number_of_rooms)
        {
            printf("%d", map.matrix[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
    */

    while (check_ways(&map))
        ;

        //free all;
    return 0;
}