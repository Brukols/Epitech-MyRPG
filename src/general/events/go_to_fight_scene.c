/*
** EPITECH PROJECT, 2019
** go_to_fight_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

int go_to_fight_scene(game_t *game)
{
    for (; game->scenes->prev; game->scenes = game->scenes->prev);
    for (; game->scenes->scene != FIGHT; game->scenes = \
    game->scenes->next);
    return (GO_TO_FIGHT_SCENE);
}