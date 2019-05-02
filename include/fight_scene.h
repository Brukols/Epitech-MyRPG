/*
** EPITECH PROJECT, 2019
** fight_scene.h
** File description:
** fight_scene.h
*/

#ifndef FIGHT_SCENE_H_
#define FIGHT_SCENE_H_

#include "my_rpg.h"

#define ERROR -1
#define BG_FIGHT "ressources/sprites/fight/bg.png"
#define ACTIONBAR_FIGHT "ressources/sprites/fight/actionbar.png"
#define ATTACK_BUTTON "ressources/sprites/fight/attack_button.png"
#define MAGIC_BUTTON "ressources/sprites/fight/magic_button.png"
#define ESCAPE_BUTTON "ressources/sprites/fight/escape_button.png"
#define FIGHT_MUSIC "ressources/music/pokemon_fight_music.ogg"

scenes_t *init_fight_scene(scenes_t *scenes);

//buttons
buttons_t *init_fight_scene_buttons(void);
buttons_t *attack_button(buttons_t *button);
buttons_t *magic_button(buttons_t *button);
buttons_t *escape_button(buttons_t *button);

//music
struct musics_s *init_fight_scene_music(void);

//objects
scene_object_t *init_fight_scene_objs(void);
background_t *init_fight_scene_background(void);
game_object_t *init_fight_scene_game_objects(void);

//player
player_t *init_fight_scene_player(void);
game_object_t *init_fight_scene_player_object(void);

//display
game_t *display_fight_scene(game_t *game);
void display_fight_scene_buttons(game_t *game);
void display_fight_scene_objs(game_t *game);

#endif
