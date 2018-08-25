#include "../inc/lem_in.h"

static t_boolean is_integer(char *str)
{
    size_t len;

    len = 0;
    if(!*str)
        return FALSE;
    if ((len = ft_strlen(str)) > MAX_LEN_INT)
        return FALSE;
    if (len == MAX_LEN_INT && ft_strcmp(str, MAX_INTEGER_STR))
        return FALSE;
    if (*str == '+' || *str == '-')
        str++;
    while (ft_isdigit(*str++))
        ;
    while (IS_SPACE(*str))
        str++;
    if (*str)
        return FALSE;
    return TRUE;
}

int links(t_map *pmap, char *str)
{
    char *link1;
    char *link2;

    link1 = ft_strchr(str, '-');
    link2 = ft_strrchr(str, '-');
    if (!link1 || link1 != link2)
    {
        ft_putstr("(!link1 || link1 != link2)");//ERR
        exit(EXIT_FAILURE);
    }
    while (*str) 
    {
        if (!ft_isalnum(*str) && *str != '-')
        {
            ft_putstr("!ft_isalnum(*str) && *str != '-'");//ERR
            exit(EXIT_FAILURE);
        }
        str++;
    }
    pmap->number_of_links++;
    return FALSE;
}

int rooms(t_map *pmap, char *str)
{
    if (ft_strchr(str, '-') && *str != '-')
        if (!links(pmap, str))
            return TRUE;
    while(!NON_COMPLIANT_LINE(*str) && *str)
        str++;
        ft_putstr(str);
    if(*str++ != ' ')
    {
        ft_putstr("*ptr != ' '\n");//ERR
        exit(EXIT_FAILURE);
    }
    if (!is_integer(str))
    {
        ft_putstr("is_integer\n");//ERR
        exit (EXIT_FAILURE);
    }
    str++;
    if (!is_integer(str))
    {
        ft_putstr("is_integer\n");//ERR
        exit (EXIT_FAILURE);
    }
    ft_putstr("rooms\n");
    pmap->number_of_rooms++;
    return FALSE;
}

int ants(t_map *pmap, char *str)
{
    ft_putstr("ants\n");
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