/*
** EPITECH PROJECT, 2019
** display_wind
** File description:
** my_rpg
*/

#include "my_rpg.h"

int display_wind(particle_t *particle)
{
    all_particle_t *all = particle->all_particle;

    all->x += all->speed;
    if (all->x < 1920)
        return (AGAIN);
    all->x = rand() % 1920 - 1920;
    all->y = rand() % 1080;
    all->speed = rand() % 20 + 20;
    return (AGAIN);
}