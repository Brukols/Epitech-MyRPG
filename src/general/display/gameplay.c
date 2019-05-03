/*
** EPITECH PROJECT, 2019
** game_play
** File description:
** my_rpg
*/

#include "my_rpg.h"

int gameplay(game_t *game)
{
    pnj_t *pnj = game->scenes->objs->pnj;

    if (game->quests->all_quests == TRAINING) {
        for (; my_strcmp("Zoro", pnj->name) != 0; pnj = pnj->next);
        move_zoro(game, game->scenes->objs->player, pnj);
    }
    return (SUCCESS);
}