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

t_boolean ways_is_empty(t_lst *ways, t_map *pmap)
{
    int cnt_ways;

    cnt_ways = 0;
    //ways[cnt_ways]->info.index = 0;
    while (cnt_ways < pmap->number_of_ways)
    {
        //ways[cnt_ways]->info.index = 0;
        if (!is_empty((ways[cnt_ways])->next))
        {
            ////??
            return FALSE;
        }
        cnt_ways++;
    }
    return TRUE;
}


void move(t_map *pmap, t_lst *ways)
{
    t_edge e;
    int cnt_ways;
    //pmap->number_of_ways = 1;
    int ant = 1;

    cnt_ways = 0;
    while (!ways_is_empty(ways, pmap))
    {
        cnt_ways = 0;
        while (cnt_ways < pmap->number_of_ways)
        {
            if (!is_empty((ways[cnt_ways])->next))
            {
                //ways[cnt_ways]->info.index;
                printf("\ncnt %d, room %d\n", cnt_ways, ways[cnt_ways]->info.index);
                l_show(&((ways[cnt_ways])->next), pmap->the_rooms, ways[cnt_ways]->info.e.start, ways[cnt_ways]->info.e.end, cnt_ways + 1, print_ant);
                if ((pmap->number_of_ants - ant) <= 0)
                {
                    pmap->number_of_ants--;
                    e = s_peek((ways[cnt_ways])->next);
                    l_delete_node(e.start, &ways[cnt_ways]);
                }
                else
                {
                    ant++;
                }
                ways[cnt_ways]->info.e.end++;
                ways[cnt_ways]->info.e.start++;
            }
            
            cnt_ways++;            
        }
        ft_putchar('\n');
    }
}



/*
void move(t_map *pmap, t_lst *ways)
{
    t_edge e;
    int cnt_ways;
    //pmap->number_of_ways = 1;
    int ant = 1;

    cnt_ways = 0;
    while (!ways_is_empty(ways, pmap))
    {
        cnt_ways = 0;
        //ways[cnt_ways]->info.index = 0;
        while (cnt_ways < pmap->number_of_ways)
        {
            
            if (!is_empty((ways[cnt_ways])->next))
            {
                ways[cnt_ways]->info.index = ant;
                printf("\ncnt %d, ant %d\n", cnt_ways, ways[cnt_ways]->info.index);
                l_show(&((ways[cnt_ways])->next), pmap->the_rooms,  ways[cnt_ways]->info.index, cnt_ways + 1, print_ant);
                //printf("cnt = %d ant = %d\n", cnt_ways, ant);
                if ((pmap->number_of_ants - ant) <= 0)
                {
                    pmap->number_of_ants--;
                    e = s_peek((ways[cnt_ways])->next);
                    l_delete_node(e.start, &ways[cnt_ways]);
                }
                else
                {
                    ant++;
                }
            }
            cnt_ways++;            
        }
        ft_putchar('\n');
    }
}*/

void move_ants(t_map *pmap, t_lst *ways)
{
    int i;
    
    ft_putchar('\n');
    move(pmap, ways);
    i = 0;
    while (i < pmap->number_of_ways)
    {
        ft_putstr("!IDIOT\n"); 
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