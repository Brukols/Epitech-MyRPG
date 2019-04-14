/*
** EPITECH PROJECT, 2019
** init all elements
** File description:
** rpg
*/

#include "my_rpg.h"

buttons_t *init_buttons(void)
{
    buttons_t *button = malloc(sizeof(buttons_t));
    buttons_t *(*init_each_button_menu[4])() = {button_play, button_play2, \
    setting_button, exit_button};

    if (!button)
        return (NULL);
    button->prev = NULL;
    for (int i = 0; i < 4; i++) {
        button = init_each_button_menu[i](button);
        if (i == 3)
            break;
        if ((button->next = malloc(sizeof(buttons_t))) == NULL)
            return NULL;
        button->next->prev = button;
        button = button->next;
    }
    button->next = NULL;
    for (; button->prev; button = button->prev);
    return (button);
}

scene_object_t *init_menu_objects(scene_object_t *objs)
{
    if ((objs = malloc(sizeof(scene_object_t))) == NULL)
        return NULL;
    if ((objs->background = malloc(sizeof(background_t))) == NULL)
        return NULL;
    if ((objs->background = init_background(objs->background)) == NULL)
        return NULL;
    return (objs);
}

scenes_t *init_scene_menu(scenes_t *scene)
{
    scene->scene = MENU;
    if ((scene->objs = init_menu_objects(scene->objs)) == NULL)
        return NULL;
    if (scene->objs == NULL)
        return NULL;
    scene->buttons = init_buttons();
    if (scene->buttons == NULL)
        return NULL;
    scene->texts = init_title();
    return (scene);
}
