#include "../inc/lem_in.h"
#include <stdio.h>

static t_boolean is_command(t_map *pmap, char *data, t_parse is_room)
{
    static int start = 0;
    static int end = 0;

    if (!COMMAND(data[0], data[1]))
    {
        if (is_room == LINKS && (start != 1 || end != 1))
        {
            exit_func(pmap, ERR_MSG);
        }
        return FALSE;
    }
    if (!ft_strcmp(CMD_START, data))
    {
        pmap->index_start = pmap->number_of_rooms;
        start++;
    }
    if (!ft_strcmp(CMD_END, data))
    {
        pmap->index_end = pmap->number_of_rooms;
        end++;
    }
    if (start > 1 || end > 1 || is_room != ROOMS)
    {
        exit_func(pmap, ERR_MSG);
    }
    return TRUE;
}

static t_boolean is_links(t_map *pmap, char *str)
{
    char *link1;
    char *link2;
 
    link1 = ft_strchr(str, '-');
    link2 = ft_strrchr(str, '-');
    if (!link1 || link1 != link2)
        exit_func(pmap, ERR_MSG);
    *link1 = '\0';
    if (!add_room_to_matrix(pmap, str, link1 + 1))
        exit_func(pmap, ERR_MSG);
        
    *link1 = '-';
    while (*str) 
    {
        if (!ft_isalnum(*str) && *str != '-')
            exit_func(pmap, ERR_MSG);
        str++;
    }
    return FALSE;
}

static t_boolean is_rooms(t_map *pmap, char *str)
{
    char *room;
    char *coord_y;

    room = str;
    while (*str && ft_isalnum(*str))
        str++;
    if (!*str || !*(str + 1) || *str != ' ')// || !ft_isdigit(*(str + 1)))
    {
        create_matrix(pmap);
        is_links(pmap, room);
        return TRUE;
    }
    *str++ = '\0';
    if (!(coord_y = ft_strchr(str, ' ')) || coord_y == str)
    {
        create_matrix(pmap);
        is_links(pmap, room);
        return TRUE;
    }
    *coord_y++ = '\0';
    if (!is_integer(str) || !is_integer(coord_y))
        exit_func(pmap, ERR_MSG);
    save_rooms(pmap, room);
    pmap->number_of_rooms++;
    return FALSE;
}

static t_boolean is_ants(t_map *pmap, char *str)
{
    if (!is_integer(str))
        exit_func(pmap, ERR_MSG);
    pmap->number_of_ants = ft_atoi(str);
    if (pmap->number_of_ants <= 0)
        exit_func(pmap, ERR_MSG);
    return TRUE;
}

void read_map(t_map *pmap)
{
    char data[BUFF_SIZE];
    int ants_rooms_links;
    t_boolean (*pfun_save[FORMAT])(t_map *, char *) = {is_ants, is_rooms, is_links};
    
    ants_rooms_links = ANTS;
    while (get_next_line(STDIN_FILENO, data) > 0)
    {
        str_trim_end(data);
        if (COMMENT(data[0], data[1]))
        {
            continue ;
        }
        ft_putendl(data);
        if (is_command(pmap, data, ants_rooms_links))
        {
            continue ;
        }
        if (NON_COMPLIANT_LINE(data[0]) || UNSUPORTED_ROOM(data[0]))
        {
            exit_func(pmap, ERR_MSG);
        }
        if (pfun_save[ants_rooms_links](pmap, data) && ants_rooms_links < FORMAT)
        {
            ants_rooms_links++;
        }
    }
}