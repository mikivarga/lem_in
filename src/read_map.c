#include "../inc/lem_in.h"

static t_boolean is_integer(char *str)
{
    char *pstr;
    ssize_t len;

    len = 0;
    pstr = str;
    if ((len = ft_strlen(str)) > MAX_LEN_INT)
        return FALSE;
    if (len == MAX_LEN_INT && ft_strcmp(str, MAX_INTEGER))
        return FALSE;
    if (*pstr == '+')
        pstr++;
    while (ft_isdigit(*pstr++))
        ;
    while (SPACE(*pstr))
        pstr++;
    if (*pstr)
        return FALSE;
    return TRUE;
}

static t_boolean links(t_map *pmap, char *str)
{
    (void)pmap;
    (void)str;
    return FALSE;
}

static t_boolean rooms(t_map *pmap, char *str)
{
    if (UNSUPORTED_ROOM(str[0]))
    {
        free(pmap->the_rooms);
        ft_putstr("UNSUPORTED_ROOM\n");//ERR
        exit(EXIT_FAILURE);
    }
    ++pmap->number_of_rooms;

    return FALSE;
}

static t_boolean ants(t_map *pmap, char *str)
{
    if (!is_integer(str)) {
        ft_putstr("is_integer\n");//ERR
        exit (EXIT_FAILURE);
    }
    pmap->number_of_ants = ft_atoi(str);
    if (pmap->number_of_ants <= 0)
    {
        ft_putstr("pmap->ants <= 0\n");//ERR
        exit(EXIT_FAILURE);
    }
    return TRUE;
}

void parse_map(t_map *pmap)
{
    t_boolean (*pfun_save[3])(t_map *, char *) = {ants, rooms, links};
    char data[BUFF_SIZE];
    int ants_rooms_links;
    t_boolean to_save;

    ants_rooms_links = 0;
    while (get_next_line(STDIN_FILENO, data) > 0)
    {
        to_save = TRUE;
        while (to_save)
        {
            if (COMMENT(data[0], data[1]))
                break ;
            if (NON_COMPLIANT_LINE(data[0]))
            {
                ft_putstr("NEW_LINE(data[0]) || L(data[0]) || SPACE(data[0])\n");//ERR
                exit(EXIT_FAILURE);
            }
            if ((to_save = pfun_save[ants_rooms_links](pmap, data)))
                ants_rooms_links++;
        }
        ft_putstr(data);
        ft_putchar('\n');
    }
    ft_putstr("\nANTS = ");
    ft_putnbr(pmap->number_of_ants);
    ft_putchar('\n');
}