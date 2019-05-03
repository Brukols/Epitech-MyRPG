/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** calcul_attack
*/

#include "my_rpg.h"

void calcul_attack(player_t *hunter, player_t *target, int type)
{
    if (type == 0)
        target->pv -= hunter->attack;
    else
        target->pv -= hunter->power;
    if (target->pv < 0)
        target->pv = 0;
}
