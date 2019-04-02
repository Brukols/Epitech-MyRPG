/*
** EPITECH PROJECT, 2019
** display_bg_fs_scene
** File description:
** mt_rpg
*/

#include "my_rpg.h"

void move_bg(background_t *bg, player_t *player)
{
    if (bg->move_x > 0 && bg->pos.x > -2470 && player->pos.x >= 900) {
        bg->pos.x -= 7;
        bg->move_x--;
        player->move_x--;
    }
    if (bg->move_x < 0 && bg->pos.x < 0 && player->pos.x <= 900) {
        bg->pos.x += 7;
        bg->move_x++;
        player->move_x++;
    }
    if (bg->move_y > 0 && bg->pos.y > -1450 && player->pos.y >= 480) {
        bg->pos.y -= 7;
        bg->move_y--;
        player->move_y--;
    }
    if (bg->move_y < 0 && bg->pos.y < -7 && player->pos.y <= 480) {
        bg->pos.y += 7;
        bg->move_y++;
        player->move_y++;
    }
}

void display_bg_fs_scene(game_t *game)
{
    background_t *bg = game->scenes->objs->background;
    player_t *player = game->scenes->objs->player;

    move_bg(bg, player);
    sfSprite_setPosition(bg->sprite, bg->pos);
    sfSprite_setTexture(bg->sprite, bg->texture, sfFalse);
    sfSprite_setScale(bg->sprite, bg->scale);
    sfRenderWindow_drawSprite(game->window, bg->sprite, NULL);
}