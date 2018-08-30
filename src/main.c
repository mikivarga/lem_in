#include "../inc/lem_in.h"

static void print_ant(int ant, char *room)
{
    ft_putchar('L');
    ft_putnbr(ant + 1);
    ft_putchar('-');
    ft_putstr(room);
    ft_putchar(' ');
}

static void move_ants(t_map *pmap, t_stack **ways, int ants)
{
    t_edge e;

    while(!s_is_empty(*ways))
    {
        e = s_peek(*ways);
        if (e.start == pmap->index_end)
        {
            s_pop(ways);//if thera ants don't do pop
            continue ;
        }
        print_ant(ants, pmap->the_rooms[e.start]);
        
       // if (pmap->number_of_ants == ants)
        {
            s_pop(ways);
            ft_putchar('\n');
        }
        //exit(0);
    }
    print_ant(ants, pmap->the_rooms[e.start]);
    ft_putchar('\n');
}
/*
static void save_ways(t_map *pmap, int *arr_way)
{
    int **pp;
    int **old_ways;

    pp = (int **)malloc(sizeof(int *) *(pmap->number_of_ways + 2));
    if (!pp)
    {
        ft_putstr("malloc\n");//ERR
        exit(EXIT_FAILURE);
    }
    old_ways = pmap->ways;
    while (pmap->number_of_ways && *old_ways)
    {
        *pp++ = *old_ways++;
    }
    *pp++ = arr_way;
    *pp = 0;
    if (pmap->number_of_ways)
        free(old_ways - (pmap->number_of_ways));
    pmap->ways = pp - (pmap->number_of_ways + 1);
}
*/
static void show_move_ants(t_map *pmap)
{
    struct s_stack *stack[MAX_WAYS];
    int ants;
    int i;

    i = 0;
    ants = 0;
    while (check_ways(pmap, &stack[i++]))
        pmap->number_of_ways++;
    i = 0;
    while (i < pmap->number_of_ways)
    {
        move_ants(pmap, &stack[i], ants++);
        i++;
    }
}

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
    show_move_ants(&map);
    ft_putchar('\n');
    //free(all)
    return 0;
}