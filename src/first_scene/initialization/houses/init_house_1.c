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

game_object_t *init_house_objects(game_object_t *go, char *str)
{
    int i = 0;
    char *tmp = next_data(str, &i);
    char *x = next_data(str, &i);
    char *y = next_data(str, &i);
    char *name[3] = {"plant", "bed"};

    game_object_t *(*init_every_object[3])() = {init_plant, init_bed};

    if (!tmp || !x || !y)
        return (NULL);
    for (int i = 0; i < 2; i++) {
        if (!my_strcmp(tmp, name[i]))
            return (init_every_object[i](go, my_getnbr(x), my_getnbr(y)));
    }
    return (NULL);
}

game_object_t *init_house_1(void)
{
    char **house = init_map("maps/house_1");
    game_object_t *house_objects = malloc(sizeof(game_object_t));

    if (!house || !house_objects)
        return (NULL);
    house_objects->prev = NULL;
    for (int i = 0; house[i]; i++) {
        if (!(house_objects = init_house_objects(house_objects, house[i])))
            return (NULL);
        if (!house[i + 1])
            break;
        if (!(house_objects->next = malloc(sizeof(game_object_t))))
            return (NULL);
        house_objects->next->prev = house_objects;
        house_objects = house_objects->next;
    }
    house_objects->next = NULL;
    for (; house_objects->prev; house_objects = house_objects->prev);
    return (house_objects);
}

scenes_t *init_house_1_scene(scenes_t *scene)
{
    scene->scene = HOUSE_1;
    if ((scene->objs = malloc(sizeof(scene_object_t))) == NULL)
        return NULL;
    if ((scene->objs->player = init_player()) == NULL)
        return NULL;
    if ((scene->objs->game_object = init_house_1()) == NULL)
        return NULL;
    if ((scene->objs->background = init_background_house_1()) == NULL)
        return NULL;
    if ((scene->objs = put_chara_in_game_object(scene->objs, 950, 940)) == NULL)
      return NULL;
    scene->objs->pnj = NULL;
    return scene;
}
