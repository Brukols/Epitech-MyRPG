/*
** EPITECH PROJECT, 2019
** init_shaft
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_object_t *init_shaft(game_object_t *go, int x, int y)
{
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/autumn_tileset.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x * 2.3, y * 2.3);
    go->rect = init_intrect(932, 2, 91, 92);
    go->hitbox_pos = init_vec2f(x, y + 40);
    go->hitbox_size = init_vec2f(91, 50);
    go->scale = init_vec2f(2.3, 2.3);
    go->type = SHAFT;
    return (go);
}