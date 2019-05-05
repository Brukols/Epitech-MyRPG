/*
** EPITECH PROJECT, 2019
** stop_music_fs_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void stop_music_scene(musics_t *music)
{
    for (; music; music = music->next) {
        sfMusic_stop(music->music);
        music->stop = true;
        music->pause = false;
    }
}