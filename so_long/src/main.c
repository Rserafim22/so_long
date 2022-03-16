#include "so_long.h"
int	so_long(const char *arg)
{
	t_coord a;
	t_coord *p;
	char	**map;

	a.x = 0;
    a.y = 0;
	p = &a;
	if (check_map(arg))
	{
		if(map_size_error(arg, p) == 0)
			return(printf("%s\n", "mauvaise map :("));
		map = maplloc(arg);
		window_init(a,map);
	}
	return (1);
}
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		(so_long(av[1]));
		/*void	*new_ptr;
		void	*win_ptr;

		new_ptr = mlx_init();
		win_ptr = mlx_new_window(new_ptr,500, 500, "so_long");
		mlx_loop(new_ptr);*/
	}
}
