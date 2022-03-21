#include "so_long.h"

void coin_collected(t_game *a)
{
    a->collected = 0;
    if (a->player.x == a->coll.x && a->player.y == a->coll.y)
        a->collected = 1;
}
void    init_entity(t_game *a, char c)
{
    a->monster = malloc(sizeof(t_coord) * a->count_monster);

}