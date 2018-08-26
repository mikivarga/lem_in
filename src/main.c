#include "../inc/lem_in.h"

int main(void)
{
    t_map pmap;

    pmap.number_of_ants = 0;
    pmap.number_of_rooms = 0;
    pmap.index_start = 0;
    pmap.index_end = 0;
    parse_map(&pmap);
    int i, j;
    i = pmap.number_of_rooms;
    while (i-- > 0)
    {
        j = pmap.number_of_rooms;
        while(j-- > 0)
        {
            ft_putnbr(pmap.matrix[i][j]);
        }
        ft_putchar('\n');
    }
    return 0;
}

/* 
int main()
{
    struct StackNode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
 
    return 0;
}*/