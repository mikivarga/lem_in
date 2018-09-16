/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:19:30 by mvarga            #+#    #+#             */
/*   Updated: 2018/09/16 18:09:16 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/inc/libft.h"

# define MAX_READ 1024
# define BUFF_SIZE MAX_READ * 2
# define FORMAT 3
# define MAX_LEN_INT 10
# define MAX_INTEGER_DIG 2147483647
# define MAX_INTEGER_STR "2147483647"
# define CMD_START "##start"
# define CMD_END "##end"
# define CMD_COLOUR "##colour"
# define CMD_PATH "##path"
# define ERR_MSG "ERROR\n"
# define MAX_WAYS 1024

# define COMMAND(ch1, ch2) ((ch1) == '#' && (ch2) == '#')
# define COMMENT(ch1, ch2) ((ch1) == '#' && (ch2) != '#')
# define NEW_LINE(ch) ((ch) == '\n' || (ch) == '\0')
# define IS_SPACE(ch) ((ch) == ' ' || ((ch) > 8 && (ch) < 14))
# define NON_COMPLIANT_LINE(ch) (NEW_LINE((ch)) || IS_SPACE((ch)))
# define UNSUPORTED_ROOM(ch) ((ch) == 'L')

typedef enum		e_boolean
{
	FALSE,
	TRUE,
	WARNING
}					t_boolean;

typedef	enum		e_vertex
{
	ORANGE,
	GREEN,
	GRAY,
	PUPLE
}					t_vertex;

typedef enum		e_parse
{
	ANTS,
	ROOMS,
	LINKS
}					t_parse;

typedef struct		s_edge
{
	int				start;
	int				end;
}					t_edge;

typedef struct		s_ants_info
{
	int				index;
	int				ant;
}					t_ants_info;

typedef union		u_data
{
	int				index;
	t_edge			e;
	t_ants_info		room;
}					t_data;

typedef	struct		s_node
{
	t_data			info;
	struct s_node	*next;
}					t_node;

typedef	struct		s_queue
{
	t_node			*front;
	t_node			*rear;
	int				items;
}					t_queue;

typedef t_node		*t_stack;
typedef t_node		*t_lst;

typedef	struct		s_map
{
	char			**map;
	char			**the_rooms;
	char			**matrix;
	int				index_start;
	int				index_end;
	int				number_of_ants;
	int				number_of_rooms;
	int				number_of_ways;
	int				cnt_lines;
	t_boolean		cmd_colour;
	t_boolean		cmd_path;
}					t_map;

int					get_line(const int fd, char *line);
void				read_map(t_map *pmap);
void				str_trim_end(char *str);
void				save_map(t_map *pmap, char *data, t_parse is_room);
t_boolean			is_integer(char *str);
void				move(t_map *pmap, t_boolean flag);
void				save_rooms(t_map *pmap, char *str);
void				show_map(t_map *pmap);
void				create_matrix(t_map *pmap);
t_boolean			add_room_to_matrix(t_map *pmap, char *r1, char *r2);
void				clear_room_in_matrix(t_map *pmap, int index);
void				save_ways(t_map *pmap, t_lst *ways);
void				print_ant(t_map *pmap, int ant, char *room);
void				show_ways(t_map *pmap, t_lst *ways);
t_boolean			is_empty(t_node *root);
void				free_ways(t_map *pmap, t_lst *ways);
void				cmd(t_map *pmap, char *data, int *start, int *end);
void				exit_func(t_map *pmap, const char *err_msg);

void				s_initialize(t_stack *pst);
t_boolean			s_push(t_stack *pst, t_edge data);
t_boolean			s_pop(t_stack *root);
t_edge				s_peek(t_node *root);

void				l_initialize(t_lst *plst);
t_boolean			l_add(t_ants_info i, t_lst *plst);
t_boolean			l_delete_node(int index, t_lst *plst);
void				l_delete(t_lst *plst);

void				q_initialize(t_queue *pq);
t_boolean			q_is_empty(const t_queue *pq);
int					q_item_count(const t_queue *pq);
t_boolean			q_push(int index, t_queue *pq);
t_boolean			q_pop(int *index, t_queue *pq);
void				q_empty(t_queue *pq);

#endif
