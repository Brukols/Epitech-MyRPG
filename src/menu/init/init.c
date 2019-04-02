/*
** EPITECH PROJECT, 2019
** init all elements
** File description:
** rpg
*/

#include "my_rpg.h"

background_t *init_background(background_t *background)
{
    background->texture = sfTexture_createFromFile(\
    "../../ressources/sprites/menu/background.png", NULL);
    background->sprite = sfSprite_create();
    background->pos.x = 0;
    background->pos.y = 0;
    sfSprite_setPosition(background->sprite, background->pos);
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    return (background);
}

buttons_t *init_buttons(void)
{
    buttons_t *button = malloc(sizeof(buttons_t));
    buttons_t *(*init_each_button_menu[2])() = {button_play, button_play2};

    if (!button)
        return (NULL);
    button->prev = NULL;
    for (int i = 0; i < 2; i++) {
        button = init_each_button_menu[i](button);
        if (i == 1)
            break;
        if ((button->next = malloc(sizeof(buttons_t))) == NULL)
            return NULL;
        button = button->next;
    }
    button->next = NULL;
    return (button);
}

scene_object_t *init_menu_objects(scene_object_t *objs)
{
    if ((objs = malloc(sizeof(scene_object_t))) == NULL)
        return NULL;
    if ((objs->background = malloc(sizeof(background_t))) == NULL)
        return NULL;
    objs->background = init_background(objs->background);
    return (objs);
}

scenes_t *init_scene_menu(scenes_t *scene)
{
    scene->scene = MENU;
    scene->objs = init_menu_objects(scene->objs);
    if (scene->objs == NULL)
        return NULL;
    scene->buttons = init_buttons();
    if (scene->buttons == NULL)
        return NULL;
    return (scene);
}
