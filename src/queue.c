#include "../inc/lem_in.h"

void q_initialize(t_queue * pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

t_boolean q_is_empty(const t_queue *pq)
{
    return pq->items == 0;
}

int q_item_count(const t_queue * pq)
{
    return pq->items;
}

t_boolean q_push(int index, t_queue * pq)
{
    t_node *pnew;

    if (!(pnew = (t_node *)malloc(sizeof(t_node))))
    {
        return FALSE;
    }
    pnew->info.index = index;
    pnew->next = NULL;
    if (pq->items == 0)
        pq->front = pnew;
    else
        pq->rear->next = pnew;
    pq->rear = pnew;
    pq->items++;
    return TRUE;
}

t_boolean q_pop(int *index, t_queue * pq)
{
    t_node *pt;

    if (pq->items == 0)
        return FALSE;
    *index = pq->front->info.index;
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;
    return TRUE;
}