/*
** EPITECH PROJECT, 2019
** game.h
** File description:
** my_rpg
*/

#ifndef GAME_H
#define GAME_H

#include "my_rpg.h"

typedef struct game_s {
    scenes_t *scenes;
    sfRenderWindow *window;
} game_t;