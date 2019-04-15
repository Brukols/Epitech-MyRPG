/*
** EPITECH PROJECT, 2019
** scene_object
** File description:
** header
*/

#ifndef scene_object_H
#define scene_object_H

#include "my_rpg.h"

enum game_object_e {
    PLAYER,
    SHAFT,
    INTRO_SKIP1,
    INTRO_SKIP2,
    INTRO_FAIRY,
    INTRO_BUBBLE1,
    INTRO_BUBBLE2,
    INTRO_BUBBLE3,
    INTRO_INTERROGATION,
    INTRO_BUBBLE_RED,
    INTRO_KING_WALK,
    INTRO_KING_SURPRISE,
    INTRO_BUBBLE4,
    INTRO_BUBBLE5
};

typedef struct background_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    sfVector2f scale;
    int move_x;
    int move_y;
} background_t;

typedef struct game_object_s {
    enum game_object_e type;
    int move_x;
    int move_y;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfVector2f hitbox_pos;
    sfVector2f hitbox_size;
    struct game_object_s *next;
    struct game_object_s *prev;
} game_object_t;

typedef struct player_s {
    //items_t *items;
    char *name;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    int direction;
    sfClock *clock;
    int move_x;
    int move_y;
    game_object_t *game_object;
} player_t;

typedef struct event_click_s {
    int user_click;
    int fairy_event;
} event_click_t;

typedef struct scene_object_s {
    background_t *background;
    game_object_t *game_object;
    player_t *player;
    event_click_t *clicks;
} scene_object_t;

#endif
