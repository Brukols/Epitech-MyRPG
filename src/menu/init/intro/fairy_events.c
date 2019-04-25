/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** fairy and interrogation
*/

#include "my_rpg.h"

game_object_t *init_fairy(game_object_t *game_object)
{
    game_object->type = INTRO_FAIRY;
    game_object->pos.x = 950;
    game_object->pos.y = 420;
    game_object->rect.top = 0;
    game_object->rect.left = 0;
    game_object->rect.width = 160;
    game_object->rect.height = 250;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "ressources/sprites/intro/fée.png", NULL);
    return (game_object);
}

game_object_t *init_interrogation(game_object_t *game_object)
{
    game_object->type = INTRO_INTERROGATION;
    game_object->pos.x = 990;
    game_object->pos.y = 350;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "ressources/sprites/intro/?.png", NULL);
    return (game_object);
}
