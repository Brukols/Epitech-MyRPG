/*
** EPITECH PROJECT, 2019
** move_the_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void change_position_scene(player_t *player, background_t *bg, sfKeyCode code,
bool move)
{
    if (code == sfKeyRight) {
        bg->move_x = (move ? 1 : 0);
        player->game_object->move_x = (move ? 1 : 0);
        player->game_object->rect.top = player->right;
    }
    if (code == sfKeyLeft) {
        bg->move_x = (move ? -1 : 0);
        player->game_object->move_x = (move ? -1 : 0);
        player->game_object->rect.top = player->left;
    }
    if (code == sfKeyDown) {
        bg->move_y = (move ? 1 : 0);
        player->game_object->move_y = (move ? 1 : 0);
        player->game_object->rect.top = player->down;
    }
    if (code == sfKeyUp) {
        bg->move_y = (move ? -1 : 0);
        player->game_object->move_y = (move ? -1 : 0);
        player->game_object->rect.top = player->up;
    }
}

void move_the_scene(game_t *game, sfKeyCode code, bool move)
{
    background_t *bg = game->scenes->objs->background;
    player_t *player = game->scenes->objs->player;

    if (code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    change_position_scene(player, bg, code, move);
}
