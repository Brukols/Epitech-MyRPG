/*
** EPITECH PROJECT, 2019
** inti_house
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_object_t *init_house_player(game_object_t *go, int x, int y)
{
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/objs_map.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x * 2.3, y * 2.3);
    go->rect = init_intrect(0, 96, 128, 160);
    go->hitbox_pos = init_vec2f(x * 2.3, (y + 40) * 2.3);
    go->hitbox_size = init_vec2f(128 * 2.3, 110 * 2.3);
    go->scale = init_vec2f(2.3, 2.3);
    go->type = HOUSE;
    return (go);
}