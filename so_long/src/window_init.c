#include "so_long.h"

void    close_game(t_mlx mlx)
{
    mlx_clear_window(mlx.ptr,mlx.window);
        mlx_destroy_window(mlx.ptr,mlx.window);
        exit(printf("jeu fermé\n"));
}
int key_sort(int key, t_game *a)
{
    if (key == 53)
        close_game(a->mlx);
    //if (key == 13)

    return(1);
}
void    window_init(t_game a, char **map)
{
    a.mlx.ptr = mlx_init();
    a.mlx.window = mlx_new_window(a.mlx.ptr,a.mapi.x * 16,a.mapi.y *16,"so_long");
    init_image(&a);
    fill_map(a.mlx,a.images,map,&a.mapi);
    mlx_key_hook(a.mlx.window,key_sort,&a);
    mlx_loop(a.mlx.ptr);
}

void    init_image(t_game *p)
{
    p->images.player = mlx_xpm_file_to_image(p->mlx.ptr,"assets/player.xpm",&p->images.width,&p->images.height);
    p->images.wall = mlx_xpm_file_to_image(p->mlx.ptr,"assets/wall.xpm",&p->images.width,&p->images.height);
    p->images.coin = mlx_xpm_file_to_image(p->mlx.ptr,"assets/coin.xpm",&p->images.width,&p->images.height);
    p->images.monster = mlx_xpm_file_to_image(p->mlx.ptr,"assets/monster.xpm",&p->images.width,&p->images.height);
}

void    fill_map(t_mlx mlx, t_image game, char **map, t_coord *index)
{
    index->y = 0;
    while (map[index->y] != NULL)
    {
        index->x = 0;
        fill_line(index,mlx,game,map[index->y]);
        index->y++;
    }
}
void fill_line(t_coord *index,t_mlx mlx, t_image game, char *line)
{
    while(line[index->x] != '\0')
        {
            if (line[index->x] == 'P')
            {
                mlx_put_image_to_window(mlx.ptr,mlx.window,game.player,index->x * 16, index->y *16);
            }
            if (line[index->x] == 'C')
                mlx_put_image_to_window(mlx.ptr,mlx.window,game.coin,index->x * 16, index->y * 16);
            if (line[index->x] == '1')
                mlx_put_image_to_window(mlx.ptr,mlx.window,game.wall,index->x * 16, index->y * 16);
            if (line[index->x] == 'M')
                mlx_put_image_to_window(mlx.ptr,mlx.window,game.monster,index->x * 16, index->y * 16);
            index->x++;
        }

}

// faire fonction param joueur//
// analyse la map pour point de depart joueur + position actuelle//