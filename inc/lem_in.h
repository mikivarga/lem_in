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
/*
struct s_stack *new_node(t_edge e)
{

}

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode =
              (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(struct StackNode *root)
{
    return !root;
}
 
void push(struct StackNode** root, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}
 
int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
 
    return popped;
}
 
int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
 
int main()
{
    struct StackNode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
 
    return 0;
}*/


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
int room_index(t_map *pmap, char *room);
#endif /*LEM_IN_H*/