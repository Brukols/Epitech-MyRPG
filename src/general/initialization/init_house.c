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
    go->comparison = y * 2.3;
    go->rect = init_intrect(0, 96, 128, 160);
    go->hitbox_pos = init_vec2f(x * 2.3, (y + 40) * 2.3);
    go->hitbox_size = init_vec2f(128 * 2.3, 120 * 2.3);
    go->scale = init_vec2f(2.3, 2.3);
    go->display = true;
    go->type = PLAYER_HOUSE_FS_SCENE;
    return (go);
}

game_object_t *init_brown_house(game_object_t *go, int x, int y)
{
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/objs_map.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x * 2.3, y * 2.3);
    go->comparison = y * 2.3;
    go->rect = init_intrect(672, 65, 96, 94);
    go->hitbox_pos = init_vec2f(x * 2.3, (y + 11) * 2.3);
    go->hitbox_size = init_vec2f(96 * 2.3, 83 * 2.3);
    go->scale = init_vec2f(2.3, 2.3);
    go->display = true;
    go->type = BROWN_HOUSE_FS_SCENE;
    return (go);
}
