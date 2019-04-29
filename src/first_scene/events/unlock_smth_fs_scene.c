/*
** EPITECH PROJECT, 2019
** unlock_smth
** File description:
** fs_scene
*/

#include "my_rpg.h"

void unlock_chest(game_t *game, char *name)
{
    game_object_t *go = game->scenes->objs->game_object;

    if (my_strcmp(name, "Dobby") == 0)
        for (; go->type != FIRST_CHEST; go = go->next);
    go->display = true;
}

void unlock_chest_fs_scene(game_t *game)
{
    pnj_t *pnj = game->scenes->objs->pnj;

    for (; pnj->prev; pnj = pnj->prev);
    for (; pnj; pnj = pnj->next) {
        if (pnj->speak == false)
            continue;
        unlock_chest(game, pnj->name);
    }
}

void unlock_smth_fs_scene(game_t *game)
{
    unlock_chest_fs_scene(game);
}