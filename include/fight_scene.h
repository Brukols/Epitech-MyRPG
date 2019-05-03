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
#define ENEMY_BUTTON_ONE "ressources/sprites/fight/enemy1_button.png"
#define ENEMY_BUTTON_TWO "ressources/sprites/fight/enemy2_button.png"
#define ENEMY_BUTTON_THREE "ressources/sprites/fight/enemy3_button.png"
#define FIGHT_MUSIC "ressources/music/pokemon_fight_music.ogg"

scenes_t *init_fight_scene(scenes_t *scenes);

//buttons
buttons_t *init_fight_scene_buttons(void);
buttons_t *attack_button(buttons_t *button);
buttons_t *magic_button(buttons_t *button);
buttons_t *escape_button(buttons_t *button);
buttons_t *enemy_button_one(buttons_t *button);
buttons_t *enemy_button_two(buttons_t *button);
buttons_t *enemy_button_three(buttons_t *button);

//actions
int player_attack(game_t *game);

//music
struct musics_s *init_fight_scene_music(void);

//objects
scene_object_t *init_fight_scene_objs(void);
background_t *init_fight_scene_background(void);
game_object_t *init_fight_scene_game_objects(void);

//player
player_t *init_fight_scene_player(void);
game_object_t *init_fight_scene_player_object(void);

/* //enemies */
/* player_t *init_fight_scene_enemies(int index); */
/* player_t *init_enemies_loop(player_t *enemy); */
/* player_t init_enemies(int index); */
/* game_object_t *init_enemy_obj(int index, char *filepath); */
/* sfVector2f *get_pos(int index); */

//display
game_t *display_fight_scene(game_t *game);
void display_fight_scene_buttons(game_t *game);
void display_fight_scene_objs(game_t *game);

//events
void fight_events(game_t *game);
void manage_fight_scene_buttons_events(game_t *game);

#endif
