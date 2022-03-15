#include "so_long.h"
//void    init_image(void *mlx_ptr, game a);
void    window_init(game a,char **map)
{
    void *mlx_ptr;
    void *window;
    void *tchoupi;
    int img_widht;
    int img_height;

    mlx_ptr = mlx_init();
    window = mlx_new_window(mlx_ptr,a.pos_x * 100,a.pos_y *100,"so_long");
    //init_image(mlx_ptr, a);
    tchoupi = mlx_xpm_file_to_image(mlx_ptr,"TCHOUPI.xpm",&img_widht,&img_widht);
    mlx_put_image_to_window(mlx_ptr,window,tchoupi,20,20);
    printf("widht %d\n", img_widht);
    printf("height %d\n", img_height);
    mlx_loop(mlx_ptr);

}

/*void    init_image(void *mlx_ptr, game a)
{
    int img_widht;
    int img_height;
    void *img_ptr;

    mlx_xpm_file_to_image(mlx_ptr,"TCHOUPI.xpm",&img_widht,&img_widht);
    printf("widht %d\n", img_widht);
    printf("height %d\n", img_height);
}*/

// faire fonction param joueur//
// analyse la map pour point de depart joueur + position actuelle//