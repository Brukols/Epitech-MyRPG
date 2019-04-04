/*
** EPITECH PROJECT, 2019
** display_first_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_player_fs_scene(game_t *game)
{
    //player_t *player = game->scenes->objs->player;
    background_t *bg = game->scenes->objs->background;
    game_object_t *player = game->scenes->objs->player->game_object;

    if (player->move_x || player->move_y) {
        if (sfClock_getElapsedTime(player->clock).microseconds > 120000) {
            player->rect.left += 78;
            sfClock_restart(player->clock);
        }
        if (player->rect.left == 234)
            player->rect.left = 0;
    } else
        player->rect.left = 78;
    /*sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);*/
}