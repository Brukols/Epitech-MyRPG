/*
** EPITECH PROJECT, 2019
** display_quests
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_quests(game_t *game)
{
    quests_t *quest = game->quests;

    sfText_setCharacterSize(quest->text, 90);
    sfText_setFont(quest->text, quest->font);
    sfText_setPosition(quest->text, quest->pos);
    sfText_setColor(quest->text, sfBlack);
    sfText_setString(quest->text, quest->arr_quests[quest->quest]);
    sfRenderWindow_drawText(game->window, quest->text, NULL);
}