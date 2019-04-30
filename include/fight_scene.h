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
#define BG_FIGHT "../../ressources/sprites/fight/bg.png"
#define ACTIONBAR_FIGHT "../../ressources/sprites/fight/actionbar.png"
#define ATTACK_BUTTON "../../ressources/sprites/fight/attack_button.png"
#define MAGIC_BUTTON "../../ressources/sprites/fight/magic_button.png"
#define ESCAPE_BUTTON "../../ressources/sprites/fight/escape_button.png"

typedef struct button
{
    sfVector2f position;
    sfVector2f size;
    sfRectangleShape *shape;
    sfSprite *sprite;
    sfTexture *texture;
    void (*callback)(game_t *game);
} button_t;

typedef struct object
{
    sfVector2f position;
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    sfIntRect *rect;
} object_t;

typedef struct scene
{
    int nb_button;
    button_t **button;
    int nb_object;
    object_t **object;
    sfClock *clock;
} scene_t;

scene_t *init_fight_scene(void);

//object
int init_fight_scene_objects(scene_t *scene);
object_t *create_object(char *filepath, sfVector2f position);
void destroy_object(object_t *object);

//button
int init_fight_scene_buttons(scene_t *scene);
button_t *create_button(char *filepath, sfVector2f size, sfVector2f position);

//display
void display_fight_scene(sfRenderWindow *window, scene_t *scene);

#endif
