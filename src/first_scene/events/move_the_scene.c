/*
** EPITECH PROJECT, 2019
** move_the_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void change_position_scene(game_object_t *player, background_t *bg, sfKeyCode code,
bool move)
{
    if (code == sfKeyRight) {
        bg->move_x = (move ? 1 : 0);
        player->move_x = (move ? 1 : 0);
        player->rect.top = 216;
    }
    if (code == sfKeyLeft) {
        bg->move_x = (move ? -1 : 0);
        player->move_x = (move ? -1 : 0);
        player->rect.top = 108;
    }
    if (code == sfKeyDown) {
        bg->move_y = (move ? 1 : 0);
        player->move_y = (move ? 1 : 0);
        player->rect.top = 0;
    }
    if (code == sfKeyUp) {
        bg->move_y = (move ? -1 : 0);
        player->move_y = (move ? -1 : 0);
        player->rect.top = 324;
    }
}

void move_the_scene(game_t *game, sfKeyCode code, bool move)
{
    background_t *bg = game->scenes->objs->background;
    //player_t *player = game->scenes->objs->player;
    game_object_t *player = game->scenes->objs->player->game_object;

    if (code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    change_position_scene(player, bg, code, move);
}