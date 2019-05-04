/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** house 1
*/

#include "my_rpg.h"

background_t *init_background_house_zoro(void)
{
    background_t *bg = malloc(sizeof(background_t));

    if (!bg)
        return (NULL);
    if (!(bg->texture = sfTexture_createFromFile(\
        "ressources/sprites/Houses/zoro_house.png", NULL)))
        return (NULL);
    if (!(bg->sprite = sfSprite_create()))
        return (NULL);
    bg->pos = init_vec2f(350, 0);
    bg->scale = init_vec2f(1.63, 1.63);
    bg->move_x = 0;
    bg->move_y = 0;
    return (bg);
}

scene_object_t *init_scene_object_zoro_house(void)
{
    scene_object_t *so = malloc(sizeof(scene_object_t));

    if (!so)
        return (NULL);
    if (!(so->background = init_background_house_zoro()))
        return (NULL);
    if (!(so->player = init_player()))
        return (NULL);
    if (!(so->game_object = init_game_object_scene("maps/zoro_house")))
        return (NULL);
    if (!(so = put_chara_in_game_object(so, 950, 930)))
        return (NULL);
    so->particle = NULL;
    so->pnj = NULL;
    return (so);
}

scenes_t *init_zoro_house(scenes_t *scene)
{
    scene->scene = ZORO_HOUSE;
    if (!(scene->objs = init_scene_object_zoro_house()))
        return (NULL);
    scene->musics = NULL;
    return (scene);
}
