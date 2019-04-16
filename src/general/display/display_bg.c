/*
** EPITECH PROJECT, 2019
** display_bg
** File description:
** mt_rpg
*/

#include "my_rpg.h"

void display_bg(game_t *game)
{
    background_t *bg = game->scenes->objs->background;

    sfSprite_setPosition(bg->sprite, bg->pos);
    sfSprite_setTexture(bg->sprite, bg->texture, sfFalse);
    sfSprite_setScale(bg->sprite, bg->scale);
    sfRenderWindow_drawSprite(game->window, bg->sprite, NULL);
}
