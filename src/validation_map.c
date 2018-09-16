/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:50:17 by mvarga            #+#    #+#             */
/*   Updated: 2018/09/16 18:34:27 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				str_trim_end(char *str)
{
	size_t	len;
	char	*str_end;

	len = ft_strlen(str);
	str_end = (str + (len - 1));
	while (IS_SPACE(*str_end))
		str_end--;
	if (*str_end)
		*(str_end + 1) = '\0';
}

t_boolean			is_integer(char *str)
{
	size_t	len;

	if (!*str)
		return (FALSE);
	if (*str == '+' || *str == '-')
		str++;
	if ((len = ft_strlen(str)) > MAX_LEN_INT)
		return (FALSE);
	if (len == MAX_LEN_INT && ft_strcmp(str, MAX_INTEGER_STR))
		return (FALSE);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			break ;
	}
	return (*str ? FALSE : TRUE);
}

void				save_rooms(t_map *pmap, char *str)
{
	char	**pp;
	char	**old_rooms;
	int		i;

	i = 0;
	if (!*str)
		return ;
	if (!(pp = (char **)malloc(sizeof(char *) * (pmap->number_of_rooms + 2))))
		exit_func(pmap, "Unable to allocate memory!");
	old_rooms = pmap->the_rooms;
	while (pmap->number_of_rooms && old_rooms[i])
	{
		if (!ft_strcmp(old_rooms[i], str))
		{
			free(pp);
			exit_func(pmap, ERR_MSG);
		}
		pp[i] = old_rooms[i];
		i++;
	}
	pp[i++] = ft_strdup(str);
	pp[i] = 0;
	if (pmap->number_of_rooms++)
		free(old_rooms);
	pmap->the_rooms = pp;
}

static t_boolean	check_coord_xy(char *data1, char *data2, t_parse is_room)
{
	int		fl;
	char	*pstr1;
	char	*pstr2;

	if (is_room != ROOMS || COMMAND(data2[0], data2[1]) ||
COMMAND(data1[0], data1[1]))
		return (TRUE);
	pstr1 = ft_strchr(data1, ' ');
	pstr2 = ft_strchr(data2, ' ');
	if (!pstr1 | !pstr2)
		return (TRUE);
	fl = ft_strcmp(pstr1, pstr2);
	return (fl == 0 ? FALSE : TRUE);
}

void				save_map(t_map *pmap, char *data, t_parse is_room)
{
	char	**pp;
	char	**old_rooms;
	int		i;

	i = 0;
	if (!*data)
		return ;
	if (!(pp = (char **)malloc(sizeof(char *) * (pmap->cnt_lines + 2))))
		exit_func(pmap, "Unable to allocate memory!");
	old_rooms = pmap->map;
	while (pmap->cnt_lines && old_rooms[i])
	{
		if (!check_coord_xy(old_rooms[i], data, is_room))
		{
			free(pp);
			exit_func(pmap, ERR_MSG);
		}
		pp[i] = old_rooms[i];
		i++;
	}
	pp[i++] = ft_strdup(data);
	pp[i] = 0;
	if (pmap->cnt_lines++)
		free(old_rooms);
	pmap->map = pp;
}
