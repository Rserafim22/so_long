#include "so_long.h"
int	so_long(const char *arg)
{
	int i;
	t_coord a;
	t_coord *p;
	//int map_size;
	char	**map;

	a.x = 0;
    a.y = 0;
	i = -1;
	p = &a;
	if (check_map(arg))
	{
		if(map_size_error(arg, p) == 0)
			return(printf("%s\n", "mauvaise map :("));
		printf("x = %d\n", a.x);
		printf("y = %d\n", a.y);
		map = maplloc(arg);
		while(++i < 20)
		printf("%s\n", map[i]);
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
