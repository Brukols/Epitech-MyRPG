/*
** EPITECH PROJECT, 2019
** music_play
** File description:
** my_rpg
*/

#include "my_rpg.h"

void music_play(musics_t *music, enum music_e type, sfBool loop)
{
    for (; music->type != type; music = music->next);
    sfMusic_play(music->music);
    sfMusic_setLoop(music->music, loop);
}

void music_pause(musics_t *music, enum music_e type)
{
    for (; music->type != type; music = music->next);
    sfMusic_pause(music->music);
}

void music_stop(musics_t *music, enum music_e type)
{
    for (; music->type != type; music = music->next);
    sfMusic_stop(music->music);
}