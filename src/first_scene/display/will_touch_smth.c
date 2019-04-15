/*
** EPITECH PROJECT, 2019
** will_touch_smth
** File description:
** rpog
*/

#include "my_rpg.h"

bool will_touch_side(background_t *bg, game_object_t *go, \
sfVector2f pos_player)
{
    if (bg->move_x < 0 && pos_player.x - 5 > go->hitbox_pos.x && \
        pos_player.x - 5 < go->hitbox_pos.x + go->hitbox_size.x && \
        pos_player.y + 100 > go->hitbox_pos.y && pos_player.y + 70 < \
        go->hitbox_pos.y + go->hitbox_size.y)
        return (true);
    if (bg->move_x > 0 && pos_player.x + 70 > go->hitbox_pos.x && \
        pos_player.x + 70 < go->hitbox_pos.x + go->hitbox_size.x && \
        pos_player.y + 100 > go->hitbox_pos.y && pos_player.y + 70 < \
        go->hitbox_pos.y + go->hitbox_size.y)
        return (true);
    return (false);
}

bool will_touch_up_and_down(background_t *bg, game_object_t *go, \
sfVector2f pos_player)
{
    if (bg->move_y < 0 && pos_player.y + 65 > go->hitbox_pos.y && \
        pos_player.y + 65 < go->hitbox_pos.y + go->hitbox_size.y && \
        pos_player.x + 65 > go->hitbox_pos.x && pos_player.x < \
        go->hitbox_pos.x + go->hitbox_size.x)
        return (true);
    if (bg->move_y > 0 && pos_player.y + 5 + 100 > go->hitbox_pos.y && \
        pos_player.y + 5 + 100 < go->hitbox_pos.y + go->hitbox_size.y && \
        pos_player.x + 65 > go->hitbox_pos.x && pos_player.x < \
        go->hitbox_pos.x + go->hitbox_size.x)  
        return (true);
    return (false);
}

bool will_touch_the_border(background_t *bg, game_object_t *go, \
sfVector2f pos_player)
{
    if (bg->move_x < 0 && pos_player.x - 5 < 0)
        return (true);
    if (bg->move_x > 0 && pos_player.x + 5 + 130 > 1980)
        return (true);
    if (bg->move_y < 0 && pos_player.y - 5 < 0)
        return (true);
    if (bg->move_y > 0 && pos_player.y + 5 + 108 > 1020)
        return (true);
    return (false);
}