#include "so_long.h"
int     key_return(int key, int *nb)
{
    nb = &key;
    printf("%d\n", key);
    return (key);
}

void    key_event(t_mlx *mlx,t_image *game,t_coord *a,char **map, int key)
{
    if (key == 53)
    {
        mlx_clear_window(mlx->ptr,mlx->window);
        mlx_destroy_window(mlx->ptr,mlx->window);
        exit(printf("jeu fermé\n"));
    }
}