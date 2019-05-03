/*
** EPITECH PROJECT, 2019
** init_fight_scene_objs.c
** File description:
** init_fight_scene_objs.c
*/

#include "my_rpg.h"

scene_object_t *init_fight_scene_objs(void)
{
    scene_object_t *obj = malloc(sizeof(scene_object_t));

    if (obj == NULL)
        return (NULL);
    obj->background = init_fight_scene_background();
    obj->game_object = init_fight_scene_game_objects();
    obj->player = NULL;
    obj->clicks = NULL;
    obj->pnj = NULL;
    if (obj->background == NULL || obj->game_object == NULL) {
        free(obj);
        return (NULL);
    }
    return (obj);
}

background_t *init_fight_scene_background(void)
{
    background_t *bg = malloc(sizeof(background_t));

    if (bg == NULL)
        return (NULL);
    bg->pos = init_vec2f(0, 0);
    bg->clock = NULL;
    bg->move_x = 0;
    bg->move_y = 0;
    bg->texture = sfTexture_createFromFile(BG_FIGHT, NULL);
    bg->sprite = sfSprite_create();
    if (bg->texture == NULL || bg->sprite == NULL) {
        free(bg);
        return (NULL);
    }
    sfSprite_setTexture(bg->sprite, bg->texture, sfFalse);
    sfSprite_setPosition(bg->sprite, bg->pos);
    return (bg);
}

game_object_t *init_fight_scene_game_objects(void)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    sfIntRect rect = {.top=0, .left=0, .width=0, .height=0};

    if (obj == NULL)
        return (NULL);
    obj->prev = NULL;
    obj->next = NULL;
    obj->pos = init_vec2f(0, 830);
    obj->rect = rect;
    obj->display = true;
    obj->texture = sfTexture_createFromFile(ACTIONBAR_FIGHT, NULL);
    obj->sprite = sfSprite_create();
    if (obj->texture == NULL || obj->sprite == NULL) {
        free(obj);
        return (NULL);
    }
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (obj);
}

player_t *init_fight_scene_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return (NULL);
    player->name = NULL;
    player->direction = 0;
    player->inventory = NULL;
    player->game_object = init_fight_scene_player_object();
    if (player->game_object == NULL) {
        free(player);
        return (NULL);
    }
    return (player);
}

game_object_t *init_fight_scene_player_object(void)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    sfIntRect rect = {.top=0, .left=0, .width=0, .height=0};

    if (obj == NULL)
        return (NULL);
    obj->pos = init_vec2f(100, 500);
    obj->rect = rect;
    obj->texture = sfTexture_createFromFile(PLAYER, NULL);
    obj->sprite = sfSprite_create();
    if (obj->texture == NULL || obj->sprite == NULL) {
        free(obj);
        return (NULL);
    }
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->clock = NULL;
    return (obj);
}
