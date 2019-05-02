/*
** EPITECH PROJECT, 2019
** init_wind_particle
** File description:
** my_rpg
*/

#include "my_rpg.h"

all_particle_t *init_wind(void)
{
    all_particle_t *all_particle = malloc(sizeof(all_particle_t));

    if (!all_particle)
        return (NULL);
    all_particle->speed = rand() % 20 + 20;
    all_particle->y = rand() % 1080;
    all_particle->x = rand() % 1920 - 1920;
    all_particle->color = init_color(128, 128, 128, 100);
    all_particle->next = NULL;
    all_particle->prev = NULL;
    return (all_particle);
}

void complete_frame(particle_t *particle)
{
    all_particle_t *all = particle->all_particle;
    sfColor color = {0, 0, 0, 0};

    for (int i = 0; i < 2; i++) {
        for (int a = 0; a < 100; a++)
            (rand() % 3 == 0 ? my_put_pixel(particle->frame, a, i, color) : \
            my_put_pixel(particle->frame, a, i, all->color));
    }
}

particle_t *init_all_wind(particle_t *particle)
{
    particle->type = WIND;
    if (!(particle->texture = sfTexture_create(100, 2)))
        return (NULL);
    if (!(particle->sprite = sfSprite_create()))
        return (NULL);
    if (!(particle->frame = create_framebuffer(100, 2)))
        return (NULL);
    if (!(particle->all_particle = init_wind()))
        return (NULL);
    complete_frame(particle);
    particle->game_object = NULL;
    return (particle);
}

particle_t *init_wind_particle(void)
{
    particle_t *particle = malloc(sizeof(particle_t));

    if (!particle)
        return (NULL);
    particle->prev = NULL;
    for (int i = 0; i < 10; i++) {
        if (!(particle = init_all_wind(particle)))
            return (NULL);
        if (i == 9)
            break;
        if (!(particle->next = malloc(sizeof(particle_t))))
            return (NULL);
        particle->next->prev = particle;
        particle = particle->next;
    }
    particle->next = NULL;
    for (; particle->prev; particle = particle->prev);
    return (particle);
}