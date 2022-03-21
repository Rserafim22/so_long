#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"

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
    t_coord            sortie;
    t_coord            coll;
    t_coord            *monster;
    int                collected;
    size_t                count_monster;
    size_t             count_coll;
    int                count_player;
    size_t              index;
    size_t              player_moves;
}                t_game;

int     so_long(const char *map);
int     check_map(const char *map);
int     map_size_error(const char *map_name, t_coord *p);
int     ft_char_find(const char *str, int to_find);
int     ft_check_line(const char *line, char *need);
int     check_mid_map(const char *line, char *need, int fd);
int     check_need(char c, char *need);
char    **maplloc(const char *arg);
void    window_init(t_game a);
void    init_image(t_game *a);
void    fill_map(t_game *p, char **map);
void    fill_line(char *line, t_game *a);
int     key_sort(int key, t_game *a);
void    close_game(t_mlx mlx, int i);
void    player_up(t_game *a);
void    player_down(t_game *a);
void    player_left(t_game *a);
void    player_right(t_game *a);
void    clear_image(t_mlx mlx, t_coord player);
void entity_counter(t_game *x);
void    init_entity(t_game *a);
void    coin_collected(t_game *a);
void    init_position(t_game *a, char c);

#endif