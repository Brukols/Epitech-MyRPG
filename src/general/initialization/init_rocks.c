/*
** EPITECH PROJECT, 2019
** init_rocks
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_object_t *init_rock(game_object_t *go, int x, int y)
{
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/autumn_tileset.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x * 2.3, y * 2.3);
    go->rect = init_intrect(705, 132, 62, 55);
    go->hitbox_pos = init_vec2f(x * 2.3, (y + 20) * 2.3);
    go->hitbox_size = init_vec2f(62 * 2.3, 35 * 2.3);
    go->scale = init_vec2f(2.3, 2.3);
    go->type = HOUSE;
    return (go);
}