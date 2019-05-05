/*
** EPITECH PROJECT, 2019
** move_the_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void change_position_scene_up_and_down(player_t *player, \
background_t *bg, sfKeyCode code, bool move)
{
    if (code == sfKeyDown) {
        bg->move_y = (move ? 1 : 0);
        bg->move_x = 0;
        player->game_object->move_y = (move ? 1 : 0);
        player->game_object->move_x = 0;
        player->game_object->rect.top = player->down;
        return;
    }
    if (code == sfKeyUp) {
        bg->move_y = (move ? -1 : 0);
        bg->move_x = 0;
        player->game_object->move_y = (move ? -1 : 0);
        player->game_object->move_x = 0;
        player->game_object->rect.top = player->up;
        return;
    }
}

void change_position_scene(player_t *player, background_t *bg, sfKeyCode code,
bool move)
{
    if (code == sfKeyRight) {
        bg->move_x = (move ? 1 : 0);
        bg->move_y = 0;
        player->game_object->move_x = (move ? 1 : 0);
        player->game_object->move_y = 0;
        player->game_object->rect.top = player->right;
        return;
    }
    if (code == sfKeyLeft) {
        bg->move_x = (move ? -1 : 0);
        bg->move_y = 0;
        player->game_object->move_x = (move ? -1 : 0);
        player->game_object->move_y = 0;
        player->game_object->rect.top = player->left;
        return;
    }
    change_position_scene_up_and_down(player, bg, code, move);
}

void move_the_scene(game_t *game, sfKeyCode code, bool move)
{
    background_t *bg = game->scenes->objs->background;
    player_t *player = game->scenes->objs->player;

    if (game->quests->all_quests == TRAINING) {
        bg->move_x = 0;
        bg->move_y = 0;
        player->game_object->move_x = 0;
        player->game_object->move_y = 0;
        return;
    }
    if (there_is_an_interaction(game) == true)
        return;
    change_position_scene(player, bg, code, move);
}
