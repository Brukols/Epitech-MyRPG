/*
** EPITECH PROJECT, 2019
** init_fight_scene_enemies.c
** File description:
** my_rpg
*/

#include "my_rpg.h"


player_t *init_fight_scene_enemies(int index)
{
    player_t *enemy = malloc(sizeof(player_t));

    if (enemy == NULL)
        return (NULL);
    enemy->prev = NULL;
    enemy = init_enemies_loop(enemy, index);
    if (enemy == NULL)
        return (NULL);
    enemy->next = NULL;
    for (; enemy->prev; enemy = enemy->prev);
    return (enemy);
}

player_t *init_enemies_loop(player_t *enemy)
{
    player_t *(*init_enemies[3])() = {init_enemy_one, init_enemy_two, \
        init_enemy_three};

    for (int i = 0; i < 3; i++) {
        enemy = init_enemies[i](enemy, i);
        if (enemy == NULL) {
            free(enemy);
            return (NULL);
        }
        if (i == 2)
            break;
        enemy->next = malloc(sizeof(player_t));
        if (enemy->next == NULL) {
            free(enemy);
            return (NULL);
        }
        enemy->next->prev = enemy;
        enemy = enemy->next;
    }
    return (enemy);
}

player_t *init_enemy_one(player_t *enemy, int index)
{
    if (index == 0) {
        enemy->obj = init_enemy_obj(index);
    }
}

game_object_t *init_enemy_obj(int index, char *filepath)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    if (obj == NULL)
        return (NULL);
    obj->pos = get_enemy_pos(index);
    obj->rect = init_intrect(0, 0, 100, 100);
    obj->texture = sfTexture_createFromFile(filepath, NULL);
    obj->sprite = sfSprite_create();
    if (obj->texture == NULL || obj->sprite == NULL) {
        free(obj);
        return (NULL);
    }
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->clock = NULL;
    return (obj);
}

sfVector2f *get_pos(int index)
{
    sfVector2f *vec;

    if (index == 0) {
        vec.x = 1700;
        vec.y = 500;
    } else if (index == 1) {
        vec.x = 1800;
        vec.y = 800;
    } else {
        vec.x = 1800;
        vec.y = 200;
    }
    return (vec);
}
