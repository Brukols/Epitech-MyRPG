/*
** EPITECH PROJECT, 2019
** init_first_scnee
** File description:
** myrpg
*/

#include "my_rpg.h"

scenes_t *init_first_scene(scenes_t *scenes)
{
    //if (!(scenes->next = malloc(sizeof(scenes_t))))
    //    return (NULL);
    //if (!(scenes = malloc(sizeof(scenes_t))))
    //    return (NULL);
    //scenes = scenes->next;
    scenes->scene = FIRST_SCENE;
    if (!(scenes->objs = init_scene_object_fs_scene()))
        return (NULL);
    return (scenes);
}