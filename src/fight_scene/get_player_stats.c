/*
** EPITECH PROJECT, 2019
** get_player_stats.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void get_player_stats(game_t *game)
{
    player_t *p = game->scenes->objs->player;
    player_t *prev_p = game->scenes->prev->prev->objs->player;

    p->hp = prev_p->hp;
    p->attack = prev_p->attack;
    p->power = prev_p->power;
    p->inventory = prev_p->inventory;
}
