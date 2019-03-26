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
    PLAY_PAUSE,
    SETTING,
    ...
};

typedef struct buttons_s {
    enum button_e type;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    struct scene_s *(*callback)(struct scene_s *);
    struct button_s *next;
    struct button_s *prev;
} buttons_t;

#endif
