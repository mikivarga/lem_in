#include "../inc/lem_in.h"
#include <stdio.h>

static void print_ant(int ant, char *room)
{
    ft_putchar('L');
    ft_putnbr(ant);
    ft_putchar('-');
    ft_putstr(room);
    ft_putchar(' ');
}

/*
while(TRUE)//!is_empty(*ways))
    {
        cnt_ways = 0;
        while (cnt_ways < pmap->number_of_ways)
        {
            if (!is_empty(ways[cnt_ways]))
            {
                l_show(&ways[cnt_ways], pmap->the_rooms, ant, print_ant);
                e = s_peek(ways[cnt_ways]);
                ft_putchar('\n');
                if (!(pmap->number_of_ants - ant))
                {
                    l_delete_node(e.start, &ways[cnt_ways]);
                    continue ;
                }
                ant++;
            }
            cnt_ways++;
        }
*/

void move(t_map *pmap, t_lst *ways)
{
    t_edge e;

    int ant = 1;
    int cnt_ways;
    
    cnt_ways = 0;
    /*while (cnt_ways < pmap->number_of_ways)
    {
        //e = s_peek(ways[cnt_ways]);
        //l_delete_node(e.start, &ways[cnt_ways++]);
        ways[cnt_ways] = ways[cnt_ways]->next;
        cnt_ways++;
    }*/
    while(!is_empty((*ways)->next)) //here need use all ways
    {
        l_show(&((*ways)->next), pmap->the_rooms, ant, print_ant);
        e = s_peek((*ways)->next);
        if (!(pmap->number_of_ants - ant))
        {
            l_delete_node(e.start, ways);
        }
        else
        {
            ant++;
        }
        ft_putchar('\n');
    }
}

void move_ants(t_map *pmap, t_lst *ways)
{
    int i;
    
    //i = 0;
    //while(i < pmap->number_of_ways)
    move(pmap, ways);
    i = 0;
    while (i < pmap->number_of_ways)
    {
        ft_putstr("IDIOT\n"); 
        l_delete(&ways[i++]);
    }
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
    move_ants(&map, ways);
    //free(all)
    return 0;
}