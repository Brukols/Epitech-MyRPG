/*
** EPITECH PROJECT, 2019
** init_chest
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_object_t *init_first_chest(game_object_t *go, int x, int y)
{
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/chests.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x * 2.3, y * 2.3);
    go->comparison = y * 2.3 - 42;
    go->rect = init_intrect(389, 18, 19, 18);
    go->hitbox_pos = init_vec2f(x * 2.3, (y + 5) * 2.3);
    go->hitbox_size = init_vec2f(19 * 2.3, 13 * 2.3);
    go->scale = init_vec2f(2.3, 2.3);
    go->display = false;
    go->type = FIRST_CHEST;
    go->interaction = false;
    go->open = false;
    go->item = 0;
    return (go);
}