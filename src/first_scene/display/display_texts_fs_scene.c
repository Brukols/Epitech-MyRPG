/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_texts_fs_scnee
*/

#include "my_rpg.h"

void display_dialog_fs_scene(game_t *game, texts_t *texts)
{
    pnj_t *pnj = game->scenes->objs->pnj;

    for (; pnj && pnj->speak != true; pnj = pnj->next);
    if (!pnj)
        return;
    if (texts->type == NAME_BOX)
        display_pnj_name(game, texts, pnj);
    else
        display_pnj_dialog(game, texts, pnj);
}

void display_texts_fs_scene(game_t *game)
{
    texts_t *texts = game->scenes->texts;
    game_object_t *go = game->scenes->objs->game_object;

    for (; texts->prev; texts = texts->prev);
    for (; texts; texts = texts->next) {
        if (texts->type == NAME_BOX || texts->type == TEXT_BOX)
            display_dialog_fs_scene(game, texts);
    }
    for (; go; go = go->next) {
        if (go->type != FIRST_CHEST)
            continue;
        if (go->interaction == true)
            display_msg_in_box(game, "You need to retrieve a key");
    }
}