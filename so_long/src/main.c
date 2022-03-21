#include "so_long.h"
void entity_counter(t_game *x)
{
	t_coord index;

	index.x = 0;
	index.y = 0;
	while (x->map[index.y])
	{
		index.x = 0;
		while (x->map[index.y][index.x] != '\0')
		{
			if (x->map[index.y][index.x] == 'C')
				x->count_coll++;
			if (x->map[index.y][index.x] == 'M')
				x->count_monster++;
			index.x++;
		}
		index.y++;
	}
	x->monster = malloc (sizeof(t_coord) * x->count_monster);
}
int	so_long(const char *arg)
{
	t_game	x;
	//char	**map;

	x.mapi.x = 0;
    x.mapi.y = 0;
	if (check_map(arg))
	{
		if(map_size_error(arg, &x.mapi) == 0)
			return(printf("%s\n", "mauvaise map :("));
		x.map = maplloc(arg);
		entity_counter(&x);
		printf("%zu\n", x.count_monster);
		init_entity(&x, 'M');
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
