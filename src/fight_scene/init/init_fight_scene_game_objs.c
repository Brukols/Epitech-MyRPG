/*
** EPITECH PROJECT, 2019
** init_fight_scene_game_objs.c
** File description:
** init_fight_scene_game_objs.c
*/

#include "my_rpg.h"

game_object_t *init_fight_scene_game_objects(void)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    game_object_t *(*init_g_o[3])() = {create_actionbar, \
        create_fight_info, create_help_box};

    if (obj == NULL)
        return (NULL);
    obj->prev = NULL;
    for (int i = 0; i < 3; i++) {
        if ((obj = init_g_o[i](obj)) == NULL)
            return (NULL);
        if (i == 2)
            break;
        obj->next = malloc(sizeof(game_object_t));
        if (obj->next == NULL)
            return (NULL);
        obj->next->prev = obj;
        obj = obj->next;
    }
    obj->next = NULL;
    for (; obj->prev; obj = obj->prev);
    return (obj);
}

game_object_t *create_actionbar(game_object_t *obj)
{
    obj->display = true;
    obj->pos = init_vec2f(0, 830);
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

game_object_t *create_fight_info(game_object_t *obj)
{
    obj->display = true;
    obj->pos = init_vec2f(1120, 880);
    obj->texture = sfTexture_createFromFile(FIGHT_INFO, NULL);
    obj->sprite = sfSprite_create();
    if (obj->texture == NULL || obj->sprite == NULL) {
        free(obj);
        return (NULL);
    }
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (obj);
}

game_object_t *create_help_box(game_object_t *obj)
{
    obj->display = false;
    obj->pos = init_vec2f(0, 0);
    obj->texture = sfTexture_createFromFile(FIGHT_HELP, NULL);
    obj->sprite = sfSprite_create();
    if (obj->texture == NULL || obj->sprite == NULL) {
        free(obj);
        return (NULL);
    }
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (obj);
}
