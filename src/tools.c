#include "../inc/lem_in.h"

void print_ant(int ant, char *room)
{
    ft_putchar('L');
    ft_putnbr(ant);
    ft_putchar('-');
    ft_putstr(room);
    ft_putchar(' ');
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