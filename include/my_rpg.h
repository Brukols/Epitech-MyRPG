/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** header
*/

#ifndef MY_DEFENDER_H
#define MY_DEFENDER_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "macros.h"
#include "inventory.h"
#include "scene_object.h"
#include "my.h"
#include "scenes.h"
#include "game.h"
#include "buttons.h"
#include "texts.h"
#include "game.h"
#include "protos_menu.h"
#include "protos_first_scene.h"

// GENERAL_DISPLAY //

void display_bg(game_t *);
void display_player(game_t *);
void move_all_the_scene(game_t *);
void move_the_scene(game_t *, sfKeyCode, bool);
game_object_t *sort_game_object(game_object_t *);
void display_buttons(game_t *);
void display_pnj_dialog(game_t *, texts_t *, pnj_t *);
void display_pnj_name(game_t *, texts_t *, pnj_t *);
void display_inventory(game_t *);

// GENERAL_EVENTS //

bool player_touch_smth(game_t *);
bool will_touch_the_border(background_t *, sfVector2f);
bool will_touch_up_and_down(background_t *, game_object_t *, sfVector2f);
bool will_touch_side(background_t *, game_object_t *, sfVector2f);
bool change_dialog(game_t *);
void interactions(game_t *game, sfKeyCode);
bool click(sfVector2f pos, sfVector2f size, sfVector2f mouse);
void manage_mouse_button_event(game_t *);
void touch_a_button(game_t *, sfVector2f);

// GENERAL INIT //

char **init_map(char *);
char **str_to_word_array_for_map(char *);
sfVector2f init_vec2f(float x, float y);
sfIntRect init_intrect(int top, int left, int width, int height);
sfColor init_color(int r, int g, int b, int a);
game_object_t *init_house_player(game_object_t *, int x, int y);
game_object_t *init_object(game_object_t *, char *);
game_object_t *init_shaft(game_object_t *, int x, int y);
scene_object_t *init_pnj(scene_object_t *, char *);
game_object_t *freddy(game_object_t *, int, int);
char **init_discuss(char *, int *);
texts_t *init_box_text(texts_t *);
buttons_t *init_box_dialog(buttons_t *);
game_object_t *dobby(game_object_t *, int, int);
game_object_t *init_brown_house(game_object_t *, int, int);
game_object_t *init_rock(game_object_t *, int, int);
game_object_t *init_first_chest(game_object_t *, int, int);
scene_object_t *put_chara_in_game_object(scene_object_t *);
player_t *init_player(int, int);
game_object_t *init_game_object_scene(char *);

game_t *init_all_game(void);
sfRenderWindow *create_window(unsigned int, unsigned int, unsigned int);
int launch_game(void);

#endif
