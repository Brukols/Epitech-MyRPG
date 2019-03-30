/*
** EPITECH PROJECT, 2019
** header
** File description:
** my_rpg
*/

#ifndef PROTOS_FIRST_SCENE_H
#define PROTOS_FIRST_SCENE_H

#include "my_rpg.h"

// INITIALIZATION //

scenes_t *init_first_scene(scenes_t *);
scene_object_t *init_scene_object_fs_scene(void);
player_t *init_player_fs_scene(void);

// DISPLAY //

game_t *display_fs_scene(game_t *);
void display_bg_fs_scene(game_t *);
void display_player_fs_scene(game_t *);

// EVENTS //

game_t *events_fs_scene(game_t *);
void move_the_scene(game_t *, sfKeyCode);

// DESTROY //

#endif