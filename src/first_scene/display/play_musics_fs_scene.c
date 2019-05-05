/*
** EPITECH PROJECT, 2019
** display_muscis_fs_cene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void play_musics_fs_scene(game_t *game)
{
    static int i = 0;
    musics_t *music = game->scenes->musics;

    for (; music && music->type != WIND_SOUND; music = music->next);
    if (!music)
        return;
    if (music->stop == true)
        music_play(game->scenes->musics, WIND_SOUND, sfTrue);
}