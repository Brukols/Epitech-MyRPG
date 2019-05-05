/*
** EPITECH PROJECT, 2019
** status
** File description:
** my_rpg
*/

#ifndef STATS_H
#define STATS_H

#include "my_rpg.h"

enum stat_e {
    LEVEL,
    LIFE,
    POWER,
    ATK
};

typedef struct level_bar_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} level_bar_t;

typedef struct player_stats_s {
    enum stat_e stat;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
    struct player_stats_s *next;
    struct player_stats_s *prev;
} player_stats_t;

typedef struct stats_s {
    level_bar_t *level_bar;
    player_stats_t *player_stats; 
} stats_t;

#endif