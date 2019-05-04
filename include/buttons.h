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
    MENU_SETTINGS,
    MENU_EXIT,
    BOX_DIALOG,
    ATTACK,
    MAGIC,
    ESCAPE,
    ENEMY,
    INFO
};

typedef struct buttons_s {
    enum button_e type;
    sfTexture *texture;
    sfTexture *hover;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    sfClock *clock;
    sfVector2f hitbox_pos;
    bool display;
    int (*callback)();
    struct buttons_s *next;
    struct buttons_s *prev;
} buttons_t;

#endif
