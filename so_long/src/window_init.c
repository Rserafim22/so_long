#include "so_long.h"

int close_game(int key, t_mlx *mlx)
{
    if (key == 53)
    {
        mlx_clear_window(mlx->ptr,mlx->window);
        mlx_destroy_window(mlx->ptr,mlx->window);
        exit(printf("jeu fermé\n"));
    }
    return(1);
}
void    window_init(t_coord a,char **map)
{
    t_mlx   mlx;
    t_image game;

    mlx.ptr = mlx_init();
    mlx.window = mlx_new_window(mlx.ptr,a.x * 16,a.y *16,"so_long");
    init_image(&game,&mlx);
    fill_map(mlx,game,map);
    mlx_key_hook(mlx.window,close_game,&mlx);
    mlx_loop(mlx.ptr);
}

void    init_image(t_image *p,t_mlx *mlx)
{
    p->player = mlx_xpm_file_to_image(mlx->ptr,"assets/player.xpm",&p->width,&p->height);
    p->wall = mlx_xpm_file_to_image(mlx->ptr,"assets/wall.xpm",&p->width,&p->height);
    p->coin = mlx_xpm_file_to_image(mlx->ptr,"assets/coin.xpm",&p->width,&p->height);
    p->monster = mlx_xpm_file_to_image(mlx->ptr,"assets/monster.xpm",&p->width,&p->height);
}

void    fill_map(t_mlx mlx, t_image game, char **map)
{
    t_coord index;

    index.y = 0;
    while (map[index.y] != NULL)
    {
        index.x = 0;
        fill_line(index,mlx,game,map[index.y]);
        index.y++;
    }
}
void fill_line(t_coord index,t_mlx mlx, t_image game, char *line)
{
    while(line[index.x] != '\0')
        {
            if (line[index.x] == 'P')
                mlx_put_image_to_window(mlx.ptr,mlx.window,game.player,index.x * 16, index.y *16);
            if (line[index.x] == 'C')
                mlx_put_image_to_window(mlx.ptr,mlx.window,game.coin,index.x * 16, index.y * 16);
            if (line[index.x] == '1')
                mlx_put_image_to_window(mlx.ptr,mlx.window,game.wall,index.x * 16, index.y * 16);
            if (line[index.x] == 'M')
                mlx_put_image_to_window(mlx.ptr,mlx.window,game.monster,index.x * 16, index.y * 16);
            index.x++;
        }

}

// faire fonction param joueur//
// analyse la map pour point de depart joueur + position actuelle//