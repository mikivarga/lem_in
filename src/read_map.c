#include "../inc/lem_in.h"

static void is_correct_command(t_map *pmap, char *data, int is_room)
{
    static int start = 0;
    static int end = 0;

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
        ft_putstr("NEW_LINE || UNSUPORTED_ROOM || SPACE(data[0])\n");//ERR
        exit(EXIT_FAILURE);
    }
}

static void save_map(t_map *pmap, char *data)
{
    static int buf_size = MAX_READ;
    char *new_farm_map;
    char *old_farm_map;
    char *tmp;

    if ((int)(ft_strlen(pmap->farm_map) + ft_strlen(data)) > buf_size)
    {
        old_farm_map = pmap->farm_map;
        buf_size *= 2;
        if (!(new_farm_map = (char *)malloc((buf_size) * sizeof(char))))
            exit(EXIT_FAILURE);//ERR
        ft_bzero(new_farm_map, buf_size);
        tmp = new_farm_map;
        while ((*new_farm_map++ = *old_farm_map++))
            ;
        free(pmap->farm_map);
        pmap->farm_map = tmp;
    }
    ft_strncat(pmap->farm_map, data, ft_strlen(data));
    ft_strncat(pmap->farm_map, "\n", 1); 
}

void parse_map(t_map *pmap)
{
    char data[BUFF_SIZE];
    int ants_rooms_links;
    int (*pfun_save[3])(t_map *, char *) = {ants, rooms, links};
    
    ants_rooms_links = 0;
    if (!(pmap->farm_map = ft_strnew(MAX_READ)))//init
        exit(EXIT_FAILURE);//ERR
    while (get_next_line(STDIN_FILENO, data) > 0)
    {
        save_map(pmap, data);//?
        ft_putendl(data);
        if (COMMENT(data[0], data[1]))
            continue ;
        if (COMMAND(data[0], data[1]))
        {
            is_correct_command(pmap, data, ants_rooms_links);
            continue ;
        }
        if (NON_COMPLIANT_LINE(data[0]) || UNSUPORTED_ROOM(data[0]))
            exit(EXIT_FAILURE);//err
        if (pfun_save[ants_rooms_links](pmap, data) && ants_rooms_links < 3)
            ants_rooms_links++;
    }
}