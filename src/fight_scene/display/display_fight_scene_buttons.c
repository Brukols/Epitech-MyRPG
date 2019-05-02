/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_fight_scene_buttons
*/

#include "my_rpg.h"

void display_fight_scene_buttons(game_t *game)
{
    buttons_t *buttons = game->scenes->buttons;

    for (; buttons->prev; buttons = buttons->prev);
    for (; buttons; buttons = buttons->next) {
        sfSprite_setTextureRect(buttons->sprite, buttons->rect);
        sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
    }
}
