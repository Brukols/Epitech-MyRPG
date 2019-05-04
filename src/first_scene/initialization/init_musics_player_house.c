/*
** EPITECH PROJECT, 2019
** init_music_playe_houe
** File description:
** my_rpg
*/

#include "my_rpg.h"

musics_t *voice_m_sound(musics_t *music)
{
    music->type = VOICE_M;
    music->music = sfMusic_createFromFile("ressources/music/voice_m.ogg");
    if (!music->music)
        return (NULL);
    return (music);
}

musics_t *voice_f_sound(musics_t *music)
{
    music->type = VOICE_F;
    music->music = sfMusic_createFromFile("ressources/music/voice_f.ogg");
    if (!music->music)
        return (NULL);
    return (music);
}

musics_t *init_musics_player_house(void)
{
    musics_t *musics = malloc(sizeof(musics_t));
    musics_t *(*fill_musics_fs_scene[])() = {run_sound, open_chest_sound, \
    voice_f_sound, voice_m_sound};

    if (!musics)
        return (NULL);
    musics->prev = NULL;
    for (int i = 0; i < 4; i++) {
        musics = fill_musics_fs_scene[i](musics);
        if (!musics)
            return (NULL);
        if (i == 3)
            break;
        if (!(musics->next = malloc(sizeof(musics_t))))
            return (NULL);
        musics->next->prev = musics;
        musics = musics->next;
    }
    musics->next = NULL;
    for (; musics->prev; musics = musics->prev);
    return (musics);
}