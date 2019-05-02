/*
** EPITECH PROJECT, 2019
** display_sheet
** File description:
** my_rpg
*/

#include "my_rpg.h"

int display_leaf(particle_t *particle)
{
    framebuffer_t *frame = particle->frame;
    all_particle_t *all_particle = particle->all_particle;
    sfColor color = {0, 0, 0, 0};

    for (int i = 0; i < 165; i++) {
        for (int a = 0; a < 165; a++)
            my_put_pixel(frame, i, a, color);
    }
    for (; all_particle; all_particle = all_particle->next) {
        my_draw_square(frame, all_particle, 5);
        all_particle->y += all_particle->speed;
        if (all_particle->y < 165)
            continue;
        if (!all_particle->prev && !all_particle->next)
            return (NOTHING);
        if (all_particle->prev)
            all_particle->prev->next = all_particle->next;
        if (all_particle->next)
            all_particle->next->prev = all_particle->prev;
    }
    return (AGAIN);
}