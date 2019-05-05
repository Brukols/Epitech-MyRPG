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

    if (game->quests->all_quests == TRAINING || \
    game->quests->all_quests == TALK_TO_ARIANA) {
        for (; my_strcmp("Zoro", pnj->name) != 0; pnj = pnj->next);
        move_zoro(game, game->scenes->objs->player, pnj);
    }
    if (game->quests->all_quests == FIGHT_THE_MASTER || \
    game->quests->all_quests == FIND_A_SECOND_CHEST) {
        for (; my_strcmp("Master", pnj->name) != 0; pnj = pnj->next);
        move_the_master(game, pnj);
    }
    return (SUCCESS);
}