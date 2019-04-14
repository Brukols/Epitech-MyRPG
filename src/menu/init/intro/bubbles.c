/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** init bubbles discutions
*/

#include "my_rpg.h"

game_object_t *init_bubble_1(game_object_t *game_object)
{
    game_object->type = INTRO_BUBBLE1;
    game_object->pos.x = 1100;
    game_object->pos.y = 240;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/bulle1.png", NULL);
    return (game_object);
}

game_object_t *init_bubble_2(game_object_t *game_object)
{
    game_object->type = INTRO_BUBBLE2;
    game_object->pos.x = 1100;
    game_object->pos.y = 250;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/bulle2.png", NULL);
    return (game_object);
}

game_object_t *init_bubble_3(game_object_t *game_object)
{
    game_object->type = INTRO_BUBBLE3;
    game_object->pos.x = 460;
    game_object->pos.y = 260;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/bulle3.png", NULL);
    return (game_object);
}

game_object_t *init_bubble_red(game_object_t *game_object)
{
    game_object->type = INTRO_BUBBLE_RED;
    game_object->pos.x = 1100;
    game_object->pos.y = 120;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/bulle4.png", NULL);
    return (game_object);
}
