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
    go->pos = init_vec2f(x * 2.3, y * 2.3);
    go->comparison = y * 2.3;
    go->rect = init_intrect(612, 256, 24, 22); //22 a changer
    go->hitbox_pos = init_vec2f(x * 2.3, (y + 15) * 2.3);
    go->hitbox_size = init_vec2f(24 * 2.3, 31 * 2.3);
    go->scale = init_vec2f(2.3, 2.3);
    go->type = BED_HOUSE;
    return (go);
}
