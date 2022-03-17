#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct s_coord {
    int                x;
    int                y;
}            t_coord;

typedef struct s_mlx {
    void *ptr;
    void *window;
}           t_mlx;

typedef struct s_image
{
    void *player;
    void *coin;
    void *wall;
    void *sortie;
    void *monster;
    int width;
    int height;
}               t_image;

typedef struct s_game {
    t_mlx           mlx;
    t_image         images;
    t_coord         mapi;
    char            **map;
    t_coord            player;
    int                player_up;
    int                player_down;
    int                player_left;
    int                player_right;
    int                player_move;
    int                player_coll;
    t_coord            exit;
    t_coord            *coll;
    int                count_coll;
    int                count_exit;
    int                count_player;
}                t_game;

int     so_long(const char *map);
int     check_map(const char *map);
int     map_size_error(const char *map_name, t_coord *p);
int     ft_char_find(const char *str, int to_find);
int     ft_check_line(const char *line, char *need);
int     check_mid_map(const char *line, char *need, int fd);
char    **maplloc(const char *arg);
char	*ft_strjoin1(char const *s1, char const *s2);
char	**ft_split(const char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    window_init(t_game a ,char **map);
void    init_image(t_game *a);
void    fill_map(t_mlx mlx, t_image game, char **map, t_coord *index);
void    fill_line(t_coord *index,t_mlx mlx, t_image game, char *line);
int     key_sort(int key, t_game *a);
void    close_game(t_mlx mlx);

#endif