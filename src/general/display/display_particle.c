/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_particle
*/

#include "my_rpg.h"

int refresh_frame(particle_t *particle)
{
    if (particle->type == LEAF)
        return (display_leaf(particle));
    return (display_wind(particle));
}

int display_frame(particle_t *particle, particle_t **tmp, sfVector2f pos)
{
    if (refresh_frame(particle) != NOTHING) {
        sfTexture_updateFromPixels(particle->texture, particle->frame->pixels,
        particle->frame->width, particle->frame->height, 0, 0);
        sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
        sfSprite_setPosition(particle->sprite, pos);
        return (DISPLAY);
    }
    particle->game_object->hit = false;
    particle->game_object = NULL;
    if (!particle->prev && !particle->next)
        return (STOP);
    if (particle->prev) {
        (*tmp) = particle->prev;
        particle->prev->next = particle->next;
    }
    if (particle->next) {
        (*tmp) = particle->next;
        particle->next->prev = particle->prev;
    }
    return (CONTINUE);
}

sfVector2f init_pos_frame(particle_t *particle)
{
    if (particle->type == LEAF)
        return (init_vec2f(particle->game_object->hitbox_pos.x + 33, \
        particle->game_object->hitbox_pos.y - 45));
    return (init_vec2f(particle->all_particle->x, particle->all_particle->y));
}

particle_t *display_particle(game_t *game)
{
    particle_t *particle = game->scenes->objs->particle;
    particle_t *tmp = particle;
    sfVector2f pos;
    int verif;

    for (; particle; particle = particle->next) {
        if (!particle->game_object && particle->type != WIND)
            continue;
        pos = init_pos_frame(particle);
        verif = display_frame(particle, &tmp, pos);
        if (verif == STOP)
            return (NULL);
        if (verif == CONTINUE)
            continue;
        sfRenderWindow_drawSprite(game->window, particle->sprite, NULL);
    }
    if (!tmp)
        return (NULL);
    for (; tmp->prev; tmp = tmp->prev);
    return (tmp);
}