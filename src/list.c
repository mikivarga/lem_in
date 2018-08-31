#include "../inc/lem_in.h"

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

void l_delete(t_lst *plst)
{
    t_node *psave;

    while (*plst != NULL)
    {
        psave = (*plst)->next;
        free(*plst);
        *plst = psave;
    }
}