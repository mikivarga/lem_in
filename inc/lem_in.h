#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/inc/libft.h"

# define MAX_READ 1024
# define BUFF_SIZE MAX_READ * 2
# define MAX_LEN_INT 10
# define MAX_INTEGER "2147483647"

# define COMMAND(ch1, ch2) ((ch1) == '#' && (ch2) == '#')
# define COMMENT(ch1, ch2) ((ch1) == '#' && (ch2) != '#')
# define NEW_LINE(ch) ((ch) == '\n')
# define IS_SPACE(ch) ((ch) == ' ' || ((ch) > 8 && (ch) < 14))
# define NON_COMPLIANT_LINE(ch) (NEW_LINE((ch)) || IS_SPACE((ch)))
# define UNSUPORTED_ROOM(ch) ((ch) == 'L')

typedef enum {FALSE, TRUE} t_boolean;
typedef enum {KO, OK} t_valid;
typedef enum {ANTS, ROOMS, LINKS} t_parse;


typedef struct s_ant_map
{

} t_ant_map;   


typedef struct s_map
{
    char *the_rooms;
    int number_of_ants;
    int number_of_rooms;


} t_map;

int get_next_line(const int fd, char *line);
void parse_map(t_map *pmap);
t_boolean checking_ants(char *str);
t_boolean checking_rooms(char *str);
t_boolean checking_links(char *str);

#endif /*LEM_IN_H*/