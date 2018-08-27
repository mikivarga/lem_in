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

void add_room_to_matrix(t_map *pmap, char *room1, char *room2, t_vertex st)
{
    char **room;
    int i;
    int j;

    i = 0;
    j = 0;
    room = pmap->the_rooms;
    while (*room)
    {
        if (!ft_strcmp(*room++, room1))
            break ;
        i++;
    }
    room = pmap->the_rooms;
    while (*room)
    {
        if (!ft_strcmp(*room++, room2))
            break ;
        j++;
    }
    pmap->matrix[i][j] = st;
}

int is_correct_links(t_map *pmap, char *room1, char *room2)
{
    char **room;
    t_boolean link1;
    t_boolean link2;

    link1 = FALSE;
    link2 = FALSE;
    room = pmap->the_rooms;
    if (!*room2)// || !ft_strcmp(room1, room2))
        return FALSE;
    while(*room)
    {
        if (!ft_strcmp(*room, room1))
            link1 = TRUE;
        if (!ft_strcmp(*room++, room2))
            link2 = TRUE;
    }
    return (link1 == link2 && link1 == TRUE);
}

int links(t_map *pmap, char *str)
{
    char *link1;
    char *link2;

    link1 = ft_strchr(str, '-');
    link2 = ft_strrchr(str, '-');
    if (!link1 || link1 != link2)
        exit(EXIT_FAILURE);
    *link1 = '\0';
    if (!is_correct_links(pmap, str, link1 + 1))
        exit(EXIT_FAILURE);
    add_room_to_matrix(pmap, str, link1 + 1, GREEN);
    *link1 = '-';
    while (*str) 
    {
        if (!ft_isalnum(*str) && *str != '-')
            exit(EXIT_FAILURE);
        str++;
    }
    return FALSE;
}

void create_matrix(t_map *pmap)
{
    int i;
    int j;

    i = pmap->number_of_rooms;
    pmap->matrix = (int **)malloc(sizeof(int *) * (i));
    if (!pmap->matrix)
    {
        ft_putstr("malloc\n");//ERR
        exit(EXIT_FAILURE);
    }
    while (i-- > 0)
    {
        j = pmap->number_of_rooms;
        pmap->matrix[i] = (int *)malloc(sizeof(int) * (j));
        while(j-- > 0)
            pmap->matrix[i][j] = ORANGE;
    }
}

void save_rooms(t_map *pmap, char *str)//needed check if the romm is new
{
    char **pp;
    char **old_rooms;

    if (!*str)
        return ;
    pp = (char **)malloc(sizeof(char *) *(pmap->number_of_rooms + 2));
    if (!pp)
    {
        ft_putstr("malloc\n");//ERR
        exit(EXIT_FAILURE);
    }
    old_rooms = pmap->the_rooms;
    while (pmap->number_of_rooms && *old_rooms)
        *pp++ = *old_rooms++;
    *pp++ = ft_strdup(str);
    *pp = 0;
    if (pmap->number_of_rooms)
        free(old_rooms - (pmap->number_of_rooms));
    pmap->the_rooms = pp - (pmap->number_of_rooms + 1);
}

int rooms(t_map *pmap, char *str)
{
    char *new_room;

    new_room = str;
    if (ft_strchr(str, '-'))//???if room consist '-'
    {
        create_matrix(pmap);
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
    *(str - 1) = '\0';
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
    save_rooms(pmap, new_room);
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