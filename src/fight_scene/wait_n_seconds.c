/*
** EPITECH PROJECT, 2019
** wait_n_seconds.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int wait_n_seconds(float n)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0;

    if (clock == NULL)
        return (ERROR);
    while (seconds < n) {
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
    }
    sfClock_destroy(clock);
    return (0);
}
