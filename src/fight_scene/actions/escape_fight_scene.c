/*
** EPITECH PROJECT, 2019
** escape_fight_scene.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int escape_fight_scene(game_t *game)
{
    int escape_status = rand_action(5, 1);

    if (escape_status == 1) {
        go_back_to_first_scene(game);
    } else {
        sfText_setString(game->scenes->texts->text, \
        "PLAYER tries to escape: it failed!");
    }
    return (0);
}
