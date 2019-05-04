/*
** EPITECH PROJECT, 2019
** init_enemies.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

enemy_t *init_enemies(void)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    enemy_t *(*init_enemy[4])() = {\
        init_enemy_one, init_enemy_two, init_enemy_three, init_enemy_four};

    if (enemy == NULL)
        return (NULL);
    enemy->prev = NULL;
    for (int i = 0; i < 4; i++) {
        enemy = init_enemy[i](enemy);
        if (enemy == NULL)
            return (NULL);
        if (i == 3)
            break;
        enemy->next = malloc(sizeof(enemy_t));
        if (enemy->next == NULL)
            return (NULL);
        enemy->next->prev = enemy;
        enemy = enemy->next;
    }
    enemy->next = NULL;
    for (; enemy->prev; enemy = enemy->prev);
    return (enemy);
}

enemy_t *init_enemy_one(enemy_t *enemy)
{
    enemy->hp = 100;
    enemy->attack = 10;
    enemy->attacking = false;
    enemy->obj = malloc(sizeof(game_object_t));
    if (enemy->obj == NULL)
        return (NULL);
    enemy->obj->clock = NULL;
    enemy->obj->pos = init_vec2f(1300, 430);
    enemy->obj->rect = init_intrect(0, 0, 34, 35);
    enemy->obj->scale = init_vec2f(6, 6);
    enemy->obj->texture = sfTexture_createFromFile(ENEMY_SHEET, NULL);
    enemy->obj->sprite = sfSprite_create();
    if (enemy->obj->texture == NULL || enemy->obj->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(enemy->obj->sprite, enemy->obj->texture, sfFalse);
    sfSprite_setTextureRect(enemy->obj->sprite, enemy->obj->rect);
    sfSprite_setPosition(enemy->obj->sprite, enemy->obj->pos);
    sfSprite_setScale(enemy->obj->sprite, enemy->obj->scale);
    return (enemy);
}

enemy_t *init_enemy_two(enemy_t *enemy)
{
    enemy->hp = 250;
    enemy->attack = 20;
    enemy->attacking = false;
    enemy->obj = malloc(sizeof(game_object_t));
    if (enemy->obj == NULL)
        return (NULL);
    enemy->obj->clock = NULL;
    enemy->obj->pos = init_vec2f(1300, 430);
    enemy->obj->rect = init_intrect(0, 35, 34, 35);
    enemy->obj->scale = init_vec2f(7, 7);
    enemy->obj->texture = sfTexture_createFromFile(ENEMY_SHEET, NULL);
    enemy->obj->sprite = sfSprite_create();
    if (enemy->obj->texture == NULL || enemy->obj->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(enemy->obj->sprite, enemy->obj->texture, sfFalse);
    sfSprite_setTextureRect(enemy->obj->sprite, enemy->obj->rect);
    sfSprite_setPosition(enemy->obj->sprite, enemy->obj->pos);
    sfSprite_setScale(enemy->obj->sprite, enemy->obj->scale);
    return (enemy);
}

enemy_t *init_enemy_three(enemy_t *enemy)
{
    enemy->hp = 250;
    enemy->attack = 20;
    enemy->attacking = false;
    enemy->obj = malloc(sizeof(game_object_t));
    if (enemy->obj == NULL)
        return (NULL);
    enemy->obj->clock = NULL;
    enemy->obj->pos = init_vec2f(1300, 400);
    enemy->obj->rect = init_intrect(0, 115, 24, 50);
    enemy->obj->scale = init_vec2f(8, 8);
    enemy->obj->texture = sfTexture_createFromFile(ENEMY_SHEET, NULL);
    enemy->obj->sprite = sfSprite_create();
    if (enemy->obj->texture == NULL || enemy->obj->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(enemy->obj->sprite, enemy->obj->texture, sfFalse);
    sfSprite_setTextureRect(enemy->obj->sprite, enemy->obj->rect);
    sfSprite_setPosition(enemy->obj->sprite, enemy->obj->pos);
    sfSprite_setScale(enemy->obj->sprite, enemy->obj->scale);
    return (enemy);
}

enemy_t *init_enemy_four(enemy_t *enemy)
{
    enemy->hp = 500;
    enemy->attack = 50;
    enemy->attacking = false;
    enemy->obj = malloc(sizeof(game_object_t));
    if (enemy->obj == NULL)
        return (NULL);
    enemy->obj->clock = NULL;
    enemy->obj->pos = init_vec2f(1200, 300);
    enemy->obj->rect = init_intrect(0, 70, 25, 35);
    enemy->obj->scale = init_vec2f(10, 10);
    enemy->obj->texture = sfTexture_createFromFile(ENEMY_SHEET, NULL);
    enemy->obj->sprite = sfSprite_create();
    if (enemy->obj->texture == NULL || enemy->obj->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(enemy->obj->sprite, enemy->obj->texture, sfFalse);
    sfSprite_setTextureRect(enemy->obj->sprite, enemy->obj->rect);
    sfSprite_setPosition(enemy->obj->sprite, enemy->obj->pos);
    sfSprite_setScale(enemy->obj->sprite, enemy->obj->scale);
    return (enemy);
}
