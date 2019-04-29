/*
** EPITECH PROJECT, 2019
** quest
** File description:
** my_rpg
*/

#ifndef QUESTS_H
#define QUESTS_H

#include "my_rpg.h"

enum all_quests_e {
    TALK_TO_DOBBY = 0,
    FIND_A_CHEST,
    FIND_THE_KEY,
    OPEN_THE_CHEST
};

typedef struct quests_s {
    int quest;
    enum all_quests_e all_quests;
    char **arr_quests;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
} quests_t;

#endif