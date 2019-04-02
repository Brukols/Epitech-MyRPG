/*
** EPITECH PROJECT, 2019
** display_first_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void move_player_fs_scene(player_t *player, background_t *bg)
{
    if ((bg->pos.x <= -2470 || player->pos.x < 900) && player->move_x > 0) {
        player->pos.x += 7;
        player->move_x--;
    }
    if ((bg->pos.x >= 0 || player->pos.x > 900) && player->move_x < 0) {
        player->pos.x -= 7;
        player->move_x++;
    }
    if ((bg->pos.y <= -1450 || player->pos.y < 480) && player->move_y > 0) {
        player->pos.y += 7;
        player->move_y--;
    }
    if ((bg->pos.y >= -7 || player->pos.y > 480) && player->move_y < 0) {
        player->pos.y -= 7;
        player->move_y++;
    }
}

void display_player_fs_scene(game_t *game)
{
    player_t *player = game->scenes->objs->player;
    background_t *bg = game->scenes->objs->background;

    move_player_fs_scene(player, bg);
    if (player->move_x || player->move_y) {
        if (sfClock_getElapsedTime(player->clock).microseconds > 100000) {
            player->rect.left += 78;
            sfClock_restart(player->clock);
        }
        if (player->rect.left == 234)
            player->rect.left = 0;
    } else
        player->rect.left = 78;
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
}