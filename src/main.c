#include "../inc/lem_in.h"


int main(void)
{
    t_map pmap;

    parse_map(&pmap);
    ft_putendl(pmap.farm_map);//show map
    return 0;
}