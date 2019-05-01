/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** change_dialog
*/

#include "my_rpg.h"

void change_quest_pnj(game_t *game, pnj_t *pnj)
{
    if (my_strcmp(pnj->name, "Dobby") == 0)
        change_quest(game, TALK_TO_DOBBY);
    if (my_strcmp(pnj->name, "Freddy") == 0)
        change_quest(game, FIND_THE_KEY);
}

bool change_dialog_pnj(game_t *game, pnj_t *pnj)
{
    if (game->quests->quest != 2 && my_strcmp(pnj->name, "Freddy") == 0) {
        pnj->next_dialog = 0;
        pnj->speak = false;
        return (true);
    }
    pnj->has_talk_with = true;
    if (pnj->discuss[pnj->next_dialog + 1])
        pnj->next_dialog += 2;
    else
        pnj->next_dialog++;
    if (pnj->discuss[pnj->next_dialog] == NULL) {
        pnj->next_dialog = 0;
        pnj->speak = false;
        change_quest_pnj(game, pnj);
    }
    return (true);
}

bool change_dialog(game_t *game)
{
    pnj_t *pnj = game->scenes->objs->pnj;

    for (; pnj; pnj = pnj->next) {
        if (pnj->speak == true)
            return (change_dialog_pnj(game, pnj));
    }
    return (false);
}