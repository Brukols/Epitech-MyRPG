/*
** EPITECH PROJECT, 2019
** init bottoms (exit + setting buttons)
** File description:
** my rpg
*/

#include "my_rpg.h"

buttons_t *setting_button(buttons_t *button)
{
    button->type = MENU_SETTINGS;
    button->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/menu/settings.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 1770;
    button->pos.y = 900;
    return (button);
}

buttons_t *exit_button(buttons_t *button)
{
    button->type = MENU_EXIT;
    button->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/menu/exit.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 1650;
    button->pos.y = 900;
    return (button);
}
