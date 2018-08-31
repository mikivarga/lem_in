#include "../inc/lem_in.h"
#include <stdio.h>

static void print_ant(int ant, char *room)
{
    ft_putchar('L');
    ft_putnbr(ant + 1);
    ft_putchar('-');
    ft_putstr(room);
    ft_putchar(' ');
}

void move_ants(t_map *pmap, t_lst *ways)
{
    t_edge e;

    while(!is_empty(*ways))
    {
        e = s_peek(*ways);
        l_delete_node(e.start, ways);
        if (e.start == pmap->index_end)
            continue ;
        print_ant(0, pmap->the_rooms[e.start]);
    }
    print_ant(0, pmap->the_rooms[e.start]);
    ft_putchar('\n');
}


int main(void)
{
    t_map map;
    t_node *ways[MAX_WAYS];

    map.the_rooms = NULL;
    map.matrix = NULL;
    map.number_of_ants = 0;
    map.number_of_rooms = 0;
    map.number_of_ways = 0;
    map.index_start = 0;
    map.index_end = 0;
    read_map(&map);
    save_ways(&map, ways);
    int i = 0;
    while(i < map.number_of_ways)
        move_ants(&map, &ways[i++]);
    //free(all)
    return 0;
}