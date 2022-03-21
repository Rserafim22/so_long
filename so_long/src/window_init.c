#include "so_long.h"

void    close_game(t_mlx mlx, int i)
{
    mlx_clear_window(mlx.ptr,mlx.window);
    mlx_destroy_window(mlx.ptr,mlx.window);
    if (i == 53)
        exit(printf("Jeu fermé\n"));
    if (i == 1)
        exit(printf("Bien vu bg\n"));
    if (i == 2)
        exit(printf("Zebi c'est dangereux\n"));
}
int key_sort(int key, t_game *a)
{
    if (key == 53)
        close_game(a->mlx,53);
    if (key == 13)
        player_up(a);
    if (key == 1)
        player_down(a);
    if (key == 0)
        player_left(a);
    if (key == 2)
        player_right(a);
    return(1);
}
void    window_init(t_game a)
{
    a.mlx.ptr = mlx_init();
    a.mlx.window = mlx_new_window(a.mlx.ptr,a.mapi.x * 16,a.mapi.y *16,"so_long");
    init_image(&a);
    fill_map(&a,a.map);
    printf("player x :%d\nplayer y :%d\n", a.player.x, a.player.y);
    mlx_key_hook(a.mlx.window,key_sort,&a);
    mlx_loop(a.mlx.ptr);
}

void    init_image(t_game *p)
{
    p->images.sortie = mlx_xpm_file_to_image(p->mlx.ptr,"assets/sortie.xpm",&p->images.width,&p->images.height);
    p->images.player = mlx_xpm_file_to_image(p->mlx.ptr,"assets/player.xpm",&p->images.width,&p->images.height);
    p->images.wall = mlx_xpm_file_to_image(p->mlx.ptr,"assets/wall.xpm",&p->images.width,&p->images.height);
    p->images.coin = mlx_xpm_file_to_image(p->mlx.ptr,"assets/coin.xpm",&p->images.width,&p->images.height);
    p->images.monster = mlx_xpm_file_to_image(p->mlx.ptr,"assets/monster.xpm",&p->images.width,&p->images.height);
}

void    fill_map(t_game *p, char **map)
{
    p->mapi.y = 0;
    while (map[p->mapi.y] != NULL)
    {
        p->mapi.x = 0;
        fill_line(map[p->mapi.y], p);
        p->mapi.y++;
    }
}
void fill_line(char *line, t_game *a)
{
    while(line[a->mapi.x] != '\0')
        {
            if (line[a->mapi.x] == 'P')
                init_position(a,line[a->mapi.x]);
            if (line[a->mapi.x] == 'C')
                init_position(a,line[a->mapi.x]);
            if (line[a->mapi.x] == '1')
                mlx_put_image_to_window(a->mlx.ptr,a->mlx.window,a->images.wall,a->mapi.x * 16, a->mapi.y * 16);
            if (line[a->mapi.x] == 'M')
            {
                init_position(a,line[a->mapi.x]);
                a->count_monster++;
            }
            if (line[a->mapi.x] == 'E')
                init_position(a,line[a->mapi.x]);
            a->mapi.x++;
        }

}

void    init_position(t_game *a, char c)
{
    if (c == 'P')
    {
        mlx_put_image_to_window(a->mlx.ptr,a->mlx.window,a->images.player,a->mapi.x * 16, a->mapi.y *16);
        a->player.x = a->mapi.x;
        a->player.y = a->mapi.y;
    }
    if (c == 'C')
    {
        mlx_put_image_to_window(a->mlx.ptr,a->mlx.window,a->images.coin,a->mapi.x * 16, a->mapi.y * 16);
        a->coll.x = a->mapi.x;
        a->coll.y = a->mapi.y;
    }
    if (c == 'M')
    {
        mlx_put_image_to_window(a->mlx.ptr,a->mlx.window,a->images.monster,a->mapi.x * 16, a->mapi.y * 16);
        a->monster->x = a->mapi.x;
        a->monster->y = a->mapi.y;
        a->monster++;
    }
    if (c == 'E')
    {
        mlx_put_image_to_window(a->mlx.ptr,a->mlx.window,a->images.sortie,a->mapi.x * 16, a->mapi.y * 16);
        a->sortie.x = a->mapi.x;
        a->sortie.y = a->mapi.y;
    }
}

// faire fonction param joueur//
// analyse la map pour point de depart joueur + position actuelle//