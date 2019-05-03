/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init_fight_scene
*/

#include "my_rpg.h"

scenes_t *init_fight_scene(scenes_t *scenes)
{
    scenes->scene = FIGHT;
    scenes->objs = init_fight_scene_objs();
    scenes->buttons = init_fight_scene_buttons();
    scenes->texts = NULL;
    scenes->musics = NULL;
    if (scenes->objs == NULL || scenes->buttons == NULL)
        return (NULL);
    return (scenes);
}
