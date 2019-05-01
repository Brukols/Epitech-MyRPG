/*
** EPITECH PROJECT, 2019
** playe_rotuvh_chest
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool player_touch_chest_below(game_object_t *go, game_object_t *player)
{
    if ((player->pos.x + 35 > go->pos.x && player->pos.x + 35 < \
        go->pos.x + go->hitbox_size.x && player->pos.y > go->pos.y && \
        player->pos.y < go->pos.y + go->hitbox_size.y) || \
        (player->pos.x + 35 > go->pos.x && player->pos.x + 35 < \
        go->pos.x + go->hitbox_size.x && player->pos.y + 45 > go->pos.y && \
        player->pos.y + 45 < go->pos.y + go->hitbox_size.y))
        return (true);
    return (false);
}

bool player_touch_chest_left(game_object_t *go, game_object_t *player)
{
    if ((player->pos.x + 90 > go->pos.x && player->pos.x + 90 < \
        go->pos.x + go->hitbox_size.x && player->pos.y + 60 > go->pos.y && \
        player->pos.y + 60 < go->pos.y + go->hitbox_size.y) || \
        (player->pos.x + 90 > go->pos.x && player->pos.x + 90 < \
        go->pos.x + go->hitbox_size.x && player->pos.y + 90 > go->pos.y && \
        player->pos.y + 90 < go->pos.y + go->hitbox_size.y))
        return (true);
    return (false);
}

bool player_touch_chest_up(game_object_t *go, game_object_t *player)
{
    if ((player->pos.x + 35 > go->pos.x && player->pos.x + 35 < \
        go->pos.x + go->hitbox_size.x && player->pos.y + 100 > go->pos.y && \
        player->pos.y + 100 < go->pos.y + go->hitbox_size.y) || \
        (player->pos.x + 35 > go->pos.x && player->pos.x + 35 < \
        go->pos.x + go->hitbox_size.x && player->pos.y + 120 > go->pos.y && \
        player->pos.y + 120 < go->pos.y + go->hitbox_size.y))
        return (true);
    return (false);
}

bool player_touch_chest_right(game_object_t* go, game_object_t *player)
{
    if ((player->pos.x - 15 > go->pos.x && player->pos.x - 15 < \
        go->pos.x + go->hitbox_size.x && player->pos.y + 60 > go->pos.y && \
        player->pos.y + 60 < go->pos.y + go->hitbox_size.y) || \
        (player->pos.x - 15 > go->pos.x && player->pos.x - 15 < \
        go->pos.x + go->hitbox_size.x && player->pos.y + 90 > go->pos.y && \
        player->pos.y + 90 < go->pos.y + go->hitbox_size.y))
        return (true);
    return (false);
}

bool player_touch_chest(game_object_t *go, game_object_t *player)
{
    if (player_touch_chest_below(go, player) == true)
        return (true);
    if (player_touch_chest_left(go, player) == true)
        return (true);
    if (player_touch_chest_up(go, player) == true)
        return (true);
    if (player_touch_chest_right(go, player) == true)
        return (true);
    return (false);
}