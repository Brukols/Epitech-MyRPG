/*
** EPITECH PROJECT, 2019
** move_all_the_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void move_bg(background_t *bg, sfVector2f pos_play, sfVector2f pos_bg)
{
    if (bg->move_x > 0 && pos_bg.x > -2470 && pos_play.x >= 900) {
        bg->pos.x -= 5;
    }
    if (bg->move_x < 0 && pos_bg.x < 0 && pos_play.x <= 900) {
        bg->pos.x += 5;
    }
    if (bg->move_y > 0 && pos_bg.y > -1400 && pos_play.y >= 480) {
        bg->pos.y -= 5;
    }
    if (bg->move_y < 0 && pos_bg.y < -5 && pos_play.y <= 480) {
        bg->pos.y += 5;
    }
}

void move_player_fs_scene(game_object_t *player, sfVector2f pos_play, \
sfVector2f pos_bg)
{
    if ((pos_bg.x <= -2470 || pos_play.x < 900) && player->move_x > 0) {
        player->pos.x += 5;
    }
    if ((pos_bg.x >= 0 || pos_play.x > 900) && player->move_x < 0) {
        player->pos.x -= 5;
    }
    if ((pos_bg.y <= -1400 || pos_play.y < 480) && player->move_y > 0) {
        player->pos.y += 5;
        player->comparison += 5;
    }
    if ((pos_bg.y >= -5 || pos_play.y > 480) && player->move_y < 0) {
        player->pos.y -= 5;
        player->comparison -= 5;
    }
}

void move_game_object(game_object_t *go, background_t *bg, \
game_object_t *player)
{
    if (bg->move_x > 0 && bg->pos.x > -2470 && player->pos.x >= 900) {
        go->pos.x -= 5;
        go->hitbox_pos.x -= 5;
    }
    if (bg->move_x < 0 && bg->pos.x < 0 && player->pos.x <= 900) {
        go->pos.x += 5;
        go->hitbox_pos.x += 5;
    }
    if (bg->move_y > 0 && bg->pos.y > -1400 && player->pos.y >= 480) {
        go->pos.y -= 5;
        go->hitbox_pos.y -= 5;
        go->comparison -= 5;
    }
    if (bg->move_y < 0 && bg->pos.y < -5 && player->pos.y <= 480) {
        go->pos.y += 5;
        go->hitbox_pos.y += 5;
        go->comparison += 5;
    }
}

void move_all_the_scene(game_t *game)
{
    game_object_t *go = game->scenes->objs->game_object;
    background_t *bg = game->scenes->objs->background;
    game_object_t *player = game->scenes->objs->player->game_object;
    sfVector2f pos_pla = init_vec2f(player->pos.x, player->pos.y);
    sfVector2f pos_bg = init_vec2f(bg->pos.x, bg->pos.y);

    if (player_touch_smth(game) == true)
        return;
    for (; go; go = go->next) {
        if (go->type != PLAYER)
            move_game_object(go, bg, player);
    }
    move_player_fs_scene(player, pos_pla, pos_bg);
    move_bg(bg, pos_pla, pos_bg);
}
