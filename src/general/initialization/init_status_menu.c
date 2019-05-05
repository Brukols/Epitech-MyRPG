/*
** EPITECH PROJECT, 2019
** init_status_menu
** File description:
** my_rpg
*/

#include "my_rpg.h"

int display_button_status(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->type != STATUS_MENU; button = button->next);
    button->display = false;
    for (; button->prev; button = button->prev);
    for (; button->type != BUTTON_STATUS_MENU; button = button->next);
    button->display = true;
    return (SUCCESS);
}

buttons_t *init_status_menu(buttons_t *button)
{
    button->type = STATUS_MENU;
    button->display = false;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/stats_menu.png", NULL);
    button->sprite = sfSprite_create();
    button->pos = init_vec2f(70, 10);
    button->size = init_vec2f(376, 531);
    button->rect = init_intrect(0, 0, 376, 531);
    button->hitbox_pos = init_vec2f(70, 10);
    button->callback = &display_button_status;
    if (!button->sprite || !button->texture)
        return (NULL);
    return (button);
}