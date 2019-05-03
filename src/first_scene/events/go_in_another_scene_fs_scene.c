/*
** EPITECH PROJECT, 2019
** go_in_another_scene_fs_scnee
** File description:
** my_rpg
*/

#include "my_rpg.h"

void re_initialize_value(game_t *game)
{
    background_t *background = game->scenes->objs->background;
    game_object_t *player = game->scenes->objs->player->game_object;

    background->move_x = 0;
    background->move_y = 0;
    player->move_x = 0;
    player->move_y = 0;
    player->pos.y += 6;
}

bool go_to_other_scene(game_t *game, game_object_t *player, game_object_t *go)
{
    sfVector2f pos = init_vec2f(go->pos.x + (80 * 2.3), \
    go->pos.y + (159 * 2.3));
    sfVector2f size_player = init_vec2f(player->rect.width, player->rect.height);

    if (click(player->pos, size_player, pos) == true) {
        re_initialize_value(game);
        game->scenes = game->scenes->next;
        return (true);
    }
    return (false);
}

bool go_in_another_scene_fs_scene(game_t *game)
{
    background_t *background = game->scenes->objs->background;
    player_t *player = game->scenes->objs->player;
    game_object_t *player_go = player->game_object;
    game_object_t *go = game->scenes->objs->player->game_object;

    for (; go->prev; go = go->prev);
    for (; go; go = go->next) {
        if (go->type != PLAYER_HOUSE_FS_SCENE)
            continue;
        if (will_touch(background, player, go) == true && go->display == true)
            return (go_to_other_scene(game, player_go, go));
    }
    return (false);
}