#include "../inc/lem_in.h"

void exit_func(t_map *pmap, const char *err_msg)
{
    int i;

    if (err_msg)
        ft_putstr_fd(err_msg, 2);
    exit(EXIT_FAILURE);
}
