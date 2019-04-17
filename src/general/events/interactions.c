/*
** EPITECH PROJECT, 2019
** interaction
** File description:
** my_rog
*/

#include "my_rpg.h"

bool is_ready_to_talk(game_object_t *go, sfVector2f pos_player)
{
    if (pos_player.x + 35 > go->pos.x && pos_player.x + 35 < \
        go->pos.x + go->hitbox_size.x && pos_player.y - 35 > go->pos.y && \
        pos_player.y - 35 < go->pos.y + go->hitbox_size.y)
        return (true);
    return (false);
}

void new_dialog(game_t *game, sfVector2f pos_player)
{
    pnj_t *pnj = game->scenes->objs->pnj;

    for (; pnj; pnj = pnj->next) {
        if (is_ready_to_talk(pnj->game_object, pos_player) == true) {
            pnj->speak = true;
            return;
        }
    }
}

void interactions(game_t *game, sfKeyCode code)
{
    player_t *player = game->scenes->objs->player;

    if (code == sfKeyReturn) {
        if (change_dialog(game) == true)
            return;
        new_dialog(game, player->game_object->pos);
    }
}