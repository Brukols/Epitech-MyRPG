/*
** EPITECH PROJECT, 2019
** init_player_house
** File description:
** my_rpg
*/

#include "my_rpg.h"

game_object_t *init_table(game_object_t *go, int x, int y)
{
    if (!(go->texture = sfTexture_createFromFile(\
        "ressources/sprites/Houses/interior tileset.png", NULL)))
        return (NULL);
    if (!(go->sprite = sfSprite_create()))
        return (NULL);
    go->pos = init_vec2f(x * 4.3, y * 4.3);
    go->comparison = y * 4.3;
    go->display = true;
    go->rect = init_intrect(806, 196, 54, 55);
    go->hitbox_pos = init_vec2f(x * 4.3, y * 4.3);
    go->hitbox_size = init_vec2f(24 * 4.3, 31 * 4.3);
    go->scale = init_vec2f(4.3, 4.3);
    go->type = BED_HOUSE;
    return (go);
}

game_object_t *init_zoro_house_objects(game_object_t *go, char *str)
{
    int i = 0;
    char *tmp = next_data(str, &i);
    char *x = next_data(str, &i);
    char *y = next_data(str, &i);
    char *name[3] = {"table", "bed"};
    game_object_t *(*init_every_object[2])() = {init_table, init_bed};

    if (!tmp || !x || !y)
        return (NULL);
    for (int i = 0; i < 2; i++) {
        if (!my_strcmp(tmp, name[i]))
            return (init_every_object[i](go, my_getnbr(x), my_getnbr(y)));
    }
    return (NULL);
}

game_object_t *init_object_zoro_house(void)
{
    char **house = init_map("maps/zoro_house");
    game_object_t *house_objects = malloc(sizeof(game_object_t));

    if (!house || !house_objects)
        return (NULL);
    house_objects->prev = NULL;
    for (int i = 0; house[i]; i++) {
        if (!(house_objects = init_zoro_house_objects(house_objects, house[i])))
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
