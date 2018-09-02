#include "../inc/lem_in.h"
#include <stdio.h>

void l_initialize(t_lst *plst)
{
    *plst = NULL;
}

t_boolean l_add(t_ants_info i, t_lst *plst)
{
    t_node *pnew;
    t_node *scan;

    scan = *plst;

    pnew = (t_node *)malloc(sizeof(t_node));
    if (pnew == NULL)
        return FALSE;
    pnew->info.room = i;
    pnew->next = NULL;
    if (scan == NULL)
    {
        *plst = pnew;
    }
    else
    {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }
    return TRUE;
}

/*
t_boolean l_add(int index, t_lst *plst)
{
    t_node *pnew;
    t_node *scan;

    scan = *plst;

    pnew = (t_node *)malloc(sizeof(t_node));
    if (pnew == NULL)
        return FALSE;
    pnew->info.index = index;
    pnew->next = NULL;
    if (scan == NULL)
    {
        *plst = pnew;
    }
    else
    {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }
    return TRUE;
}*/

t_boolean l_delete_node(int index, t_lst *plst)
{
    t_node *pnode;
    t_node *psave;

    pnode = *plst;
    psave = NULL;
    while (pnode != NULL)
    {
        if (pnode->info.index == index) {
            if (psave == NULL)
                *plst = pnode->next;
            else
                psave->next = pnode->next;
            free(pnode);
            return TRUE;
        }
        psave = pnode;
        pnode = pnode->next;
    }
    return FALSE;
}
/*
void l_show(t_lst *plst, char **room, int nmb_ant, int nmb_room, int index, void(*pfun)(int, char *))
{
    t_edge e;

    if ((*plst)->next != NULL && nmb_room)
    {
        l_show(&((*plst)->next), room, nmb_ant - index, nmb_room - 1, index, pfun);
            
    }
    else
    {
    e = s_peek(*plst);
    pfun(nmb_ant, room[e.start]);
    }
}*/



void l_show(t_lst *plst, char **room, int ant, int inc, void(*pfun)(int, char *))
{
    t_edge e;

    if ((ant - inc) > 0  && (*plst)->next != NULL)
    {
        l_show(&((*plst)->next), room, ant - inc, inc, pfun);
    }
    e = s_peek(*plst);
    pfun(ant, room[e.start]);
}

    /*if (ant - inc == 0)
    {
        e = s_peek(*plst);
        //ft_putchar('A');
        pfun(ant, room[e.start]);
    }
    else*/ 
    /*}
    else
    {
        e = s_peek(*plst);
        //ft_putchar('C');
        pfun(ant, room[e.start]);
    }*/
    /*
    else
    {
         e = s_peek(*plst);
         ft_putchar('G');
        pfun(ant, room[e.start]);
    }*/
    /*if (!(ant / inc))
    {
        e = s_peek(*plst);
        pfun(ant, room[e.start]);
    }
    else if (!(ant % inc))
    {
        e = s_peek(*plst);
        pfun(ant, room[e.start]);
    }*/ 
    /*else if ((cnt - inc + 1) > 0)
    {
        e = s_peek(*plst);
        pfun(cnt - (inc), room[e.start]);
    }*/


void l_delete(t_lst *plst)
{
    t_node *psave;

    while (*plst != NULL)
    {
        ft_putstr(" MIKI\n");
        psave = (*plst)->next;
        free(*plst);
        *plst = psave;
    }
}