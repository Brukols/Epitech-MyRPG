/*
** EPITECH PROJECT, 2019
** animation_shaft
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool animation_shaft(game_t *game, game_object_t *go)
{
    particle_t *particle = game->scenes->objs->particle;

    if (go->type != SHAFT || go->hit == true)
        return (true);
    if (!particle) {
        particle = init_particle(go);
        if (!particle)
            return (true);
        go->hit = true;
        game->scenes->objs->particle = particle;
        return (true);
    }
    for (; particle->next; particle = particle->next);
    if (!(particle->next = init_particle(go)))
        return (false);
    go->hit = true;
    particle->next->prev = particle;
    for (; particle->prev; particle = particle->prev);
    game->scenes->objs->particle = particle;
    return (true);
}