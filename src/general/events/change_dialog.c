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
    if (my_strcmp(pnj->name, "Ariana") == 0)
        change_quest(game, TALK_TO_ARIANA);
    if (my_strcmp(pnj->name, "Guard") == 0)
        change_quest(game, TALK_TO_THE_GUARD);
}

bool stop_dialog(game_t *game, pnj_t *pnj)
{
    if (game->quests->quest != 2 && my_strcmp(pnj->name, "Freddy") == 0)
        return (true);
    if (game->quests->quest != 4 && my_strcmp(pnj->name, "Zoro") == 0)
        return (true);
    if (game->quests->quest != 5 && my_strcmp(pnj->name, "Ariana") == 0)
        return (true);
    if (game->quests->quest != 8 && my_strcmp(pnj->name, "Guard") == 0)
        return (true);
    if (game->quests->quest != 9 && my_strcmp(pnj->name, "Joker") == 0)
        return (true);
    return (false);
}

int check_event_fight(game_t *game, pnj_t *pnj)
{
    if (my_strcmp(pnj->name, "Zoro") == 0 && game->quests->all_quests == \
TRAINING)
        return (go_to_fight_scene(game));
    if (my_strcmp(pnj->name, "Master") == 0 && game->quests->all_quests == \
FIGHT_THE_MASTER)
        return (go_to_fight_scene(game));
    if (my_strcmp(pnj->name, "Joker") == 0 && game->quests->all_quests == \
FIGHT_THE_JOKER)
        return (go_to_fight_scene(game));
    if (my_strcmp(pnj->name, "Leader") == 0 && game->quests->all_quests == \
FIND_THE_LEADER)
        return (go_to_fight_scene(game));
    return (SUCCESS);
}

int change_dialog_pnj(game_t *game, pnj_t *pnj)
{
    if (stop_dialog(game, pnj) == true) {
        re_init_pnj_dialog(pnj);
        stop_music_voice(game, pnj);
        return (SUCCESS);
    }
    pnj->has_talk_with = true;
    if (pnj->discuss[pnj->next_dialog + 1])
        pnj->next_dialog += 2;
    else
        pnj->next_dialog++;
    if (pnj->discuss[pnj->next_dialog] == NULL) {
        pnj->next_dialog = 0;
        pnj->speak = false;
        pnj->game_object->rect.top = pnj->game_object->stock_top;
        stop_music_voice(game, pnj);
        change_quest_pnj(game, pnj);
        return (check_event_fight(game, pnj));
    } else
        play_music_voice(game, pnj);
    return (SUCCESS);
}

int change_dialog(game_t *game)
{
    pnj_t *pnj = game->scenes->objs->pnj;

    for (; pnj; pnj = pnj->next) {
        if (pnj->speak == true)
            return (change_dialog_pnj(game, pnj));
    }
    return (FAILURE);
}