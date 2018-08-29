#include "../inc/lem_in.h"
#include <stdio.h>

void str_trim_end(char *str)
{
    size_t len;
    char *str_end;
    
    len = ft_strlen(str);
    if (IS_SPACE(*str))
        exit(EXIT_FAILURE);//err
	str_end = (str + (len - 1));
	while (IS_SPACE(*str_end))
		str_end--;
    if (*str_end)
        *(str_end + 1) = '\0';
}

t_boolean is_integer(char *str)
{
    size_t len;

    if(!*str)
        return FALSE;
    if (*str == '+' || *str == '-')
        str++;
    if ((len = ft_strlen(str)) > MAX_LEN_INT)
        return FALSE;
    if (len == MAX_LEN_INT && ft_strcmp(str, MAX_INTEGER_STR))
        return FALSE;
    while (*str)
    {
        if (!ft_isdigit(*str++))
            break ;
    }
    return (*str ? FALSE : TRUE);
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
    {
        *pp++ = *old_rooms++;
    }
    *pp++ = ft_strdup(str);
    *pp = 0;
    if (pmap->number_of_rooms)
        free(old_rooms - (pmap->number_of_rooms));
    pmap->the_rooms = pp - (pmap->number_of_rooms + 1);
}