#include "../inc/lem_in.h"
#include <stdio.h>

void print_ant(int ant, char *room)
{
    ft_putchar('L');
    ft_putnbr(ant);
    ft_putchar('-');
    ft_putstr(room);
    ft_putchar(' ');
}

t_boolean ant_waits(int all_ants, int *ants_arr)
{
    int i;

    i = 0;
    while (i < all_ants)
    {
        if (ants_arr[i])
            return TRUE;
        i++;
    }
    return FALSE;
}

t_boolean find_way(t_map *pmap, t_lst *ways, int nmb_ant)
{
    t_node *w;
    t_node *tmp;
    int cnt;
    int i;

    cnt = -1;
    while(++cnt < pmap->number_of_ways)
        if (!(w = ways[cnt]->next)->info.room.ant)
        {
            print_ant(nmb_ant, pmap->the_rooms[w->info.room.index]);//2
            return (w && (w->info.room.ant = nmb_ant)) ? FALSE : TRUE;
        }
        else
        {
            i = cnt;
            while ((tmp = ways[i++]))
                if (!tmp->next->info.room.ant && (tmp->next->info.room.ant = nmb_ant))
                {
                    print_ant(nmb_ant, pmap->the_rooms[tmp->next->info.room.index]);//3
                    return FALSE;
                }
            return FALSE;
        }
    return FALSE;
}

void show_ways(t_map *pmap, t_lst *ways)
{
    t_node *way;
    int i;

    i = 0;
    while (i < pmap->number_of_ways)
    {
        way = ways[i];
        ft_putchar('#');
        ft_putnbr(i + 1);
        ft_putchar('\n');
        while (way)
        {
            ft_putstr(pmap->the_rooms[way->info.room.index]);
            if (!is_empty(way->next))
                ft_putstr("->");
            way = way->next;
        }
        ft_putchar('\n');
        i++;
    }
    ft_putchar('\n');
}

t_boolean ants_go_go_go(t_map *pmap, t_lst *ways, int nmb_ant)
{
    t_node *w;
    int cnt;

    cnt = 0;
    while(cnt < pmap->number_of_ways)
    {
        w = ways[cnt++]->next;
        while(w)
        {
            if (w->info.room.ant == nmb_ant && !w->next->info.room.ant)
            {
                w->info.room.ant = 0;
                print_ant(nmb_ant, pmap->the_rooms[w->next->info.room.index]);
                if (w->next->next && !w->next->next->next)
                {
                    w->next->info.room.ant = nmb_ant;
                    return FALSE;
                }
                return TRUE;
            }
            w = w->next;
        }
    }
    return find_way(pmap, ways, nmb_ant);
}

void move_ants(t_map *pmap, t_lst *ways)
{
    int *ants_array;
    int i;

    if (!(ants_array = (int *)malloc(sizeof(int) * (pmap->number_of_ants + 1))))
        exit(EXIT_FAILURE);
    i = 0;
    while (i < pmap->number_of_ants)
        ants_array[i++] = 1;
    ants_array[i] = 0;
    while (ant_waits(pmap->number_of_ants, ants_array))
    {
        i = 0;
        while (i < pmap->number_of_ants)
        {
            if (ants_array[i])
                if(ants_go_go_go(pmap, ways, i + 1))
                    ants_array[i] = 0;
            i++;
        }
        ft_putchar('\n');
    }
    free(ants_array);
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
    ft_putchar('\n');
    show_ways(&map, ways);
    move_ants(&map, ways);
    //free(all)
    return 0;
}