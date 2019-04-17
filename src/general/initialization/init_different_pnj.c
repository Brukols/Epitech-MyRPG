/*
** EPITECH PROJECT, 2019
** init_different_pnj
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_object_t *freddy(game_object_t *go, int x, int y)
{
    go->pos = init_vec2f(x, y);
    go->type = PNJ;
    go->move_x = 0;
    go->move_y = 0;
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/chara5.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->scale = init_vec2f(1, 1);
    go->rect = init_intrect(312, 0, 78, 108);
    go->hitbox_pos = init_vec2f(x + 12, y + 54);
    go->hitbox_size = init_vec2f(51, 54);
    return (go);
}