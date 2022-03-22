#include "so_long.h"

int	so_long(const char *arg)
{
	t_game	x;

	x.mapi.x = 0;
    x.mapi.y = 0;
	if (check_map(arg))
	{
		if(map_size_error(arg, &x.mapi) == 0)
			return(printf("%s\n", "mauvaise map :("));
		x.map = maplloc(arg);
		entity_counter(&x);
		printf("%zu\n", x.count_monster);
		init_entity(&x);
		window_init(x);
	}
	return (1);
}
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		(so_long(av[1]));
	}
	else
		return(printf("Error\nNeed a valid map\n"));
}
