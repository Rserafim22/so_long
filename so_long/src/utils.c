#include "so_long.h"

int    mouse_event(int key, int x, int y, t_game *a)
{
    if (key == 17)
    {
        //mlx_mouse_get_pos(a->mlx.window, &a->mouse.x, &a->mouse.y);
        //if ((x >= 7 && x <= 20) && (y <= -7 && y >= -22))
            close_game(a->mlx, 53);
    }
    //if ((x >= 7 && x <= 20) && (y <= -7 && y >= -22))
    /*{
        mlx_mouse_get_pos(a->mlx.window, &a->mouse.x, &a->mouse.y);
        if ((x >= 7 && x <= 20) && (y <= -7 && y >= -22))
            if (key == 1)
                close_game(a->mlx, 53);
                */
        ft_printf("mouse x = %d\n", x);
        ft_printf("mouse y = %d\n", y);
    //}
    ft_printf("%d\n", key);
    return (1);
}