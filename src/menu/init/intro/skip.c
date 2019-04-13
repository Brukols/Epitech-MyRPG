/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init skip button
*/

#include "my_rpg.h"

game_object_t *init_skip1(game_object_t *game_object)
{
    game_object->type = INTRO_SKIP1;
    game_object->pos.x = 1700;
    game_object->pos.y = 820;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/skip1.png", NULL);
    return (game_object);
}

game_object_t *init_skip2(game_object_t *game_object)
{
    game_object->type = INTRO_SKIP2;
    game_object->pos.x = 1700;
    game_object->pos.y = 820;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/skip2.png", NULL);
    return (game_object);
}
