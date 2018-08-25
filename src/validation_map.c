#include "../inc/lem_in.h"

static t_boolean is_integer(char *str, t_boolean fl)
{
    size_t len;
    char *ptr;

    if(!*str)
        return FALSE;
    if (fl)
    {
        ptr = ft_strchr(str, ' ');
        *ptr = '\0';
    }
    if ((len = ft_strlen(str)) > MAX_LEN_INT)
        return FALSE;
    if (len == MAX_LEN_INT && ft_strcmp(str, MAX_INTEGER_STR))
        return FALSE;
    if (*str == '+' || *str == '-')
        str++;
    while (ft_isdigit(*str++))
        ;
    while (IS_SPACE(*str++))
        ;
    if (fl)
        *ptr = ' ';
    return (*str ? FALSE : TRUE);
}

int is_correct_links(t_map *pmap, char *room1, char *room2)
{
    int cnt_rooms;
    char *room;

    cnt_rooms = pmap->number_of_rooms;
    if (!link || !ft_strcmp(room1, room2))
        return FALSE;
    while(cnt_rooms >= 0)
    {
        ft_strncmp()//need array of rooms;
    }
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
    *link1 = '\0';
    if (!is_correct_links(pmap, str, link1 + 1))
    {
        ft_putstr("!checking_links(pmap, str, link1 + 1)");//ERR
        exit(EXIT_FAILURE);
    }
    *link1 = '-';
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
    char **tmp;
    int cnt_rooms;

    if (ft_strchr(str, '-'))//???if room consist '-'
    {
        cnt_rooms = pmap->number_of_rooms;
        while (cnt_rooms >= 0)
        {
            ft_strncmp()//  гамнокод простіше при виділенні памяті записувати!!
        }
        if (!links(pmap, str))
        {
            return TRUE;
        }
    }
    while(!NON_COMPLIANT_LINE(*str) && *str)
        str++;
    if(*str++ != ' ')
    {
        ft_putstr("*ptr != ' '\n");//ERR
        exit(EXIT_FAILURE);
    }
    if (!is_integer(str++, TRUE))
    {
        ft_putstr("1is_integer\n");//ERR
        exit (EXIT_FAILURE);
    }
    if (!is_integer(str, FALSE))
    {
        ft_putstr("is_integer\n");//ERR
        exit (EXIT_FAILURE);
    }
    pmap->number_of_rooms++;
    return FALSE;
}

int ants(t_map *pmap, char *str)
{
    if (!is_integer(str, FALSE)) {
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