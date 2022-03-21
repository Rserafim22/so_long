#include "so_long.h"
void    player_up(t_game *a)
{
    char *line_up;

    line_up = strdup(a->map[a->player.y - 1]);
    if (line_up[a->player.x] != '1' || ((a->player.x == a->sortie.x && a->player.y == a->sortie.y) && a->collected != 1))
    {
        a->player_moves++;
        printf("player moves = %zu\n", a->player_moves);
        if (a->player.x != a->sortie.x || a->player.y != a->sortie.y)
            clear_image(a->mlx,a->player);
        a->player.y -= 1;
        mlx_put_image_to_window(a->mlx.ptr,a->mlx.window,a->images.player,a->player.x * 16,a->player.y *16);
        if (a->player.x == a->coll.x && a->player.y == a->coll.y)
            a->collected = 1;
        if (a->player.x == a->sortie.x && a->player.y == a->sortie.y && a->collected == 1)
            close_game(a->mlx, 1);
        if (a->player.x == a->monster->x && a->player.y == a->monster->y)
          close_game(a->mlx, 2);
    }
    else
        printf("moove impossible\n");
    free(line_up);
}

void    player_down(t_game *a)
{
    char *line_up;

    line_up = strdup(a->map[a->player.y + 1]);
    if (line_up[a->player.x] != '1' || ((a->player.x == a->sortie.x && a->player.y == a->sortie.y) && a->collected != 1))
    {
        a->player_moves++;
        printf("player moves = %zu\n", a->player_moves);
         if (a->player.x != a->sortie.x || a->player.y != a->sortie.y)
            clear_image(a->mlx,a->player);
        a->player.y += 1;
        mlx_put_image_to_window(a->mlx.ptr,a->mlx.window,a->images.player,a->player.x * 16,a->player.y *16);
        if (a->player.x == a->monster->x && a->player.y == a->monster->y)
          close_game(a->mlx, 2);
        if (a->player.x == a->coll.x && a->player.y == a->coll.y)
            a->collected = 1;
        if (a->player.x == a->sortie.x && a->player.y == a->sortie.y && a->collected == 1)
            close_game(a->mlx, 1);
    }
    else
        printf("moove impossible\n");
    free(line_up);
}

void    player_left(t_game *a)
{
    char *line;

    line = strdup(a->map[a->player.y]);
    if (line[a->player.x - 1] != '1' || ((a->player.x == a->sortie.x && a->player.y == a->sortie.y) && a->collected != 1))
    {
        a->player_moves++;
        printf("player moves = %zu\n", a->player_moves);
         if (a->player.x != a->sortie.x || a->player.y != a->sortie.y)
            clear_image(a->mlx,a->player);
        a->player.x -= 1;
        mlx_put_image_to_window(a->mlx.ptr,a->mlx.window,a->images.player,a->player.x * 16,a->player.y *16);
        if (a->player.x == a->coll.x && a->player.y == a->coll.y)
            a->collected = 1;
        if (a->player.x == a->monster->x && a->player.y == a->monster->y)
            close_game(a->mlx, 2);
        if (a->player.x == a->sortie.x && a->player.y == a->sortie.y && a->collected == 1)
            close_game(a->mlx, 1);
    }
    else
        printf("moove impossible\n");
    free (line);
}

void    player_right(t_game *a)
{
    char *line;

    line = strdup(a->map[a->player.y]);
    if (line[a->player.x + 1] != '1')
    {
        a->player_moves++;
        printf("player moves = %zu\n", a->player_moves);
         if (a->player.x != a->sortie.x || a->player.y != a->sortie.y)
            clear_image(a->mlx,a->player);
        a->player.x += 1;
        mlx_put_image_to_window(a->mlx.ptr,a->mlx.window,a->images.player,a->player.x * 16,a->player.y *16);
        if (a->player.x == a->coll.x && a->player.y == a->coll.y)
            a->collected = 1;
        if (a->player.x == a->monster->x && a->player.y == a->monster->y)
          close_game(a->mlx, 2);
        if (a->player.x == a->sortie.x && a->player.y == a->sortie.y && a->collected == 1)
            close_game(a->mlx, 1);
    }
    else
        printf("moove impossible\n");
    free(line);
}
void    clear_image(t_mlx mlx, t_coord player)
{
    int i;
    int y;
    t_coord tab;

    tab.y = (player.y) * 16;
    y = 0;
    while(y++ < 16)
    {
        i = 0;
        tab.x = player.x * 16;
        while (i++ < 16)
        {
            mlx_pixel_put(mlx.ptr,mlx.window,tab.x,tab.y, 000000);
            tab.x++;
        }
        tab.y++;
    }
}