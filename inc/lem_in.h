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
# define MAX_WAYS 1000

# define COMMAND(ch1, ch2) ((ch1) == '#' && (ch2) == '#')
# define COMMENT(ch1, ch2) ((ch1) == '#' && (ch2) != '#')
# define NEW_LINE(ch) ((ch) == '\n')
# define IS_SPACE(ch) ((ch) == ' ' || ((ch) > 8 && (ch) < 14))
# define NON_COMPLIANT_LINE(ch) (NEW_LINE((ch)) || IS_SPACE((ch)))
# define UNSUPORTED_ROOM(ch) ((ch) == 'L')

typedef enum {FALSE, TRUE} t_boolean;
typedef enum {ORANGE, GREEN, GRAY, PUPLE} t_vertex;
typedef enum {ANTS, ROOMS, LINKS} t_parse;

typedef struct s_edge
{
    int start;
    int end;
} t_edge;

typedef union u_data 
{
    int index;
    t_edge e;
} t_data;

typedef struct s_node
{
    t_data info;
    struct s_node *next;
} t_node;

typedef struct s_queue
{
    t_node *front;
    t_node *rear;
    int items;
} t_queue;

typedef t_node *t_stack;
typedef t_node *t_lst;

typedef struct s_map
{
    char **the_rooms;
    char **matrix;
    int index_start;
    int index_end;
    int number_of_ants;
    int number_of_rooms;
    int number_of_ways;
} t_map;

/*parsing*/
int get_next_line(const int fd, char *line);
void read_map(t_map *pmap);
void str_trim_end(char *str);
t_boolean is_integer(char *str);
void save_rooms(t_map *pmap, char *str);
/**/
void create_matrix(t_map *pmap);
t_boolean add_room_to_matrix(t_map *pmap, char *r1, char *r2);
void clear_room_in_matrix(t_map *pmap, int index);
/**/
void save_ways(t_map *pmap, t_lst *ways);

t_boolean is_empty(t_node *root);
t_edge s_peek(t_node *root);

/*stack*/

void s_initialize(t_stack *pst);
t_boolean s_push(t_stack *pst, t_edge data);
t_boolean s_pop(t_stack *root);

/*list*/

void l_initialize(t_lst *plst);
t_boolean l_add(int index, t_lst *plst);
void l_show(t_lst *plst, char **room, int cnt, void(*pfun)(int, char *));
t_boolean l_delete_node(int index, t_lst *plst);
void l_delete(t_lst *plst);

/*queue*/

void q_initialize(t_queue * pq);
t_boolean q_is_empty(const t_queue *pq);
int q_item_count(const t_queue * pq);
t_boolean q_push(int index, t_queue * pq);
t_boolean q_pop(int *index, t_queue * pq);
void q_empty(t_queue * pq);

#endif /*LEM_IN_H*/