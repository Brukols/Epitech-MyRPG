/*
** EPITECH PROJECT, 2019
** display_bg_fs_scene
** File description:
** mt_rpg
*/

#include "my_rpg.h"

void display_bg_fs_scene(game_t *game)
{
    background_t *bg = game->scenes->objs->background;
    player_t *player = game->scenes->objs->player;

    sfSprite_setPosition(bg->sprite, bg->pos);
    sfSprite_setTexture(bg->sprite, bg->texture, sfFalse);
    sfSprite_setScale(bg->sprite, bg->scale);
    sfRenderWindow_drawSprite(game->window, bg->sprite, NULL);
}