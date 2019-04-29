/*
** EPITECH PROJECT, 2019
** ther_is_an_interaction
** File description:
** my_rp
*/

#include "my_rpg.h"

bool there_is_an_interaction(game_t *game)
{
    pnj_t *pnj = game->scenes->objs->pnj;
    game_object_t *go = game->scenes->objs->game_object;

    for (; pnj && pnj->speak != true; pnj = pnj->next);
    if (pnj)
        return (true);
    for (; go; go = go->next) {
        if (go->type != FIRST_CHEST)
            continue;
        if (go->interaction == true)
            return (true);
    }
    return (false);
}