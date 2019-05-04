/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** house 1
*/

#include "my_rpg.h"

background_t *init_background_house_1(void)
{
    background_t *bg = malloc(sizeof(background_t));

    if (!bg)
        return (NULL);
    if (!(bg->texture = sfTexture_createFromFile(\
        "ressources/sprites/Houses/without.png", NULL)))
        return (NULL);
    if (!(bg->sprite = sfSprite_create()))
        return (NULL);
    bg->pos = init_vec2f(350, 0);
    bg->scale = init_vec2f(1.66, 1.66);
    bg->move_x = 0;
    bg->move_y = 0;
    return (bg);
}

scenes_t *init_player_house(scenes_t *scene)
{
    scene->scene = PLAYER_HOUSE;
    if (!(scene->objs = init_scene_object_player_house()))
        return (NULL);
    if (!(scene->buttons = init_buttons_house_player()))
        return (NULL);
    if (!(scene->texts = init_texts_player_house()))
        return (NULL);
    if (!(scene->musics = init_musics_player_house()))
        return (NULL);
    return (scene);
}
