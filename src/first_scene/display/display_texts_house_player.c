/*
** EPITECH PROJECT, 2019
** display_texts_house_player
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_texts_house_player(game_t *game)
{
    texts_t *texts = game->scenes->texts;
    game_object_t *go = game->scenes->objs->game_object;

    for (; texts->prev; texts = texts->prev);
    for (; texts; texts = texts->next) {
        if (texts->type == NAME_BOX || texts->type == TEXT_BOX)
            display_dialog(game, texts);
    }
    for (; go; go = go->next) {
        if (go->type != FIRST_CHEST)
            continue;
        if (go->interaction == true)
            display_msg_in_box(game, "You need to retrieve a key");
    }
}