/*
** EPITECH PROJECT, 2019
** init_quetss
** File description:
** my_rpg
*/

#include "my_rpg.h"

quests_t *init_quests(void)
{
    quests_t *quests = malloc(sizeof(quests_t));

    if (!quests)
        return (NULL);
    if (!(quests->text = sfText_create()))
        return (NULL);
    if (!(quests->font = sfFont_createFromFile(\
        "ressources/font/quest_font.otf")))
        return (NULL);
    quests->pos = init_vec2f(1520, 870);
    quests->arr_quests = init_map("maps/quests");
    quests->quest = 0;
    quests->all_quests = TALK_TO_DOBBY;
    return (quests);
}