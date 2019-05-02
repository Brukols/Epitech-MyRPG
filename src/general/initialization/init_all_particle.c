/*
** EPITECH PROJECT, 2019
** int_all_particle
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_color_particle(all_particle_t *all_particle)
{
    int x = rand() % 145;
    int y = rand() % 95;

    all_particle->x = x;
    all_particle->y = y;
    all_particle->speed = rand() % 2 + 1;
    if (y < 10)
        all_particle->color = init_color(245, 208, 95, 255);
    if (y < 20 && y >= 10)
        all_particle->color = init_color(209, 177, 81, 255);
    if (y < 30 && y >= 20)
        all_particle->color = init_color(163, 116, 75, 255);
    if (y < 50 && y >= 30)
        all_particle->color = init_color(137, 85, 64, 255);
    if (y < 95 && y >= 50)
        all_particle->color = init_color(104, 62, 68, 255);
}

all_particle_t *init_all_particle(void)
{
    all_particle_t *all_particle = malloc(sizeof(all_particle_t));

    if (!all_particle)
        return (NULL);
    all_particle->prev = NULL;
    for (int i = 0; i < 30; i++) {
        init_color_particle(all_particle);
        if (i == 29)
            break;
        all_particle->next = malloc(sizeof(all_particle_t));
        if (!all_particle->next)
            return (NULL);
        all_particle->next->prev = all_particle;
        all_particle = all_particle->next;
    }
    all_particle->next = NULL;
    for (; all_particle->prev; all_particle = all_particle->prev);
    return (all_particle);
}
