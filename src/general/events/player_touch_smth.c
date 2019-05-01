/*
** EPITECH PROJECT, 2019
** player_touc_smth
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool will_touch(background_t *bg, player_t *player, game_object_t *go)
{
    sfVector2f pos_player = player->game_object->pos;

    if (will_touch_side(bg, go, pos_player) == true)
        return (true);
    if (will_touch_up_and_down(bg, go, pos_player) == true)
        return (true);
    if (will_touch_the_border(bg, pos_player) == true)
        return (true);
    return (false);
}

bool player_touch_a_go(game_t *game)
{
    player_t *player = game->scenes->objs->player;
    game_object_t *go = game->scenes->objs->game_object;
    background_t *bg = game->scenes->objs->background;

    for (; go->prev; go = go->prev);
    for (; go; go = go->next) {
        if (go->type == PLAYER)
            continue;
        if (will_touch(bg, player, go) == true && go->display == true) {
            return (animation_shaft(game, go));
        }
    }
    return (false);
}

bool player_touch_smth(game_t *game)
{
    return (player_touch_a_go(game));
}