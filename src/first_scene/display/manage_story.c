/*
** EPITECH PROJECT, 2019
** end_of_the_story
** File description:
** my_tpg
*/

#include "my_rpg.h"

void manage_story(game_t *game)
{
    static int i = 0;
    pnj_t *pnj = game->scenes->objs->pnj;

    if (game->quests->all_quests == FIND_THE_LEADER && i == 0) {
        for (; pnj && my_strcmp(pnj->name, "Leader") != 0; pnj = pnj->next);
        if (!pnj)
            return;
        pnj->game_object->pos = init_vec2f(-600, 400);
        pnj->game_object->hitbox_pos = init_vec2f(-600 + 12, 400 + 54);
        i++;
    }
    if (game->quests->all_quests == SAVE_LUCY)
        end_game(game);
}