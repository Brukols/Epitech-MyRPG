/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** calcul_attack
*/

#include "my_rpg.h"

void calcul_basic_attack(int attack_status, game_t *game)
{
    if (attack_status == 1)
        game->scenes->objs->enemy->hp -= game->scenes->objs->player->attack;
    else if (attack_status == 2)
        game->scenes->objs->enemy->hp -= game->scenes->objs->player->attack * 2;
    if (game->scenes->objs->enemy->hp < 0)
        game->scenes->objs->enemy->hp = 0;
}

void calcul_magic_attack(game_t *game)
{
    game->scenes->objs->enemy->hp -= game->scenes->objs->player->power;
    if (game->scenes->objs->enemy->hp < 0)
        game->scenes->objs->enemy->hp = 0;
}
