/*
** EPITECH PROJECT, 2019
** destroy_muscis
** File description:
** my_rpg
*/

#include "my_rpg.h"

void delete_musics(musics_t *music)
{
    for (; music; music = music->next)
        sfMusic_destroy(music->music);
}

void destroy_musics(game_t *game)
{
    scenes_t *scenes = game->scenes;

    for (; scenes->prev; scenes = scenes->prev);
    for (; scenes->scene != FIRST_SCENE; scenes = scenes->next);
    delete_musics(scenes->musics);
    for (; scenes->prev; scenes = scenes->prev);
    for (; scenes->scene != PLAYER_HOUSE; scenes = scenes->next);
    delete_musics(scenes->musics);
    for (; scenes->prev; scenes = scenes->prev);
    for (; scenes->scene != ZORO_HOUSE; scenes = scenes->next);
    delete_musics(scenes->musics);
}