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
/*
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
}*/

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
*/


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
/*
void move(t_map *pmap, t_lst *ways, int nmb_ant, int cnt_ways)
{
    //t_edge e;
    if (cnt_ways < pmap->number_of_ways)
    {
        if (!is_empty((ways[cnt_ways])->next))
        {
            l_show(&((ways[cnt_ways])->next), pmap->the_rooms,  nmb_ant, cnt_ways + 1, print_ant);
            //l_show(&((ways[cnt_ways])->next), pmap->the_rooms, nmb_ant, ways[cnt_ways]->info.index, cnt_ways + 1, print_ant);
            if ((pmap->number_of_ants < nmb_ant))
            {
                
                //e = s_peek((ways[cnt_ways])->next);
                //l_delete_node(e.start, &ways[cnt_ways]);
            }

            //ways[cnt_ways]->info.index++;
                //ways[cnt_ways]->info.e.start++;
            ft_putstr("cnt_ways =");
            ft_putnbr(cnt_ways);
            ft_putchar('\n');

        }
        move(pmap, ways, nmb_ant + 1, cnt_ways + 1);
    }
}*/

//printf("way = %d, consist %d room %s\n", cnt_ways, ways[cnt_ways]->info.index, pmap->the_rooms[ways[cnt_ways]->info.index]);
/*
t_boolean l_last(t_lst *plst, int cnt)
{
    t_node *tmp;

    tmp = *plst;
    while (cnt-- >= 0)
    {
        if(tmp == NULL)
        {
            return TRUE;
        }
        tmp = tmp->next;
    }
    return FALSE;
}

void move(t_map *pmap, t_lst *ways, int nmb_ant, int cnt_ways)
{
    t_edge e;
    if (cnt_ways < pmap->number_of_ways)
    {
        if (is_empty(ways[cnt_ways]->next))
        {
            return ;
        }
        else if (l_last(&ways[cnt_ways]->next, ways[cnt_ways]->info.index))
        {
            print_ant(nmb_ant - 1, pmap->the_rooms[ways[cnt_ways]->info.index]);
            //move(pmap, ways, nmb_ant, cnt_ways + 2);
            ways[cnt_ways]->info.index = 0;
            move(pmap, ways, nmb_ant, cnt_ways + 2);
            //exit(0);
        }
        else if ((nmb_ant) < pmap->number_of_ants)
        {
            l_show(&((ways[cnt_ways])->next), pmap->the_rooms, nmb_ant, cnt_ways + 1, print_ant);
            move(pmap, ways, nmb_ant + 1, cnt_ways + 1);//?
            ways[cnt_ways]->info.index++;
            //sleep(1);
        }
        else
        {
            e = s_peek((ways[cnt_ways])->next);
            l_delete_node(e.start, &ways[cnt_ways]);
        }
    }
}
*/
/* work if only one way;
void move(t_map *pmap, t_lst *ways, int nmb_ant)
{
    int cnt_ways;

    cnt_ways = 0;
    while (cnt_ways < pmap->number_of_ways)
    {
        ft_putstr("ANT = ");
        ft_putnbr(nmb_ant);
        ft_putstr(":\t");
        l_show(&((ways[cnt_ways])->next), pmap->the_rooms,  nmb_ant, cnt_ways + 1, print_ant);
        ft_putstr("\tcnt_ways = ");
        ft_putnbr(cnt_ways);
        ft_putstr(" len =");
        ft_putnbr(ways[cnt_ways]->info.room.index);
        ft_putchar('\n');
        cnt_ways++;
    }
}

void move_ants(t_map *pmap, t_lst *ways)
{
    int nmb_ant;
    int i;
    
    //pmap->number_of_ways = 1;
    printf("cnt_ways %d\n", pmap->number_of_ways);
    nmb_ant = 0;
    while (nmb_ant < pmap->number_of_ants)
    {
        move(pmap, ways, ++nmb_ant);
        ft_putchar('\n');
        sleep(1);
    }
    //printf(last room)
    i = 0;
    while (i < pmap->number_of_ways)
    {
        ft_putstr("!IDIOT\n"); 
        l_delete(&ways[i++]);
    }
}*/


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
    t_lst *w;
    //
    int cnt;

    cnt = 0;
    w = ways;

    while(cnt < pmap->number_of_ways)
    {
        /*ft_putstr(" MYWAY =");
        t_edge e= s_peek(w[cnt]->next);
        ft_putstr(pmap->the_rooms[e.start]);
        ft_putchar('\n');*/

        /*ft_putstr(" WAY =");
        ft_putstr(pmap->the_rooms[w[cnt]->next->info.room.index]);
        ft_putchar('\n');*/
        sleep(1);
        if (!w[cnt]->next->info.room.ant)
        {
            print_ant(nmb_ant, pmap->the_rooms[w[cnt]->next->info.room.index]);
            if (!is_empty((w[cnt]->next->next)))
            {
                w[cnt]->next->info.room.ant = nmb_ant;
                return FALSE;
            }
            return TRUE;
        }
        else
        {
            //t_lst *w2;
            t_lst *tmp;

            tmp = ways;
            int i = 0;
            while (i < pmap->number_of_ways)
            {
                if (!tmp[i]->next->info.room.ant)
                    break;
                i++;
            }
            if (!is_empty(tmp[i]->next))// && (w[cnt]->info.room.index - tmp[i]->info.room.index) < pmap->number_of_ants)
            {
                tmp[i]->next->info.room.ant = nmb_ant;
                print_ant(nmb_ant, pmap->the_rooms[w[cnt]->next->info.room.index]);
                //if (temp2->length - temp->length < ants)
				//	return (find_route_3(ant, temp2));
            }
            return FALSE;

        }
        cnt++;
    }
    return FALSE;
}

t_boolean ants_go_go_go(t_map *pmap, t_lst *ways, int nmb_ant)
{
    t_node *w;
    int cnt;

    cnt = 0;
    while(cnt < pmap->number_of_ways)
    {
        w = ways[cnt++]->next;//?->next
        while(!is_empty(w->next))
        {
            //printf("\n!%d!\n", w->info.room.ant);
            //sleep(1);
            if (w->info.room.ant == nmb_ant && !w->next->info.room.ant)
            {
                w->info.room.ant = 0;
                print_ant(nmb_ant, pmap->the_rooms[w->next->info.room.index]);
                if (!is_empty((w->next)))
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
            if (ants_array[i] && ants_go_go_go(pmap, ways, i + 1))
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
    move_ants(&map, ways);

    
    //move_ants(&map, ways);
    //free(all)
    return 0;
}