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
game_object_t *init_game_object_fs_scene(void);
game_object_t *init_shaft(game_object_t *, int x, int y);
scene_object_t *put_chara_in_game_object(scene_object_t *);

// DISPLAY //

game_t *display_fs_scene(game_t *);
void display_bg_fs_scene(game_t *);
void display_player_fs_scene(game_t *);
void display_game_object_fs_scene(game_t *);
void move_all_the_scene(game_t *);
bool player_touch_smth(game_t *);

// EVENTS //

game_t *events_fs_scene(game_t *);
void move_the_scene(game_t *, sfKeyCode, bool);

// DESTROY //

#endif