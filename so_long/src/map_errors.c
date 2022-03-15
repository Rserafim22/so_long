#include "so_long.h"
#include "get_next_line.h"

int map_size_error(const char *map_name, t_coord *p)
{
    int fd;
    char *line;
    static char *need;

    need = strdup("CPE");
    fd = (open(map_name,O_RDONLY));
    line = get_next_line(fd);
    if (ft_char_find(line,'0'))
        return(0);
    printf("first line ok\n");
    (*p).x = strlen(line);
    (*p).y = check_mid_map (line,need,fd);
    if ((*p).y == 0 || (*p).x == 0)
        return (0);
     printf("x y != 0 ok\n");
    if ((*p).y == (*p).x)
        return(0);
     printf("x != y ok\n");
    if (strcmp(need, "777") != 0)
        return (0);
     printf("need ok\n");
    return (1);
}
int ft_char_find(const char *str, int to_find)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if(str[i] == to_find)
            return (1);
        i++;
    }
    return (0);
}

int ft_check_line(const char *line, char *need)
{
    int i;
    int y;

    i = - 1;
    printf("%s\n", line);
    while (line[++i] != '\0')
    {
        if ((line[i + 1] == '\0' && line[i] != '1') || line[0] != '1')
            return (1);
        if (line[i] == 'P' || line[i] == 'C' || line[i] == 'E')
        {
            y = 0;
            while (need[y] != '\0')
            {
                if (need[y] == line[i])
                    need[y] = '7';
                y++;
            }
        }
        if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
            && line[i] != 'E'  && line[i] != 'M' && line[i] != 'P' && line[i] != '\0')
                return (1);
    }
    return (0);
}
int check_mid_map(const char *line, char *need, int fd)
{
    int i;
    char    *last_line;
    size_t  comp;

    i = 0;
    comp = strlen(line);
    while (line != NULL || line != (void*)0)
    {
        i++;
        last_line = strdup(line);
        if (comp != strlen(line))
            return (0);
         printf("comp ok\n");
        if (ft_check_line(line, need) == 1)
            return (0);
         printf("check line ok\n");
        line = get_next_line(fd);
    }
    if (ft_char_find(last_line,'0'))
        return(0);
    return (i);
}

int check_map(const char *map)
{
    char *check;

    check = strrchr(map,'.');
    check++;
    if (strcmp(check,"ber") == 0)
        return (1);
    else
        return (0);
}
