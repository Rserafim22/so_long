#include "so_long.h"

void    window_init(game a,char **map)
{
    void *mlx_ptr;
    void *window;

    mlx_ptr = mlx_init();
    window = mlx_new_window(mlx_ptr,a.pos_x * 100,a.pos_y *100,"so_long");
    mlx_loop(mlx_ptr);
}

// faire fonction param joueur//
// analyse la map pour point de depart joueur + position actuelle//