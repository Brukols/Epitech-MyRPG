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
    sfSprite *sprite;
    sfTexture *texture;

    for (; buttons->prev != NULL; buttons = buttons->prev);
    if (sfClock_getElapsedTime(buttons->clock).microseconds < 600000) {
        sprite = first_play_sprite(game);
        texture = first_play_texture(game);
    }
    if (sfClock_getElapsedTime(buttons->clock).microseconds > 600000) {
        sprite = scnd_play_sprite(game);
        texture = scnd_play_texture(game);
    }
    if (sfClock_getElapsedTime(buttons->clock).microseconds > 120000)
        sfClock_restart(buttons->clock);
    sfSprite_setPosition(sprite, buttons->pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
}
