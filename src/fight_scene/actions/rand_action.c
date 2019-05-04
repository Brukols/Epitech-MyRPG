/*
** EPITECH PROJECT, 2019
** rand_action.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int rand_action(int max, int limit)
{
    int nb = 0;

    srand(time(NULL));
    nb = rand() % max;
    if (nb > limit)
        return (0);
    else if (nb == max)
        return (1);
    else
        return (2);
}
