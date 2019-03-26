/*
** EPITECH PROJECT, 2019
** text.h
** File description:
** struct
*/

#ifndef TEXT_H
#define TEXT_H

#include "my_rpg.h"

enum text_e {
    SCORE,
    MONEY
    ...
};

typedef struct texts_s {
    enum text_e type;
    int size;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfIntRect rect;
    struct texts_s *next;
    struct texts_s *prev;
} texts_t;

#endif
