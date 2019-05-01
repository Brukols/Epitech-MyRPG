/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_particle
*/

#include "my_rpg.h"

framebuffer_t *create_framebuffer(int width, int height)
{
    framebuffer_t *frame = malloc(sizeof(framebuffer_t));

    if (!frame)
        return (NULL);
    frame->width = width;
    frame->height = height;
    frame->pixels = malloc(sizeof(sfUint8) * (width * height * 4));
    if (!frame->pixels)
        return (NULL);
    return (frame);
}

particle_t *init_particle(game_object_t *go)
{
    particle_t *particle = malloc(sizeof(particle_t));

    if (!particle)
        return (NULL);
    particle->prev = NULL;
    particle->next = NULL;
    particle->sprite = sfSprite_create();
    if (!particle->sprite)
        return (NULL);
    particle->texture = sfTexture_create(145, 165);
    if (!particle->texture)
        return (NULL);
    particle->frame = create_framebuffer(145, 165);
    if (!particle->frame)
        return (NULL);
    particle->all_particle = init_all_particle();
    particle->game_object = go;
    return (particle);
}