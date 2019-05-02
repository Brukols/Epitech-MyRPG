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
#include "quests.h"
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
#include "fight_scene.h"
#include "musics.h"

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
void display_quests(game_t *);
void display_msg_in_box(game_t *, char *);
void display_game_object(game_t *);
void my_put_pixel(framebuffer_t *, int, int, sfColor);
particle_t *display_particle(game_t *);
bool animation_shaft(game_t *, game_object_t *);
void my_draw_square(framebuffer_t *, all_particle_t *, int);
int display_leaf(particle_t *);
int display_wind(particle_t *);

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
bool interaction_with_chest(game_t *);
bool player_have_the_key(player_t *);
bool there_is_an_interaction(game_t *);
void change_quest(game_t *, enum all_quests_e);
bool player_touch_chest(game_object_t *, game_object_t *);
bool delete_an_item(game_t *, sfVector2f);

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
scene_object_t *put_chara_in_game_object(scene_object_t *, int, int);
player_t *init_player(void);
game_object_t *init_game_object_scene(char *);
char *init_what_texture(char *, int *);
char *next_for_pnj(char *, int *);
quests_t *init_quests(void);
item_t *create_key(void);
particle_t *init_particle(game_object_t *);
all_particle_t *init_all_particle(void);
framebuffer_t *create_framebuffer(int, int);
particle_t *init_wind_particle(void);

game_t *init_all_game(void);
sfRenderWindow *create_window(unsigned int, unsigned int, unsigned int);
int launch_game(void);

#endif
