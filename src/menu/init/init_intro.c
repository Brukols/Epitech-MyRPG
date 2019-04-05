/*
** EPITECH PROJECT, 2019
** intro
** File description:
** rpg
*/

#include "my_rpg.h"

background_t *init_intro_background(background_t *background)
{
    background->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/intro_fée.png", NULL);
    background->sprite = sfSprite_create();
    background->pos.x = 0;
    background->pos.y = 0;
    sfSprite_setPosition(background->sprite, background->pos);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    return (background);
}

game_object_t *init_intro_fairie(game_object_t *game_object)
{
    game_object->prev = NULL;
    game_object->pos.x = 950;
    game_object->pos.y = 420;
    game_object->rect.top = 0;
    game_object->rect.left = 0;
    game_object->rect.width = 160;
    game_object->rect.height = 250;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/fée.png", NULL);
    game_object->next = NULL;
    return (game_object);
}

scene_object_t *init_intro_objects(scene_object_t *objs)
{

    if ((objs = malloc(sizeof(scene_object_t))) == NULL)
        return NULL;
    if ((objs->background = malloc(sizeof(background_t))) == NULL)
        return NULL;
    objs->background = init_intro_background(objs->background);
    if ((objs->game_object = malloc(sizeof(game_object_t))) == NULL)
        return NULL;
    objs->game_object = init_intro_fairie(objs->game_object);
    if ((objs->clicks = malloc(sizeof(event_click_t))) == NULL)
        return NULL;
    objs->clicks->user_click = 0;
    objs->clicks->fairy_event = 0;
    return (objs);
}

scenes_t *init_intro(scenes_t *scene)
{
    scene->scene = INTRO;
    scene->objs = init_intro_objects(scene->objs);
    if (scene->objs == NULL)
        return NULL;
    return (scene);
}
