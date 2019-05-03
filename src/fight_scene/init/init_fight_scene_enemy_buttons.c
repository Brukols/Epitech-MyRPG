/*
** EPITECH PROJECT, 2019
** init_fight_scene_enemy_button.c
** File description:
** init_fight_scene_enemy_button.c
*/

#include "my_rpg.h"

buttons_t *enemy_button_one(buttons_t *button)
{
    sfIntRect rect = {.left=0, .top=0, .width=108, .height=107};

    button->type = ENEMY;
    button->pos = init_vec2f(1200.0, 910.0);
    button->size = init_vec2f(108.0, 107.0);
    button->rect = rect;
    button->clock = NULL;
    button->hitbox_pos = button->pos;
    button->display = false;
    button->texture = sfTexture_createFromFile(ENEMY_BUTTON_ONE, NULL);
    button->sprite = sfSprite_create();
    if (button->texture == NULL || button->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTextureRect(button->sprite, button->rect);
    return (button);
}

buttons_t *enemy_button_two(buttons_t *button)
{
    sfIntRect rect = {.left=0, .top=0, .width=108, .height=107};

    button->type = ENEMY;
    button->pos = init_vec2f(1358.0, 910.0);
    button->size = init_vec2f(108.0, 107.0);
    button->rect = rect;
    button->clock = NULL;
    button->hitbox_pos = button->pos;
    button->display = false;
    button->texture = sfTexture_createFromFile(ENEMY_BUTTON_TWO, NULL);
    button->sprite = sfSprite_create();
    if (button->texture == NULL || button->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTextureRect(button->sprite, button->rect);
    return (button);
}

buttons_t *enemy_button_three(buttons_t *button)
{
    sfIntRect rect = {.left=0, .top=0, .width=108, .height=107};

    button->type = ENEMY;
    button->pos = init_vec2f(1516.0, 910.0);
    button->size = init_vec2f(108.0, 107.0);
    button->rect = rect;
    button->clock = NULL;
    button->hitbox_pos = button->pos;
    button->display = false;
    button->texture = sfTexture_createFromFile(ENEMY_BUTTON_THREE, NULL);
    button->sprite = sfSprite_create();
    if (button->texture == NULL || button->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTextureRect(button->sprite, button->rect);
    return (button);
}
