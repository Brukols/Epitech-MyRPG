/*
** EPITECH PROJECT, 2019
** header
** File description:
** my_rpg
*/

#ifndef PROTOS_FIRST_SCENE_H
#define PROTOS_FIRST_SCENE_H

#include "my_rpg.h"

// INITIALIZATION HOUSES //

game_object_t *init_plant(game_object_t *go, int x, int y);
game_object_t *init_bed(game_object_t *go, int x, int y);
scenes_t *init_player_house(scenes_t *);
scene_object_t *init_scene_object_player_house(void);
char *next_data(char *str, int *i);
game_object_t *init_house_objects(game_object_t *go, char *str);
game_object_t *init_object_player_house(void);

// INITIALIZATION //

scenes_t *init_first_scene(scenes_t *);
scene_object_t *init_scene_object_fs_scene(void);
game_object_t *init_shaft(game_object_t *, int x, int y);
texts_t *init_texts_fs_scene(void);
buttons_t *init_buttons_fs_scene(void);

// DISPLAY //

game_t *display_player_house(game_t *);
game_t *display_fs_scene(game_t *);
void display_bg_fs_scene(game_t *);
void display_player_fs_scene(game_t *);
void move_all_the_scene(game_t *);
void display_texts_fs_scene(game_t *);

// EVENTS //

game_t *events_fs_scene(game_t *);
void move_the_scene(game_t *, sfKeyCode, bool);
void unlock_smth_fs_scene(game_t *);
bool go_back_to_first_scene(game_t *);

// DESTROY //

#endif
