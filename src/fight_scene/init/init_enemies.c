/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init_enemies
*/

#include "my_rpg.h"

enemies_t **one(enemies_t **enemies)
{

}

void init_enemies(static enemies_t **enemies, int quest)
{
    int *tab = {4};
    int nb = 0;
    enemies_t **(*create_enemies[])() = {one, two, three};

    while (tab[nb] != quest)
        nb++;
    enemies = create_enemies[nb](enemies);
}
