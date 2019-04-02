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
    "../../ressources/sprites/menu/play.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 800;
    button->pos.y = 800;
    button->clock = sfClock_create();
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    return (button);
}

buttons_t *button_play2(buttons_t *button)
{
    button->type = START_2;
    button->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/menu/play_2.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 800;
    button->pos.y = 800;
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    return (button);
}
