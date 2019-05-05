/*
** EPITECH PROJECT, 2019
** fight_scene.h
** File description:
** fight_scene.h
*/

#ifndef FIGHT_SCENE_H_
#define FIGHT_SCENE_H_

#include "my_rpg.h"
#include <time.h>

#define ERROR -1
#define BG_FIGHT "ressources/sprites/fight/bg.png"
#define ACTIONBAR_FIGHT "ressources/sprites/fight/actionbar.png"
#define ATTACK_BUTTON "ressources/sprites/fight/attack_button.png"
#define MAGIC_BUTTON "ressources/sprites/fight/magic_button.png"
#define ESCAPE_BUTTON "ressources/sprites/fight/escape_button.png"
#define FIGHT_INFO_BUTTON "ressources/sprites/fight/info_button.png"
#define ENEMY_SHEET "ressources/sprites/fight/enemies.png"
#define FIGHT_INFO  "ressources/sprites/fight/info_box.png"
#define FIGHT_HELP  "ressources/sprites/fight/fight_help.png"
#define PLAYER_SHEET "ressources/sprites/chara5.png"
#define FIGHT_FONT  "ressources/font/fight_font.ttf"
#define FIGHT_MUSIC "ressources/music/pokemon_fight_music.ogg"

//*******************
// MANAGE_FIGHT_SCENE
//*******************
game_t *manage_fight_scene(game_t *game);
int check_hp(game_t *game);
int defeated(game_t *game, char *str);
scenes_t *init_fight_scene(scenes_t *scenes);
void end_fight_scene(game_t *game);
void next_quest(game_t *game, int status);
int wait_n_seconds(float n);
void get_player_stats(game_t *game);

//**********
// BUTTONS
//**********
buttons_t *init_fight_scene_buttons(void);
buttons_t *attack_button(buttons_t *button);
buttons_t *magic_button(buttons_t *button);
buttons_t *escape_button(buttons_t *button);
buttons_t *info_button(buttons_t *button);

//**********
// ACTIONS
//**********
int player_basic_attack(game_t *game);
int player_magic_attack(game_t *game);
char *make_normal_attack_msg(game_t *game, char *msg);
char *make_powerful_attack_msg(game_t *game, char *msg);
char *make_failed_attack_msg(game_t *game, char *msg);
char *make_magic_attack_msg(game_t *game, char *msg);
int rand_action(int max);
int rand_basic_attack(int nb);
void calcul_basic_attack(int attack_status, game_t *game);
void calcul_magic_attack(game_t *game);
int escape_fight_scene(game_t *game);
int escape_exit(game_t *game);
int enemy_attack(game_t *game);
char *make_enemy_attack_msg(game_t *game, char *msg);

//**********
// ANIMATIONS
//**********
void fight_animation(game_t *game);
void player_attack_animation(game_t *game);
void update_enemy_pos(game_t *game);

//**********
// MUSIC
//**********
struct musics_s *init_fight_scene_music(void);

//**********
// TEXT
//**********
texts_t *init_fight_text(void);

//**********
// OBJECTS
//**********
scene_object_t *init_fight_scene_objs(scenes_t *scene);
background_t *init_fight_scene_background(void);
game_object_t *init_fight_scene_game_objects(void);
game_object_t *create_actionbar(game_object_t *obj);
game_object_t *create_fight_info(game_object_t *obj);
game_object_t *create_help_box(game_object_t *obj);

//**********
// PLAYER
//**********
player_t *init_fight_scene_player(scenes_t *scene);
game_object_t *init_fight_scene_player_object(void);

//**********
// ENEMIES
//**********
enemy_t *init_enemies(void);
enemy_t *init_enemy_one(enemy_t *enemy);
enemy_t *init_enemy_two(enemy_t *enemy);
enemy_t *init_enemy_three(enemy_t *enemy);
enemy_t *init_enemy_four(enemy_t *enemy);

//**********
// DISPLAY
//**********
game_t *display_fight_scene(game_t *game);
void display_fight_scene_objs(game_t *game);
void display_enemies(game_t *game);
void display_fight_scene_buttons(game_t *game);
int display_info(game_t *game);

//**********
// EVENTS
//**********
int fight_events(game_t *game);
int manage_fight_scene_buttons_events(game_t *game);

#endif
