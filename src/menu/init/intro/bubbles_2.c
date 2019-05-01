/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** display bubbles
*/

#include "my_rpg.h"

game_object_t *init_bubble_red(game_object_t *game_object)
{
    game_object->type = INTRO_BUBBLE_RED;
    game_object->pos.x = 1100;
    game_object->pos.y = 120;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "ressources/sprites/intro/bulle4.png", NULL);
    return (game_object);
}