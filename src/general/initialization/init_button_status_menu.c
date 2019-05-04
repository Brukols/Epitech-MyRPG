/*
** EPITECH PROJECT, 2019
** init_buttons_status_menu
** File description:
** my_rpg
*/

#include "my_rpg.h"

int display_status(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->type != BUTTON_STATUS_MENU; button = button->next);
    button->display = false;
    for (; button->prev; button = button->prev);
    for (; button->type != STATUS_MENU; button = button->next);
    button->display = true;
    return (SUCCESS);
}

buttons_t *init_button_status_menu(buttons_t *button)
{
    button->type = BUTTON_STATUS_MENU;
    button->display = true;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/emote5.png", NULL);
    button->sprite = sfSprite_create();
    button->pos = init_vec2f(10, 10);
    button->size = init_vec2f(78, 108);
    button->rect = init_intrect(156, 216, 78, 108);
    button->hitbox_pos = init_vec2f(10, 10);
    button->callback = &display_status;
    return (button);
}