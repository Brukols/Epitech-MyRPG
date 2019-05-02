/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** bed
*/

#include "my_rpg.h"

game_object_t *init_bed(game_object_t *go, int x, int y)
{
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/Houses/interior tileset.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x * 4.3, y * 4.3);
    go->comparison = y * 4.3;
    go->display = true;
    go->rect = init_intrect(613, 256, 23, 32);
    go->hitbox_pos = init_vec2f(x * 4.3, y * 4.3);
    go->hitbox_size = init_vec2f(24 * 4.3, 31 * 4.3);
    go->scale = init_vec2f(4.3, 4.3);
    go->type = BED_HOUSE;
    return (go);
}
