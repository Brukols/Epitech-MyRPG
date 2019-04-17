/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** change_dialog
*/

#include "my_rpg.h"

bool change_dialog_pnj(pnj_t *pnj)
{
    pnj->next_dialog++;
    if (pnj->discuss[pnj->next_dialog] == NULL) {
        pnj->next_dialog = 0;
        pnj->speak = false;
    }
    return (true);
}

bool change_dialog(game_t *game)
{
    pnj_t *pnj = game->scenes->objs->pnj;

    for (; pnj; pnj = pnj->next) {
        if (pnj->speak == true)
            return (change_dialog_pnj(pnj));
    }
    return (false);
}