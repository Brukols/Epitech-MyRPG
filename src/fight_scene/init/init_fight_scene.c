/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init_fight_scene
*/

#include "my_rpg.h"

scenes_t *init_fight_scene(scenes_t *scene)
{
    scene->scene = FIGHT;
    scene->objs = init_fight_scene_objs(scene);
    scene->buttons = init_fight_scene_buttons();
    scene->texts = init_fight_text();
    scene->musics = NULL;
    if (scene->objs == NULL || scene->buttons == NULL)
        return (NULL);
    return (scene);
}
