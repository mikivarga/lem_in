#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/inc/libft.h"

# define MAX_READ 1024
# define BUFF_SIZE MAX_READ * 2
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

typedef struct s_edge {
    int start;
    int end;
} t_edge;

typedef struct s_stack {
    t_edge e;
    struct s_stack *next;
} t_stack;





/* INSERT ITEM TYPE HERE */
/* FOR EXAMPLE, */
/* use the following for use_q.c */
/* typedef int Item; */
/* OR typedef struct item {int gumption; int charisma;} Item; */
/* use the following for mall.c */  
typedef struct item
{
    long arrive;      /* the time when a customer joins the queue   */
    int processtime;  /* the number of consultation minutes desired */
} Item;

#define MAXQUEUE 10

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct queue
{
    Node * front;  /* pointer to front of queue  */
    Node * rear;   /* pointer to rear of queue   */
    int items;     /* number of items in queue   */
} Queue;

/* operation:        initialize the queue                       */
/* precondition:     pq points to a queue                       */
/* postcondition:    queue is initialized to being empty        */
void InitializeQueue(Queue * pq);

/* operation:        check if queue is full                     */
/* precondition:     pq points to previously initialized queue  */
/* postcondition:   returns True if queue is full, else False  */
bool QueueIsFull(const Queue * pq);

/* operation:        check if queue is empty                    */
/* precondition:     pq points to previously initialized queue  */
/* postcondition:    returns True if queue is empty, else False */
bool QueueIsEmpty(const Queue *pq);

/* operation:        determine number of items in queue         */
/* precondition:     pq points to previously initialized queue  */
/* postcondition:    returns number of items in queue           */
int QueueItemCount(const Queue * pq);

/* operation:        add item to rear of queue                  */
/* precondition:     pq points to previously initialized queue */
/*                   item is to be placed at rear of queue      */
/* postcondition:    if queue is not empty, item is placed at   */
/*                   rear of queue and function returns         */
/*                   True; otherwise, queue is unchanged and    */
/*                   function returns False                     */
bool EnQueue(Item item, Queue * pq);

/* operation:        remove item from front of queue            */
/* precondition:     pq points to previously initialized queue  */
/* postcondition:    if queue is not empty, item at head of     */
/*                   queue is copied to *pitem and deleted from */
/*                   queue, and function returns True; if the   */
/*                   operation empties the queue, the queue is  */
/*                   reset to empty. If the queue is empty to   */
/*                   begin with, queue is unchanged and the     */
/*                   function returns False                     */
bool DeQueue(Item *pitem, Queue * pq);

/* operation:        empty the queue                            */
/* precondition:     pq points to previously initialized queue  */
/* postconditions:   the queue is empty                         */
void EmptyTheQueue(Queue * pq);









typedef struct s_map
{
    char **the_rooms;
    int **matrix;
    char *farm_map;/*?not need*/
    int index_start;
    int index_end;
    int number_of_ants;
    int number_of_rooms;
} t_map;

int get_next_line(const int fd, char *line);
void parse_map(t_map *pmap);
int links(t_map *pmap, char *str);
int rooms(t_map *pmap, char *str);
int ants(t_map *pmap, char *str);
int room_index(t_map *pmap, char *room);/*not need?*/

struct s_stack *s_new_node(t_edge e);
int s_is_empty(struct s_stack *root);
void s_push(struct s_stack **root, t_edge data);
int s_pop(struct s_stack **root);
t_edge s_peek(struct s_stack *root);

#endif /*LEM_IN_H*/