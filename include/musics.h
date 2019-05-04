/*
** EPITECH PROJECT, 2019
** music.h
** File description:
** my_rpg
*/

#ifndef MUSIC_H
#define MUSIC_H

#include "my_rpg.h"

enum music_e {
    WIND_SOUND,
    RUN_SOUND,
    OPEN_CHEST_SOUND
};

typedef struct musics_s {
    enum music_e type;
    sfMusic *music;
    struct musics_s *next;
    struct musics_s *prev;
} musics_t;

#endif
