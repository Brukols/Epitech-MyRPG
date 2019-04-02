/*
** EPITECH PROJECT, 2019
** move_the_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void change_position_scene(player_t *player, background_t *bg, sfKeyCode code)
{
    if (code == sfKeyRight) {
        bg->move_x = 3;
        player->move_x = 3;
        player->rect.top = 216;
    }
    if (code == sfKeyLeft) {
        bg->move_x = -3;
        player->move_x = -3;
        player->rect.top = 108;
    }
    if (code == sfKeyDown) {
        bg->move_y = 3;
        player->move_y = 3;
        player->rect.top = 0;
    }
    if (code == sfKeyUp) {
        bg->move_y = -3;
        player->move_y = -3;
        player->rect.top = 324;
    }
}

void move_the_scene(game_t *game, sfKeyCode code)
{
    background_t *bg = game->scenes->objs->background;
    player_t *player = game->scenes->objs->player;

    if (code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    change_position_scene(player, bg, code);
}