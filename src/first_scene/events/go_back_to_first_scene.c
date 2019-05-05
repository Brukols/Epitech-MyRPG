/*
** EPITECH PROJECT, 2019
** go_back_to_first_scene.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void re_initialize_value_house(game_t *game)
{
    game_object_t *player = game->scenes->objs->player->game_object;

    player->move_x = 0;
    player->move_y = 0;
    player->pos.y -= 6;
}

scenes_t *select_first_scene(game_t *game)
{
    for (; game->scenes->prev; game->scenes = game->scenes->prev);
    for (; game->scenes->scene != FIRST_SCENE; \
game->scenes = game->scenes->next);
    return game->scenes;
}

bool go_back_to_first_scene(game_t *game)
{
    game_object_t *player = game->scenes->objs->player->game_object;

    if (game->scenes->scene == ZORO_HOUSE && player->move_y > 0 && \
player->pos.y + 155 > 980 && player->pos.x > 100 && \
player->pos.x < 1900) {
        re_initialize_value_house(game);
        stop_music_scene(game->scenes->musics);
        game->scenes = select_first_scene(game);
        sfMusic_play(game->scenes->musics->music);
        return (true);
    }
    if (game->scenes->scene == PLAYER_HOUSE && player->move_y > 0 \
&& player->pos.y + 155 > 1080 && player->pos.x > 940 && \
player->pos.x < 1000) {
        re_initialize_value_house(game);
        stop_music_scene(game->scenes->musics);
        game->scenes = select_first_scene(game);
        sfMusic_play(game->scenes->musics->music);
        return (true);
    }
    return (false);
}
