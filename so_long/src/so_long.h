#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
typedef struct s_game {
    int pos_x;
    int pos_y;
    int coin;
    int wall;
    int monster;

}               game;

int so_long(const char *map);
int check_map(const char *map);
int map_size_error(const char *map_name, game *p);
int ft_char_find(const char *str, int to_find);
int ft_check_line(const char *line, char *need);
int check_mid_map(const char *line, char *need, int fd);
char **maplloc(const char *arg);
char	*ft_strjoin1(char const *s1, char const *s2);
char	**ft_split(const char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    window_init(game a,char **map);

#endif