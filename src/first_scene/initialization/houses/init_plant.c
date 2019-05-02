/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** plant
*/

#include "my_rpg.h"

game_object_t *init_plant(game_object_t *go, int x, int y)
{
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/Houses/interior tileset.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x * 4.3, y * 4.3);
    go->comparison = y * 4.3;
    go->display = true;
    go->rect = init_intrect(620, 197, 13, 19);
    go->hitbox_pos = init_vec2f(x * 4.3, (y + 3) * 4.3);
    go->hitbox_size = init_vec2f(18 * 4.3, 18 * 4.3);
    go->scale = init_vec2f(4.3, 4.3);
    go->type = PLANT_HOUSE;
    return (go);
}
