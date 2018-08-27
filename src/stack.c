#include "../inc/lem_in.h"

struct s_stack *s_new_node(t_edge data)
{
    struct s_stack *node;
    
    node = (struct s_stack *)malloc(sizeof(struct s_stack));
    if (!node)
    {
        ft_putendl("Unable to allocate memory!");
        exit(EXIT_FAILURE);
    }
    node->e = data;
    node->next = NULL;
    return node;
}

int s_is_empty(struct s_stack *root)
{
    return !root;
}

void s_push(struct s_stack **root, t_edge data)
{
    struct s_stack *node;
    
    node = s_new_node(data);
    node->next = *root;
    *root = node;
    ft_putstr("pushed to stack\n");
}

int s_pop(struct s_stack **root)
{
    struct s_stack *temp;

    if (s_is_empty(*root))
        return FALSE;
    temp = *root;
    *root = (*root)->next;
    free(temp);
    return TRUE;
}

t_edge s_peek(struct s_stack *root)
{
    return root->e;
}