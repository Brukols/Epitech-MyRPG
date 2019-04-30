/*
** EPITECH PROJECT, 2019
** init_fight_scene.c
** File description:
** init_fight_scene.c
*/

#include "fight_scene.h"

scene_t *init_fight_scene(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->nb_button = 3;
    scene->button = malloc(sizeof(button_t *) * (scene->nb_button));
    scene->nb_object = 2;
    scene->object = malloc(sizeof(object_t *) * (scene->nb_object));
    if (scene->button == NULL || scene->object == NULL)
        return (NULL);
    if (init_fight_scene_buttons(scene) == ERROR)
        return (NULL);
    if (init_fight_scene_objects(scene) == ERROR)
        return (NULL);
    return (scene);
}

int init_fight_scene_buttons(scene_t *scene)
{
    scene->button[0] = create_button(ATTACK_BUTTON, (sfVector2f){300, 134},
                                     (sfVector2f){100, 890});
    scene->button[1] = create_button(MAGIC_BUTTON, (sfVector2f){300, 134},
                                     (sfVector2f){450, 890});
    scene->button[2] = create_button(ESCAPE_BUTTON, (sfVector2f){300, 134},
                                     (sfVector2f){800, 890});
    /* scene->button[0]->callback = &weapon_attack; */
    /* scene->button[1]->callback = &magic_attack; */
    /* scene->button[2]->callback = &escape; */
    for (int i = 0; i < scene->nb_button; i++) {
        if (scene->button[i] == NULL)
            return (ERROR);
    }
    return (0);
}

int init_fight_scene_objects(scene_t *scene)
{
    scene->object[0] = create_object(BG_FIGHT, (sfVector2f){0, 0});
    scene->object[1] = create_object(ACTIONBAR_FIGHT, (sfVector2f){0, 830});
    /* scene->object[2] = create_object( */
    for (int i = 0; i < scene->nb_object; i++) {
        if (scene->object[i] == NULL)
            return (ERROR);
    }
    return (0);
}
