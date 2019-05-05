/*
** EPITECH PROJECT, 2019
** init_first_scnee
** File description:
** myrpg
*/

#include "my_rpg.h"

scenes_t *init_first_scene(scenes_t *scenes)
{
    scenes->scene = FIRST_SCENE;
    if (!(scenes->objs = init_scene_object_fs_scene()))
        return (NULL);
    if (!(scenes->texts = init_texts_fs_scene()))
        return (NULL);
    if (!(scenes->buttons = init_buttons_fs_scene()))
        return (NULL);
    if (!(scenes->musics = init_musics_fs_scene()))
        return (NULL);
    if (!(scenes->stats = init_stats()))
        return (NULL);
    return (scenes);
}