/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_butons
*/

#include "my_rpg.h"

void display_box_dialog(game_t *game, buttons_t *buttons)
{
    if (there_is_an_interaction(game) == false)
        return;
    sfSprite_setPosition(buttons->sprite, buttons->pos);
    sfSprite_setTexture(buttons->sprite, buttons->texture, sfFalse);
    sfSprite_setTextureRect(buttons->sprite, buttons->rect);
    sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
}

void display_buttons(game_t *game)
{
    buttons_t *buttons = game->scenes->buttons;

    for (; buttons->prev; buttons = buttons->prev);
    for (; buttons; buttons = buttons->next) {
        if (buttons->type == BOX_DIALOG) {
            display_box_dialog(game, buttons);
            continue;
        }
        sfSprite_setPosition(buttons->sprite, buttons->pos);
        sfSprite_setTexture(buttons->sprite, buttons->texture, sfFalse);
        sfSprite_setTextureRect(buttons->sprite, buttons->rect);
        sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
    }
}