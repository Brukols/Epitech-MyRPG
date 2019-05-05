/*
** EPITECH PROJECT, 2019
** rand_action.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int rand_action(int max)
{
    int nb = 0;

    srand(time(NULL));
    nb = rand() % max + 1;
    printf("%d", nb);
    return (nb);
}

int rand_basic_attack(int nb)
{
    if (nb <= 25)
        return (0);
    else if (nb >= 75)
        return (2);
    else
        return (1);
}
