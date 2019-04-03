/*
** EPITECH PROJECT, 2019
** display buttons
** File description:
** rpg
*/

#include "my_rpg.h"

void display_play_button(game_t *game)
{
    buttons_t *buttons = game->scenes->buttons;

    for (; buttons->prev != NULL; buttons = buttons->prev);
    if (sfClock_getElapsedTime(buttons->clock).microseconds < 600000) {
        for (; buttons->type != START; buttons = buttons->next);
    }
    if (sfClock_getElapsedTime(buttons->clock).microseconds > 600000) {
        if (sfClock_getElapsedTime(buttons->clock).microseconds > 1200000)
            sfClock_restart(buttons->clock);
        for (; buttons->type != START_2; buttons = buttons->next);
    }
    sfSprite_setPosition(buttons->sprite, buttons->pos);
    sfSprite_setTexture(buttons->sprite, buttons->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
}
