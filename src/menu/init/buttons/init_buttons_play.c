/*
** EPITECH PROJECT, 2019
** inits play butons sprites
** File description:
** rpg
*/

#include "my_rpg.h"

buttons_t *button_play(buttons_t *button)
{
    button->type = START;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/menu/buttonplay1.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 750;
    button->pos.y = 450;
    button->clock = sfClock_create();
    return (button);
}

buttons_t *button_play2(buttons_t *button)
{
    button->type = START_2;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/menu/buttonplay2.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 750;
    button->pos.y = 450;
    button->clock = sfClock_create();
    return (button);
}
