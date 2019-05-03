/*
** EPITECH PROJECT, 2019
** go_back_to_first_scene.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void re_initialize_value_house(game_t *game)
{
    game_object_t *player = game->scenes->objs->player->game_object;

    player->move_x = 0;
    player->move_y = 0;
    player->pos.y -= 6;
}

bool go_back_to_first_scene(game_t *game)
{
    game_object_t *player = game->scenes->objs->player->game_object;

    if (player->move_y > 0 && player->pos.y + 155 > 1080 && \
    player->pos.x > 940 && player->pos.x < 1000) {
        re_initialize_value_house(game);
        game->scenes = game->scenes->prev;
        return (true);
    }
    return (false);
}