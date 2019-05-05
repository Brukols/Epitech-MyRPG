/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** settings scene
*/

#include "my_rpg.h"

background_t *init_settings_background(void)
{
    background_t *bg = malloc(sizeof(background_t));

    if (!bg)
        return (NULL);
    if (!(bg->texture = sfTexture_createFromFile(\
        "ressources/sprites/settings/3.png", NULL)))
        return (NULL);
    if (!(bg->sprite = sfSprite_create()))
        return (NULL);
    bg->pos = init_vec2f(0, 0);
    sfSprite_setPosition(bg->sprite, bg->pos);
    sfSprite_setTexture(bg->sprite, bg->texture, sfFalse);
    return (bg);
}

scenes_t *init_scene_settings(scenes_t *scene)
{
    scene->scene = SETTINGS;
    if (!(scene->objs = malloc(sizeof(scene_object_t))))
        return NULL;
    if (!(scene->objs->background = init_settings_background()))
        return NULL;
    if (!(scene->buttons = init_settings()))
        return (NULL);
    return (scene);
}
