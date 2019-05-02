/*
** EPITECH PROJECT, 2019
** touch_wall_shouse
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool touch_walls_house(game_t *game)
{
    game_object_t *player = game->scenes->objs->player->game_object;

    if (player->move_x > 0 && player->pos.x + 5 > 1300)
        return (true);
    if (player->move_x < 0 && player->pos.x - 5 < 580)
        return (true);
    if (player->move_y > 0 && player->pos.y + 155 > 1080)
        return (true);
    if (player->move_y < 0 && player->pos.y - 5 < 180)
        return (true);
    return (false);
}