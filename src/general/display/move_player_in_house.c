/*
** EPITECH PROJECT, 2019
** move_player_in_house
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool will_touch_house_side(game_object_t *player, game_object_t *go, \
sfVector2f pos_player)
{
    if (player->move_x < 0 && pos_player.x + 10 > go->hitbox_pos.x &&   \
        pos_player.x + 10 < go->hitbox_pos.x + go->hitbox_size.x && \
        pos_player.y + 85 > go->hitbox_pos.y && pos_player.y + 85 < \
        go->hitbox_pos.y + go->hitbox_size.y)
        return (true);
    if (player->move_x > 0 && pos_player.x + 65 > go->hitbox_pos.x && \
        pos_player.x + 65 < go->hitbox_pos.x + go->hitbox_size.x && \
        pos_player.y + 85 > go->hitbox_pos.y && pos_player.y + 85 < \
        go->hitbox_pos.y + go->hitbox_size.y)
        return (true);
    return (false);
}

bool will_touch_house_up_and_down(game_object_t *player, game_object_t *go, \
sfVector2f pos_player)
{
    if (player->move_y < 0 && pos_player.y + 80 > go->hitbox_pos.y && \
        pos_player.y + 80 < go->hitbox_pos.y + go->hitbox_size.y && \
        pos_player.x + 60 > go->hitbox_pos.x && pos_player.x + 20 < \
        go->hitbox_pos.x + go->hitbox_size.x)
        return (true);
    if (player->move_y > 0 && pos_player.y + 5 + 100 > go->hitbox_pos.y && \
        pos_player.y + 5 + 100 < go->hitbox_pos.y + go->hitbox_size.y && \
        pos_player.x + 60 > go->hitbox_pos.x && pos_player.x + 20 < \
        go->hitbox_pos.x + go->hitbox_size.x)
        return (true);
    return (false);
}

void move_player_in_x_y(game_t *game)
{
    game_object_t *go = game->scenes->objs->game_object;
    game_object_t *player = game->scenes->objs->player->game_object;
    sfVector2f pos_pla = init_vec2f(player->pos.x, player->pos.y);

    if (player->move_x > 0)
        player->pos.x += 5;
    if (player->move_x < 0)
        player->pos.x -= 5;
    if (player->move_y > 0) {
        player->pos.y += 5;
        player->comparison += 5;
    }
    if (player->move_y < 0) {
        player->pos.y -= 5;
        player->comparison -= 5;
    }
}

bool player_touch_smth_in_house(game_t *game)
{
    game_object_t *go = game->scenes->objs->game_object;
    game_object_t *player = game->scenes->objs->player->game_object;
    sfVector2f pos_pla = init_vec2f(player->pos.x, player->pos.y);

    for (; go; go = go->next) {
        if (will_touch_house_up_and_down(player, go, pos_pla) == true || \
            will_touch_house_side(player, go, pos_pla) == true) {
            player->move_x = 0;
            player->move_y = 0;
            return true;
        }
    }
    return (touch_walls_house(game));
}

void move_player_on_the_house(game_t *game)
{
    if (player_touch_smth_in_house(game) == true)
        return;
    move_player_in_x_y(game);
}