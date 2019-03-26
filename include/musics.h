/*
** EPITECH PROJECT, 2019
** music.h
** File description:
** my_defendr
*/

#ifndef MUSIC_H
#define MUSIC_H

#include "my_defender.h"

typedef struct musics_s {
    sfMusic *music;
    struct musics_s *next;
    struct musics_s *prev;
} musics_t;

#endif
