/*
** EPITECH PROJECT, 2019
** protos_menu
** File description:
** my_rp
*/

#ifndef PROTOS_MENU_H
#define PROTOS_MENU_H

#include "my_rpg.h"

game_t *select_red_bubble(game_t *);
game_object_t *init_bubble_red(game_object_t *);
game_t *select_interrogation(game_t *);
game_t *bubble_1(game_t *);
game_t *bubble_2(game_t *);
game_t *bubble_3(game_t *);
game_t *display_fairy(game_t *);
game_object_t *init_skip2(game_object_t *);
game_object_t *init_skip1(game_object_t *);
game_object_t *init_bubble_3(game_object_t *);
game_object_t *init_bubble_2(game_object_t *);
game_object_t *init_bubble_1(game_object_t *);
game_t *select_fairy(game_t *);
game_t *select_bubble_1(game_t *);
game_t *select_bubble_2(game_t *);
game_t *select_bubble_3(game_t *);
scenes_t *init_intro(scenes_t *);
game_t *display_intro(game_t *);
buttons_t *setting_button(buttons_t *);
buttons_t *exit_button(buttons_t *);
background_t *init_background(background_t *);
texts_t *init_title(void);
void display_statics_buttons(game_t *);
void idle_bottoms_buttons(sfVector2i, game_t *);
game_t *idle_play_button(game_t *, char *, char *);
void redirect_idle_play_button(sfVector2i, game_t *);
buttons_t *button_play(buttons_t *);
buttons_t *button_play2(buttons_t *);
sfSprite *first_play_sprite(game_t *);
sfTexture *scnd_play_texture(game_t *);
sfSprite *scnd_play_sprite(game_t *);
sfTexture *first_play_texture(game_t *);
scenes_t *init_scene_menu(scenes_t *);
scene_object_t *init_menu_object(scene_object_t *);
void display_play_button(game_t *);
int launch_game(void);
game_t *scene_managing(game_t *);
game_t *display_menu(game_t *);

#endif
