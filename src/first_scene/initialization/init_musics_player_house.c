/*
** EPITECH PROJECT, 2019
** init_music_playe_houe
** File description:
** my_rpg
*/

#include "my_rpg.h"

musics_t *init_musics_player_house(void)
{
    musics_t *musics = malloc(sizeof(musics_t));
    musics_t *(*fill_musics_fs_scene[])() = {run_sound};

    if (!musics)
        return (NULL);
    musics->prev = NULL;
    for (int i = 0; i < 1; i++) {
        musics = fill_musics_fs_scene[i](musics);
        if (!musics)
            return (NULL);
        if (i == 0)
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