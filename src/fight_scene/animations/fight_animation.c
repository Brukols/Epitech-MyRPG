/*
** EPITECH PROJECT, 2019
** fight_animation.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void fight_animation(game_t *game)
{
    if (game->scenes->objs->player->attacking)
        player_attack_animation(game);
    else if (game->scenes->objs->enemy->attacking)
        enemy_attack_animation(game);
}
