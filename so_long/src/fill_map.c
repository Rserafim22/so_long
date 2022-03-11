#include "so_long.h"
#include "get_next_line.h"
void    ft_free(char *str)
{
    int i;

    i = 0;
    while (str[i++] != '\0')
        free(&str[i]);
}
char **maplloc(const char *arg)
{
    int fd;
    char **tab;
    const char   *line;
    const char  *save;

    save = "";
    fd = open(arg,O_RDONLY);
    line = get_next_line(fd);
        while (line != NULL)
        {
            line = ft_strjoin((char *)line,'S');
            save = ft_strjoin1(save, line);
            line = get_next_line(fd);
        }
        return(tab = ft_split(save, 'S'));
        
}