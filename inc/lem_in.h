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

typedef struct s_stack
{
    t_edge e;
    struct s_stack *next;
} t_stack;

typedef struct s_node
{
    int index;
    struct s_node * next;
} t_node;

typedef struct s_queue
{
    t_node * front;
    t_node * rear;
    int items;
} t_queue;

typedef struct s_map
{
    char **the_rooms;
    char **matrix;
    int **ways;
    int index_start;
    int index_end;
    int number_of_ants;
    int number_of_rooms;
    int number_of_ways;
} t_map;

int get_next_line(const int fd, char *line);
void read_map(t_map *pmap);
void str_trim_end(char *str);
t_boolean is_integer(char *str);
void save_rooms(t_map *pmap, char *str);
void create_matrix(t_map *pmap);
t_boolean add_room_to_matrix(t_map *pmap, char *r1, char *r2);
void clear_room_in_matrix(t_map *pmap, int index);
t_boolean check_ways(t_map *pmap);

struct s_stack *s_new_node(t_edge e);
int s_is_empty(struct s_stack *root);
void s_push(struct s_stack **root, t_edge data);
int s_pop(struct s_stack **root);
t_edge s_peek(struct s_stack *root);

void q_initialize(t_queue * pq);
t_boolean q_is_empty(const t_queue *pq);
int q_item_count(const t_queue * pq);
t_boolean q_push(int index, t_queue * pq);
t_boolean q_pop(int *index, t_queue * pq);
void q_empty(t_queue * pq);

#endif /*LEM_IN_H*/