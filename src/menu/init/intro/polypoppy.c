/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init polypoppy
*/

#include "my_rpg.h"

game_object_t *init_polipoppy_walk(game_object_t *game_object)
{
    game_object->type = INTRO_KING_WALK;
    game_object->pos.x = -50;
    game_object->pos.y = 420;
    game_object->rect.top = 0;
    game_object->rect.left = 70;
    game_object->rect.width = 70;
    game_object->rect.height = 280;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "ressources/sprites/intro/walkandsurprise.png", NULL);
    return (game_object);
}

game_object_t *init_polipoppy_surprise(game_object_t *game_object)
{
    game_object->type = INTRO_KING_SURPRISE;
    game_object->pos.x = 800;
    game_object->pos.y = 420;
    game_object->rect.top = 0;
    game_object->rect.left = 280;
    game_object->rect.width = 80;
    game_object->rect.height = 300;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "ressources/sprites/intro/walkandsurprise.png", NULL);
    return (game_object);
}
