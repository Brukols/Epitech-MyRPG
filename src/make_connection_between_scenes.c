/*
** EPITECH PROJECT, 2019
** make_connecriont_between_scenes
** File description:
** my_rpg
*/

#include "my_rpg.h"

void make_connection_between_scenes(game_t *game)
{
    scenes_t *scene = game->scenes;
    player_t *player_fs_scene;
    player_t *player_house_player;

    for (; scene->scene != FIRST_SCENE; scene = scene->next);
    player_fs_scene = scene->objs->player;
    for (; scene->scene != PLAYER_HOUSE; scene = scene->next);
    player_house_player = scene->objs->player;
    player_house_player->inventory = player_fs_scene->inventory;
}