/*
** EPITECH PROJECT, 2019
** actualize_stats_player
** File description:
** my_rpg
*/

#include "my_rpg.h"

void actualize_stats_player(game_t *game, int fd, float level)
{
    scenes_t *scenes = game->scenes;
    player_t *player;

    for (; scenes->prev; scenes = scenes->prev);
    for (; scenes->scene != FIRST_SCENE; scenes = scenes->next);
    player = scenes->objs->player;
    player->attack += player->inventory->items[fd]->atk;
    player->power += player->inventory->items[fd]->pow;
    player->level += level;
}

void delete_stats_player(game_t *game, int fd)
{
    scenes_t *scenes = game->scenes;
    player_t *player;

    for (; scenes->prev; scenes = scenes->prev);
    for (; scenes->scene != FIRST_SCENE; scenes = scenes->next);
    player = scenes->objs->player;
    player->attack -= player->inventory->items[fd]->atk;
    player->power -= player->inventory->items[fd]->pow;
}