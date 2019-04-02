/*
** EPITECH PROJECT, 2019
** protos_menu
** File description:
** my_rp
*/

#ifndef PROTOS_MENU_H
#define PROTOS_MENU_H

#include "my_rpg.h"

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
