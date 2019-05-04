/*
** EPITECH PROJECT, 2019
** go_in_another_scene_fs_scnee
** File description:
** my_rpg
*/

#include "my_rpg.h"

scenes_t *select_zoro_house(game_t *game)
{
    for (; game->scenes->prev; game->scenes = game->scenes->prev);
    for (; game->scenes->scene != ZORO_HOUSE; game->scenes = game->scenes->next);
    return (game->scenes);
}

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
    sfVector2f pos_zoro = init_vec2f(go->pos.x + (48 * 2.3), \
    go->pos.y + (82 * 2.3));
    sfVector2f size_player = init_vec2f(player->rect.width, \
    player->rect.height);

    if (click(player->pos, size_player, pos) == true && go->type == \
        PLAYER_HOUSE_FS_SCENE) {
        stop_music_scene(game->scenes->musics);
        re_initialize_value(game);
        game->scenes = game->scenes->next;
        return (true);
    }
    if (click(player->pos, size_player, pos_zoro) == true && go->type == \
        PLAYER_HOUSE_FS_SCENE) {
        stop_music_scene(game->scenes->musics);
        re_initialize_value(game);
        game->scenes = select_zoro_house(game);
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
    game_object_t *go_zoro = game->scenes->objs->player->game_object;

    for (; go->prev; go = go->prev);
    for (; go; go = go->next) {
        if (go->type != PLAYER_HOUSE_FS_SCENE)
            continue;
        if (will_touch(background, player, go) == true && go->display == true)
            return (go_to_other_scene(game, player_go, go));
    }
    for (; go_zoro->prev; go_zoro = go_zoro->prev);
    for (; go_zoro; go_zoro = go_zoro->next) {
        if (go_zoro->type != BROWN_HOUSE_FS_SCENE)
            continue;
        if (will_touch(background, player, go_zoro) == true && go_zoro->display == true)
            return (go_to_other_scene(game, player_go, go_zoro));
    }
    return (false);
}
