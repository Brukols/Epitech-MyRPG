/*
** EPITECH PROJECT, 2019
** display_fight_scene_objs.c
** File description:
** display_fight_scene_objs.c
*/

#include "my_rpg.h"

void display_fight_scene_objs(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, \
    game->scenes->objs->background->sprite, \
    NULL);
    sfRenderWindow_drawSprite(game->window, \
    game->scenes->objs->game_object->sprite, \
    NULL);
}
