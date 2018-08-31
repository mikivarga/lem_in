#include "../inc/lem_in.h"
#include <stdio.h>

void l_initialize(t_lst *plst)
{
    *plst = NULL;
}

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
}

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

void l_show(t_lst *plst, char **room, int cnt, void(*pfun)(int, char *))
{
    t_edge e;

    if (cnt - 1  && (*plst)->next != NULL)
        l_show(&((*plst)->next), room, cnt - 1, pfun);
    e = s_peek(*plst);
    pfun(cnt, room[e.start]);
}

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