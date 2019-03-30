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

#include "macros.h"
#include "scene_object.h"
#include "my.h"
#include "scenes.h"
#include "game.h"
#include "buttons.h"
#include "texts.h"
#include "game.h"
#include "protos_menu.h"
#include "protos_first_scene.h"

game_t *init_all_game(void);
sfRenderWindow *create_window(unsigned int, unsigned int, unsigned int);
sfVector2f init_vec2f(float x, float y);
sfIntRect init_intrect(int top, int left, int width, int height);
int launch_game(void);

#endif
