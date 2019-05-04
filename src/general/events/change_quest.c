/*
** EPITECH PROJECT, 2019
** change_quest
** File description:
** my_rpg
*/

#include "my_rpg.h"

void action_at_the_end(game_t *game, enum all_quests_e actual_quest)
{
    player_t *player = game->scenes->objs->player;

    if (actual_quest == FIND_THE_KEY) {
        add_item(player->inventory, 2);
    }
    if (actual_quest == TALK_TO_ARIANA)
        add_item(player->inventory, 13);
}

void change_quest(game_t *game, enum all_quests_e actual_quest)
{
    enum all_quests_e quest = game->quests->quest;

    if (quest == actual_quest) {
        action_at_the_end(game, actual_quest);
        game->quests->quest++;
        game->quests->all_quests++;
    }
}