/*
** EPITECH PROJECT, 2019
** scene
** File description:
** header
*/

#ifndef SCENE_H
#define SCENE_H

#include "my_rpg.h"

enum scene_e {
    INTRO,
    MENU,
    FIRST_SCENE,
    PLAYER_HOUSE,
    FIGHT,
    ZORO_HOUSE,
    SETTINGS
};

typedef struct scenes_s {
    enum scene_e scene;
    struct scene_object_s *objs;
    struct buttons_s *buttons;
    struct texts_s *texts;
    struct musics_s *musics;
    struct stats_s *stats;
    struct scenes_s *next;
    struct scenes_s *prev;
} scenes_t;

#endif
