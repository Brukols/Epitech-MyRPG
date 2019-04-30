/*
** EPITECH PROJECT, 2019
** display_fight_scene.c
** File description:
** display_fight_scene.c
*/

#include "my_rpg.h"

void display_fight_scene(sfRenderWindow *window, scene_t *scene)
{
    for (int i = 0; i < scene->nb_object; i++) {
        sfSprite_setPosition(scene->object[i]->sprite,
                             scene->object[i]->position);
        sfRenderWindow_drawSprite(window, scene->object[i]->sprite, NULL);
    }
    for (int i = 0; i < scene->nb_button; i++) {
        sfSprite_setPosition(scene->button[i]->sprite,
                             scene->button[i]->position);
        sfRenderWindow_drawSprite(window, scene->button[i]->sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, scene->button[i]->shape,
        NULL);
    }
}
