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
    background->clock = sfClock_create();
    sfSprite_setPosition(background->sprite, background->pos);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    return (background);
}

game_object_t *init_fairy(game_object_t *game_object)
{
    game_object->type = INTRO_FAIRY;
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
    return (game_object);
}

game_object_t *init_interrogation(game_object_t *game_object)
{
    game_object->type = INTRO_INTERROGATION;
    game_object->pos.x = 990;
    game_object->pos.y = 350;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/?.png", NULL);
    return (game_object);
}

game_object_t *init_polipoppy_walk(game_object_t *game_object)
{
    game_object->type = INTRO_KING_WALK;
    game_object->pos.x = -50;
    game_object->pos.y = 420;
    game_object->rect.top = 0;
    game_object->rect.left = 70;
    game_object->rect.width = 70;
    game_object->rect.height = 280;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/walkandsurprise.png", NULL);
    return (game_object);
}

game_object_t *init_polipoppy_surprise(game_object_t *game_object)
{
    game_object->type = INTRO_KING_SURPRISE;
    game_object->pos.x = 800;
    game_object->pos.y = 420;
    game_object->rect.top = 0;
    game_object->rect.left = 280;
    game_object->rect.width = 80;
    game_object->rect.height = 300;
    game_object->clock = sfClock_create();
    game_object->sprite = sfSprite_create();
    game_object->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/intro/walkandsurprise.png", NULL);
    return (game_object);
}

game_object_t *init_intro_sprites(game_object_t *game_object)
{
    game_object_t *(*init_each_sprites_intro[12])() = {init_fairy, init_skip1, init_skip2, init_bubble_1, init_bubble_2, init_bubble_3, init_interrogation, init_bubble_red, init_polipoppy_walk, init_polipoppy_surprise, init_bubble_4, init_bubble_5};

    game_object->prev = NULL;
    for (int i = 0; i < 12; i++) {
        game_object = init_each_sprites_intro[i](game_object);
        if (i == 11)
            break;
        if ((game_object->next = malloc(sizeof(game_object_t))) == NULL)
            return NULL;
        game_object->next->prev = game_object;
        game_object = game_object->next;
    }
    game_object->next = NULL;
    for (; game_object->prev != NULL;  game_object = game_object->prev);
    return (game_object);
}

scene_object_t *init_intro_objects(scene_object_t *objs)
{
    if ((objs = malloc(sizeof(scene_object_t))) == NULL)
        return NULL;
    if ((objs->background = malloc(sizeof(background_t))) == NULL)
        return NULL;
    if ((objs->background = init_intro_background(objs->background)) == NULL)
        return NULL;
    if ((objs->game_object = malloc(sizeof(game_object_t))) == NULL)
        return NULL;
    if ((objs->game_object = init_intro_sprites(objs->game_object)) == NULL)
        return NULL;
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
