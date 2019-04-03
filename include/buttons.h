/*
** EPITECH PROJECT, 2019
** button.h
** File description:
** header
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "my_rpg.h"

enum button_e {
    START,
    START_2,
    START_3,
    SETTING
};

typedef struct buttons_s {
    enum button_e type;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    sfClock *clock;
    game_t *(*callback)();
    struct buttons_s *next;
    struct buttons_s *prev;
} buttons_t;

#endif
