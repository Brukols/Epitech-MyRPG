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

    if (i == 0) {
        music_play(music, WIND_SOUND, sfTrue);
        i++;
    }
}