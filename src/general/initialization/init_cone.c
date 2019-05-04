/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init_cone
*/

#include "my_rpg.h"

game_object_t *init_cone(game_object_t *go, int x, int y)
{
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/autumn_tileset.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x * 2.3, y * 2.3);
    go->comparison = y * 2.3 + 50;
    go->rect = init_intrect(1040, 0, 50, 94);
    go->hitbox_pos = init_vec2f(x * 2.3, (y + 60) * 2.3);
    go->hitbox_size = init_vec2f(40 * 2.3, 40 * 2.3);
    go->scale = init_vec2f(2.3, 2.3);
    go->type = CONE;
    go->display = true;
    go->hit = false;
    return (go);
}
