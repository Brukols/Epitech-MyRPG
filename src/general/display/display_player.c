/*
** EPITECH PROJECT, 2019
** display_first_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_player(game_t *game)
{
    game_object_t *player = game->scenes->objs->player->game_object;

    if (player->move_x || player->move_y) {
        if (sfClock_getElapsedTime(player->clock).microseconds > 120000) {
            player->rect.left += 78;
            sfClock_restart(player->clock);
        }
        if (player->rect.left == 234)
            player->rect.left = 0;
    } else
        player->rect.left = 78;
}
