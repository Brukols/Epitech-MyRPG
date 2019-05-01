/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_particle
*/

#include "my_rpg.h"

int refresh_frame(particle_t *particle)
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

particle_t *display_particle(game_t *game)
{
    particle_t *particle = game->scenes->objs->particle;
    particle_t *tmp = particle;
    sfVector2f pos;
    int verif;

    for (; particle; particle = particle->next) {
        if (!particle->game_object)
            continue;
        pos = init_vec2f(particle->game_object->hitbox_pos.x + 33, \
        particle->game_object->hitbox_pos.y - 45);
        verif = display_frame(particle, &tmp, pos);
        if (verif == STOP)
            return (NULL);
        if (verif == CONTINUE)
            continue;
        sfRenderWindow_drawSprite(game->window, particle->sprite, NULL);
    }
    if (!tmp)
        return (NULL);
    for (; tmp->prev; particle = particle->prev);
    return (tmp);
}