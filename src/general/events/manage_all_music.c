/*
** EPITECH PROJECT, 2019
** manage_all_music
** File description:
** my_rog
*/

#include "my_rpg.h"

void pause_all_musics(musics_t *music)
{
    for (; music; music = music->next) {
        if (music->stop == true)
            continue;
        sfMusic_pause(music->music);
        music->pause = true;
    }
}

void play_all_musics(musics_t *music)
{
    for (; music; music = music->next) {
        if (music->pause == false)
            continue;
        sfMusic_play(music->music);
        music->pause = false;
        music->stop = false;
    }
}